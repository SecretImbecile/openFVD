#version 130

in vec3 aPosition;
out vec4 bPosition;

in vec3 aNormal;
out vec3 bNormal;

in vec2 aUv;
out vec2 bUv;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 anchorBase;
uniform vec3 eyePos;

out vec4 screenCoord;
out vec3 baryCoord;

void main(void) {
  // generate barycentric coordinates based on vertex ID
  if (gl_VertexID % 3 == 0) {
    baryCoord = vec3(1.f, 0.f, 0.f);
  } else if (gl_VertexID % 3 == 1) {
    baryCoord = vec3(0.f, 1.f, 0.f);
  } else {
    baryCoord = vec3(0.f, 0.f, 1.f);
  }

  bPosition = anchorBase * vec4(aPosition, 1.f);
  gl_Position = projectionMatrix * modelMatrix * bPosition;
  bPosition -= vec4(eyePos, 0.f);
  bNormal = vec3(anchorBase * vec4(aNormal, 0.f));
  if (length(bNormal) < 0.5f)
    bNormal = vec3(0.f, 1.f, 0.f);
  bUv = aUv;
  screenCoord = gl_Position;
}
