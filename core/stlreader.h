#ifndef STLREADER_H
#define STLREADER_H

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QVector3D>
#include <QVector>

struct Triangle {
  QVector3D normal;
  QVector3D vertices[3];
};

bool readStl(const QString &fileName, QVector<Triangle> &triangles);

QVector<QVector3D> extractVertices(const QVector<Triangle> &triangles);
QVector<QVector3D> extractVerticesNormal(const QVector<Triangle> &triangles);

#endif // STLREADER_H
