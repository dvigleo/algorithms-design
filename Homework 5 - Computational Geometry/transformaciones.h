#ifndef TRANSFORMACIONES_H
#define TRANSFORMACIONES_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

class Transformaciones
{
public:
    Transformaciones();
    void dibujar(bool & dibuja, QVector<QTransform> & vecTrans, double & xCentro, double & yCentro);
    void trasladar(QString & xStr, QString & yStr, QVector<QTransform> & vecTrans);
    void rotar(QString & gradosStr, QVector<QTransform> & vecTrans);
    void zoomOut(QVector<QTransform> & vecTrans);
    void zoomIn(QVector<QTransform> & vecTrans);
    void reflexHorizontal(QVector<QTransform> & vecTrans);
    void reflexVertical(QVector<QTransform> & vecTrans);
};

#endif
