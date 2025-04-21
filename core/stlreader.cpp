#include "stlreader.h"

bool readStl(const QString &fileName, QVector<Triangle> &triangles) {
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Cannot open file for reading:" << file.errorString();
    return false;
  }

  QTextStream in(&file);
  QString line;

  while (!in.atEnd()) {
    line = in.readLine().trimmed();
    if (line.startsWith("facet normal")) {
      Triangle triangle;
      QStringList parts = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
      if (parts.size() != 5) {
        qWarning() << "Invalid facet normal line: " << line;
        continue;
      }
      triangle.normal =
          QVector3D(parts[2].toFloat(), parts[3].toFloat(), parts[4].toFloat());

      in.readLine(); // skip "outer loop"
      for (int i = 0; i < 3; ++i) {
        line = in.readLine().trimmed();
        parts = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        if (parts.size() != 4) {
          qWarning() << "Invalid vertex line: " << line;
          continue;
        }
        triangle.vertices[i] = QVector3D(parts[1].toFloat(), parts[2].toFloat(),
                                         parts[3].toFloat());
      }
      in.readLine(); // skip "endloop"
      in.readLine(); // skip "endfacet"
      // if(triangles.size() <= 10) {
      triangles.append(triangle);
      //}
    }
  }

  file.close();
  qDebug() << "Loaded" << triangles.size() << "triangles";
  return true;
}

QVector<QVector3D> extractVertices(const QVector<Triangle> &triangles) {
  QVector<QVector3D> vertices;
  for (const Triangle &triangle : triangles) {
    for (const QVector3D &vertex : triangle.vertices) {
      vertices.append(vertex);
      // qDebug("%f %f %f", vertex[0], vertex[1], vertex[2]);
    }
  }
  return vertices;
}

QVector<QVector3D> extractVerticesNormal(const QVector<Triangle> &triangles) {
  QVector<QVector3D> vertices;
  for (const Triangle &triangle : triangles) {
    QVector3D normal = triangle.normal;
    for (const QVector3D &vertex : triangle.vertices) {
      vertices.append(vertex);
      vertices.append(normal);
      // qDebug("%f %f %f", vertex[0], vertex[1], vertex[2]);
    }
  }
  return vertices;
}
