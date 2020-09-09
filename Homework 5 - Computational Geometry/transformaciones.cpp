#include "transformaciones.h"

Transformaciones::Transformaciones()
{

}

void Transformaciones::dibujar(bool & dibuja, QVector<QTransform> & vecTrans, double & xCentro, double & yCentro)
{
    dibuja=!dibuja;
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
}

void Transformaciones::trasladar(QString & xStr, QString & yStr, QVector<QTransform> & vecTrans)
{
    if(!xStr.isEmpty() && !yStr.isEmpty()) {
        double x = xStr.toDouble();
        double y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        vecTrans.push_back(translate);
    }
}

void Transformaciones::rotar(QString & gradosStr, QVector<QTransform> & vecTrans)
{
    if(!gradosStr.isEmpty()) {
        double grados = gradosStr.toDouble();
        QTransform rotate;
        rotate.rotate(grados);
        vecTrans.push_back(rotate);
    }
}

void Transformaciones::zoomOut(QVector<QTransform> & vecTrans)
{
    QTransform zoomOut;
    zoomOut.scale(0.25,0.25);
    vecTrans.push_back(zoomOut);
}

void Transformaciones::zoomIn(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    vecTrans.push_back(zoomIn);
}

void Transformaciones::reflexHorizontal(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    vecTrans.push_back(zoomIn);
}

void Transformaciones::reflexVertical(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    vecTrans.push_back(zoomIn);
}
