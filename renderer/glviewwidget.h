#ifndef GLVIEWWIDGET_H
#define GLVIEWWIDGET_H

/*
#    FVD++, an advanced coaster design tool for NoLimits
#    Copyright (C) 2012-2015, Stephan "Lenny" Alt <alt.stephan@web.de>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program. If not, see <http://www.gnu.org/licenses/>.

#*/
#include <QtCore>

#include "GL/glew.h"
//#include "GL/glu.h"

#include "stlreader.h"
#include "track.h"
#include <QElapsedTimer>
#include <QGLBuffer>
#include <QGLShaderProgram>
#include <QGLWidget>
#include <QtGlobal>
#include <glm/glm.hpp>

#ifdef USE_OVR
#include "OVR.h"
#include "OVRVersion.h"
#endif

class myShader;
class myTexture;
class myFramebuffer;

typedef struct mesh_s {
  GLuint object;
  GLuint buffer;
} mesh_t;

class MainWindow;

class glViewWidget : public QGLWidget {
  Q_OBJECT
public:
  explicit glViewWidget(QWidget *parent = 0);
  ~glViewWidget();
  void paintGL();
  QString getGLVersionString();
  bool loadGroundTexture(QString fileName);
  void setGroundTextureSize(float _grdTexSize);

  void loadStlMesh(QString fileName, int meshIndex);
  bool initStlMesh(int meshIndex);
  void clearStlMesh();

  void setStlColor(QColor _color, int meshIndex);

  void setBackgroundColor(QColor _background);

  int curTrackShader;
  bool povMode;
  mnode *povNode;
  bool paintMode;
  bool legacyMode;
  bool riftMode;
  bool moveMode;
  int povPos;
  glm::vec4 cameraMov;
  double mSec;
  bool hasChanged;
  glm::vec3 cameraPos;

  float grdTexSize;

protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void wheelEvent(QWheelEvent *event);

signals:

private:
  void initFloorMesh();
  void initTextures();
  void initShaders();
  void moveCamera();
  void buildMatrices(float offset);
  void updateLoD();

  void drawFloor();
  void drawSky();

  void drawStl(myShader *stlShader, int meshIndex);

  void drawTrack(trackHandler *_track, bool toNormalMap = false);
  void drawSimpleSM(trackHandler *_track);
  void drawShadowVolumes();
  void drawOcclusion();
  void drawDebug();
  void drawOculus();

  void legacyDrawFloor();
  void legacyDrawTrack(trackHandler *_track);

  QPoint mousePos;

  glm::vec3 freeFlyPos;
  glm::vec3 freeFlyDir;
  glm::vec3 freeFlySide;
  glm::vec3 cameraDir;
  float fIPD;
  float fEyeToScreen;
  glm::vec4 HmdWarp;
  float lensSep;
  float hScreenSize;
  float vScreenSize;
#ifdef USE_OVR
  OVR::SensorDevice *sensor;
  OVR::SensorFusion *sensFusion;
#endif
  glm::vec3 headPos;

  int cameraJump;
  float cameraBoost;

  QColor clearColor;
  QVector<QColor> stlColor;

  glm::mat4x4 ProjectionModelMatrix;
  glm::mat4x4 ModelMatrix;
  glm::mat4x4 ProjectionMatrix;

  myTexture *floorTexture;
  myTexture *rasterTexture;
  myTexture *metalTexture;
  myTexture *skyTexture;

  myFramebuffer *simpleShadowFb;
  myFramebuffer *shadowVolumeFb;
  myFramebuffer *normalMapFb;
  myFramebuffer *occlusionFb;

  myFramebuffer *preDistortionFb;

  GLuint drawBorder;

  QVector<mesh_t> stlMesh;

  mesh_t floorMesh;
  mesh_t skyMesh;

  QVector<int> stlCountVertices;
  QVector<int> stlCountTriangles;
  QVector<bool> stlLoaded;

  QVector<QVector<Triangle>> stlTriangles;
  QVector<QVector<QVector3D>> stlVertices;

  QVector<myShader *> stlShader;

  myShader *floorShader;
  myShader *skyShader;
  myShader *trackShader;
  myShader *simpleSMShader;
  myShader *shadowVolumeShader;
  myShader *normalMapShader;
  myShader *occlusionShader;
  myShader *oculusShader;
  myShader *debugShader;

  int viewPortWidth, viewPortHeight;

  QElapsedTimer frameTimer;
  float renderTime;
  float lens;
  float fov;

  int shadowMode;
  float floorOpacity;
  int initialized;

  glm::vec3 lightDir;
};

#endif // GLVIEWWIDGET_H
