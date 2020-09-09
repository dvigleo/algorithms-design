#ifndef CUBO_H
#define CUBO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class cubo;
}

class cubo : public QDialog
{
    Q_OBJECT

public:
    explicit cubo(QWidget *parent = 0);
    ~cubo();

private:
    Ui::cubo *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;

protected:
     void paintEvent(QPaintEvent *e);
     void drawCubo(QPainter &painter);

private slots:
     void on_dibujar_clicked();
     void on_trasladar_clicked();
     void on_rotar_clicked();
     void on_zoom_in_clicked();
     void on_zoom_out_clicked();
     void on_horizontal_clicked();
     void on_vertical_clicked();

};

#endif // CUBO_H
