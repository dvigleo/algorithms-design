#ifndef PRISMAREC_H
#define PRISMAREC_H

#include "transformaciones.h"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class prismarec;
}

class prismarec : public QDialog
{
    Q_OBJECT

public:
    explicit prismarec(QWidget *parent = 0);
    ~prismarec();

protected:
     void paintEvent(QPaintEvent *e);
     void drawPrismarec(QPainter &painter);

private slots:
     void on_dibujar_clicked();
     void on_trasladar_clicked();
     void on_rotar_clicked();
     void on_zoom_in_clicked();
     void on_zoom_out_clicked();
     void on_horizontal_clicked();
     void on_vertical_clicked();

private:
    Ui::prismarec *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
};

#endif // PRISMAREC_H
