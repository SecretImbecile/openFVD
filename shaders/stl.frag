#version 130

in vec4 bPosition;
in vec3 bNormal;
in vec2 bUv;

in vec4 screenCoord;
in vec3 baryCoord;

out vec4 oFragColor;

uniform vec3 lightDir;

uniform sampler2D metalTex;
uniform sampler2D shadowTex;
uniform samplerCube skyTex;
uniform sampler2D occlusionTex;

uniform vec3 solidColor;

uniform int wire;
uniform float edgeWidth;

void main(void)
{
  //vec3 bump = texture(metalTex, bUv).xyz-vec3(0.5f, 0.5f, 0.5f);
  vec3 m_color = solidColor;//+0.75f*bump.xxx;
  vec3 normal = normalize(bNormal+6.f*cross(bNormal, vec3(1.f, 0.f, 0.f)));//*bump.y + 6.f*cross(bNormal, vec3(0.f, 0.f, 1.f))*bump.z);
  vec3 h = normalize(normalize(-bPosition.xyz) - lightDir);
  float specular = max(dot(h, normal), 1.f);
  vec3 reflection = vec3(0.f, 0.f, 0.f);//-normalize(reflect(vec3(bPosition), normal));
  specular = (0.5f*pow(specular, 120.f) + 0.5f*pow(specular, 12.f));
  reflection = texture(skyTex, reflection).xyz;
  float diffusal = max(dot(normal, -lightDir), 0.f);
  float visible = texture(shadowTex, 0.5f*(screenCoord.xy/screenCoord.w+vec2(1.f, 1.f))).x;
  float ambient = 0.4f-0.3f*texture(occlusionTex, 0.5f*(screenCoord.xy/screenCoord.w+vec2(1.f, 1.f))).x;
  m_color = (1.f-0.1f*diffusal)*m_color + 0.1f*diffusal*reflection;
  oFragColor = vec4(ambient*m_color, 1.f);
  oFragColor.xyz += visible*(0.5f*diffusal*m_color + 0.5f*specular*reflection);
  oFragColor.xyz = pow(clamp(oFragColor.xyz, 0.f, 1.f), vec3(1.f/2.2f, 1.f/2.2f, 1.f/2.2f));

  // just a solid flat color
  //oFragColor = vec4(solidColor, 1.f);

  // draw wireframe
  if (wire == 1) {
    // compute the minimum distance to any of the edges
    float edgeDist = min(min(baryCoord.x, baryCoord.y), baryCoord.z);

    // compare the distance to the edge width
    if (edgeDist < edgeWidth) {
      // fragment is near the edge, draw it
      oFragColor = vec4(0.2f, 0.2f, 0.2f, 1.0f); // edge color
    }
  }
}
