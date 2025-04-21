#-------------------------------------------------
#
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
#
#-------------------------------------------------


# DEPENDENCIES
#
# QT (tested with 5.14.2)
# glew
# glm (tested with 0.9.5.1-1)

CONFIG += qt
QT     += core gui widgets printsupport opengl

QMAKE_CXXFLAGS += -Wno-expansion-to-defined

#CONFIG += exceptions \
#          rtti

#CONFIG += debug

TARGET = FVD_0.8a
TEMPLATE = app

SOURCES += main.cpp\
    core/stlreader.cpp \
    core/common.cpp \
    core/undohandler.cpp \
    core/undoaction.cpp \
    core/trackhandler.cpp \
    core/track.cpp \
    core/subfunction.cpp \
    core/smoothhandler.cpp \
    core/sectionhandler.cpp \
    core/section.cpp \
    core/secstraight.cpp \
    core/secgeometric.cpp \
    core/secforced.cpp \
    core/seccurved.cpp \
    core/secbezier.cpp \
    core/saver.cpp \
    core/nolimitsimporter.cpp \
    core/mnode.cpp \
    core/function.cpp \
    core/exportfuncs.cpp \
    renderer/trackmesh.cpp \
    renderer/mytexture.cpp \
    renderer/myshader.cpp \
    renderer/myframebuffer.cpp \
    renderer/glviewwidget.cpp \
    ui/transitionwidget.cpp \
    ui/trackwidget.cpp \
    ui/trackproperties.cpp \
    ui/smoothui.cpp \
    ui/qcustomplot.cpp \
    ui/projectwidget.cpp \
    ui/optionsmenu.cpp \
    ui/mytreewidget.cpp \
    ui/myqdoublespinbox.cpp \
    ui/mainwindow.cpp \
    ui/importui.cpp \
    ui/graphwidget.cpp \
    ui/graphhandler.cpp \
    ui/exportui.cpp \
    ui/draglabel.cpp \
    ui/conversionpanel.cpp \
    core/secnlcsv.cpp

HEADERS += core/undohandler.h \
    core/stlreader.h \
    core/common.h \
    core/undoaction.h \
    core/trackhandler.h \
    core/track.h \
    core/subfunction.h \
    core/smoothhandler.h \
    core/sectionhandler.h \
    core/section.h \
    core/secstraight.h \
    core/secgeometric.h \
    core/secforced.h \
    core/seccurved.h \
    core/secbezier.h \
    core/saver.h \
    core/nolimitsimporter.h \
    core/mnode.h \
    core/function.h \
    core/exportfuncs.h \
    renderer/trackmesh.h \
    renderer/mytexture.h \
    renderer/myshader.h \
    renderer/myframebuffer.h \
    renderer/glviewwidget.h \
    ui/transitionwidget.h \
    ui/trackwidget.h \
    ui/trackproperties.h \
    ui/smoothui.h \
    ui/qcustomplot.h \
    ui/projectwidget.h \
    ui/optionsmenu.h \
    ui/mytreewidget.h \
    ui/myqdoublespinbox.h \
    ui/mainwindow.h \
    ui/importui.h \
    ui/graphwidget.h \
    ui/graphhandler.h \
    ui/exportui.h \
    ui/draglabel.h \
    ui/conversionpanel.h \
    lenassert.h \
    core/secnlcsv.h

FORMS += ui/transitionwidget.ui \
    ui/trackwidget.ui \
    ui/trackproperties.ui \
    ui/smoothui.ui \
    ui/projectwidget.ui \
    ui/optionsmenu.ui \
    ui/mainwindow.ui \
    ui/importui.ui \
    ui/graphwidget.ui \
    ui/exportui.ui \
    ui/conversionpanel.ui

INCLUDEPATH += "./ui/"
INCLUDEPATH += "./renderer/"
INCLUDEPATH += "./core/"

INCLUDEPATH += "path\to\fvd_deps\glew-1.12.0\include"
INCLUDEPATH += "path\to\fvd_deps\glm"

# GL and GLU, OS install
LIBS += -lOpenGL32
LIBS += -lGLU32

LIBS += "path\to\fvd_deps\glew-1.12.0\lib\Release\x64\glew32.lib"

RC_FILE = winicon.rc

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    winicon.rc \
    background.png \
    metal.png \
    shaders/normals.vert \
    shaders/track.vert \
    shaders/track.frag \
    shaders/sky.vert \
    shaders/sky.frag \
    shaders/simpleSM.vert \
    shaders/simpleSM.frag \
    shaders/shadowVolume.vert \
    shaders/shadowVolume.frag \
    shaders/oculus.vert \
    shaders/oculus.frag \
    shaders/occlusion.vert \
    shaders/occlusion.frag \
    shaders/normals.frag \
    shaders/metal.dat \
    shaders/floor.vert \
    shaders/floor.frag \
    shaders/stl.vert \
    shaders/stl.frag \
    shaders/debug.vert \
    shaders/debug.frag \
    metalnormals.png \
    readme.txt \
    sky/negx.jpg \
    sky/negy.jpg \
    sky/negz.jpg \
    sky/posx.jpg \
    sky/posy.jpg \
    sky/posz.jpg
