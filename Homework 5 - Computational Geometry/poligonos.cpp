#include "poligonos.h"
#include "ui_poligonos.h"
#include <QMessageBox>
#include <math.h>

Poligonos::Poligonos(QWidget *parent): QDialog(parent), ui(new Ui::Poligonos) {
    this->setFixedSize(521, 333); //Size of window
    ui->setupUi(this);
    xCentro = 345.0; // values so the first drawn figure is centered
    yCentro = 170.0;
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
}

Poligonos::~Poligonos() {
    delete ui;
}

void dibujarPoligono(int lados, QPainter & painter) {

    double radio = 100;
    double angulo = (double)360.0/(double)lados;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a = 1; a <= lados; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }

}

void Poligonos::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {

        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty()) {
            int lados = ladosStr.toInt();
            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarPoligono(lados, painter);
            }
        }
    }
}

//Buttons...

void Poligonos::on_dibujar_clicked() {
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);
    update();
}

void Poligonos::on_trasladar_clicked() {
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();
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

void Poligonos::on_rotar_clicked() {
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

void Poligonos::on_zoom_out_clicked() {
    trans.zoomOut(vecTrans);
    update();
}

void Poligonos::on_zoom_in_clicked() {
    trans.zoomIn(vecTrans);
    update();
}

void Poligonos::on_horizontal_clicked() {
    trans.reflexHorizontal(vecTrans);
    update();
}

void Poligonos::on_vertical_clicked() {
    trans.reflexVertical(vecTrans);
    update();
}
