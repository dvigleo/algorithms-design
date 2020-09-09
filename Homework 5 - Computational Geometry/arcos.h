#ifndef ARCOS_H
#define ARCOS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class Arcos;
}

class Arcos : public QDialog
{
    Q_OBJECT

public:
    explicit Arcos(QWidget *parent = 0);
    ~Arcos();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_dibujar_clicked();
    void on_trasladar_clicked();
    void on_rotar_clicked();
    void on_zoom_in_clicked();
    void on_zoom_out_clicked();
    void on_horizontal_clicked();
    void on_vertical_clicked();

private:
    Ui::Arcos *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

};

#endif
