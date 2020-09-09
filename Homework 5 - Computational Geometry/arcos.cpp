#include "arcos.h"
#include "ui_arcos.h"
#include <QMessageBox>

#define PI 3.14159265

Arcos::Arcos(QWidget *parent):QDialog(parent), ui(new Ui::Arcos){
    this->setFixedSize(521, 333); //Size of window
    ui->setupUi(this);
    xCentro = 345.0; // values so the first drawn figure is centered
    yCentro = 170.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Arcos::~Arcos() {
    delete ui;
}

void puntosDelCirculo(QPainter & painter) {
  int xc,yc,x,y,p,r;
  xc=300;
  yc=200;
  r=100;
  x = 0;
  y = r;
  p = 1-r;

  while(x <= y)  {
    if(p < 0) {
        x++;
        p += 2*x +1;
    }
    else {
        x++;
        y--;
        p += 2*x - 2*y +1;
    }

    painter.drawPoint(xc+x,yc+y);
    painter.drawPoint(xc+y,yc+x);
    painter.drawPoint(xc+x,yc-y);
    painter.drawPoint(xc+y,yc-x);
  }
}

void dibujarArco(QPainter & painter) {
    int xc,yc,x,y,p,r;

      xc=0;
      yc=0;
      r=100;
      x = 0;
      y = r;
      p = 1-r;

      while(x<=y) {
        if(p<0) {
            x++;
            p += 2*x +1;
        }
        else{
            x++;
            y--;
            p += 2*x - 2*y +1;
        }
        painter.drawPoint(xc+x,yc+y);
        painter.drawPoint(xc+y,yc+x);
        painter.drawPoint(xc+x,yc-y);
        painter.drawPoint(xc+y,yc-x);
      }
    }

void Arcos::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {
        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarArco(painter);;
        }
    }
}

//These are the buttons
void Arcos::on_dibujar_clicked() {
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);
    update();
}

void Arcos::on_trasladar_clicked() {
    QString x = ui->boxXinicio->toPlainText();
    QString y = ui->boxYinicio->toPlainText();
        if(!x.isEmpty() && !y.isEmpty()) {
            trans.trasladar(x, y, vecTrans);
            update();
         } else {
            QMessageBox msgBox;
            msgBox.setText("Please type in the values for x and y");
            msgBox.exec();
         }
}

void Arcos::on_rotar_clicked() {
    QString gradosStr = ui->boxGrados->toPlainText();
    if(!gradosStr.isEmpty()) {
        trans.rotar(gradosStr, vecTrans);
        update();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Please type in the degree for rotation");
        msgBox.exec();
    }
}

void Arcos::on_zoom_in_clicked() {
    trans.zoomIn(vecTrans);
    update();
}

void Arcos::on_zoom_out_clicked() {
    trans.zoomOut(vecTrans);
    update();
}

void Arcos::on_horizontal_clicked() {
    trans.reflexHorizontal(vecTrans);
    update();
}

void Arcos::on_vertical_clicked() {
    trans.reflexVertical(vecTrans);
    update();
}
