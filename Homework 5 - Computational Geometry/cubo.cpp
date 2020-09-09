#include "cubo.h"
#include "ui_cubo.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>

cubo::cubo(QWidget *parent):QDialog(parent), ui(new Ui::cubo) {
    this->setFixedSize(521, 333); //Size of window
    ui->setupUi(this);
    xCentro = 345.0; // values so the first drawn figure is centered
    yCentro = 170.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

cubo::~cubo()
{
    delete ui;
}

void cubo::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (dibuja){
        for(int i=0; i<vecTrans.size(); ++i){
            painter.setTransform(vecTrans[i],true);
            drawCubo(painter);
        }
    }
}

void cubo::drawCubo(QPainter &painter){
        painter.drawLine(-40, 40, 40, 40);
        painter.drawLine(-40, 40, -40, -40);
        painter.drawLine(40, 40, 40, -40);
        painter.drawLine(-40, -40, 40, -40);
        painter.drawLine(0, 0, 80, 0);
        painter.drawLine(0, 0, 0, -80);
        painter.drawLine(80, 0, 80, -80);
        painter.drawLine(0, -80, 80, -80);
        painter.drawLine(-40, 40, 0, 0);
        painter.drawLine(40, 40, 80, 0);
        painter.drawLine(-40, -40, 0, -80);
        painter.drawLine(40, -40, 80, -80);
}


void cubo::on_dibujar_clicked() {
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
    dibuja = !dibuja;
    update();
}

void cubo::on_trasladar_clicked() {
    QString x = ui->boxXinicio->toPlainText();
    QString y = ui->boxYinicio->toPlainText();
     if(!x.isEmpty() && !y.isEmpty()) {
       int xS = x.toInt();
       int yS = y.toInt();
       QTransform t;
       t.translate(xS, yS);
       vecTrans.push_back(t);
     } else {
       QMessageBox msgBox;
       msgBox.setText("Please type in the values for x and y");
       msgBox.exec();
     }
     update();
}

void cubo::on_zoom_out_clicked() {
    QTransform zIn;
    zIn.scale(2,2);
    vecTrans.push_back(zIn);
    update();
}


void cubo::on_zoom_in_clicked() {
    QTransform zOut;
    zOut.scale(0.5,0.5);
    vecTrans.push_back(zOut);
    update();
}

void cubo::on_rotar_clicked() {
    QString r = ui->boxGrados->toPlainText();
      if(!r.isEmpty()) {
        int rS = r.toInt();
        QTransform r;
        r.rotate(rS);
        vecTrans.push_back(r);
      } else {
        QMessageBox msgBox;
        msgBox.setText("Please type in the degree for rotation");
        msgBox.exec();
      }
    update();
}

void cubo::on_vertical_clicked() {
    QTransform rv;
    rv.scale(1,-1);
    vecTrans.push_back(rv);
    update();
}

void cubo::on_horizontal_clicked() {
    QTransform rh;
    rh.scale(-1,1);
    vecTrans.push_back(rh);
    update();
}
