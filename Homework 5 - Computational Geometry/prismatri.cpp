#include "prismatri.h"
#include "ui_prismatri.h"
#include <math.h>
#include <QMessageBox>

PrismaTri::PrismaTri(QWidget *parent) : QDialog(parent), ui(new Ui::PrismaTri) {
    this->setFixedSize(521, 333); //Size of window
    ui->setupUi(this);
    xCentro = 350.0; // values so the first drawn figure is centered
    yCentro = 170.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

PrismaTri::~PrismaTri()
{
    delete ui;
}

void PrismaTri::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (dibuja){
        for(int i=0; i<vecTrans.size(); ++i){
            painter.setTransform(vecTrans[i],true);
            drawPrismaTri(painter);
        }
    }
}
void PrismaTri::drawPrismaTri(QPainter &painter){
        painter.drawLine(0,-100,-50,-140);
        painter.drawLine(0,-100,50,-140);
        painter.drawLine(-50,-140,50,-140);
        painter.drawLine(0,0,-50,-40);
        painter.drawLine(0,0,50,-40);
        painter.drawLine(-50,-40,50,-40);
        painter.drawLine(0,-100,0,0);
        painter.drawLine(-50,-140,-50,-40);
        painter.drawLine(50,-40,50,-140);
}

void PrismaTri::on_dibujar_clicked() {
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
    dibuja = !dibuja;
    update();
}

void PrismaTri::on_trasladar_clicked() {
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

void PrismaTri::on_zoom_in_clicked() {
    QTransform zIn;
    zIn.scale(2,2);
    vecTrans.push_back(zIn);
    update();
}

void PrismaTri::on_zoom_out_clicked() {
    QTransform zOut;
    zOut.scale(0.5,0.5);
    vecTrans.push_back(zOut);
    update();
}

void PrismaTri::on_rotar_clicked() {
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

void PrismaTri::on_vertical_clicked() {
    QTransform rv;
    rv.scale(1,-1);
    vecTrans.push_back(rv);
    update();
}

void PrismaTri::on_horizontal_clicked() {
    QTransform rh;
    rh.scale(-1,1);
    vecTrans.push_back(rh);
    update();
}
