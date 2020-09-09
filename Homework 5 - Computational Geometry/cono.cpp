#include "cono.h"
#include "ui_cono.h"
#include "math.h"

Cono::Cono(QWidget *parent) : QDialog(parent),  ui(new Ui::Cono) {
    this->setFixedSize(521, 333); //Size of window
    ui->setupUi(this);
    xCentro = 345.0; // values so the first drawn figure is centered
    yCentro = 170.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Cono::~Cono()
{
    delete ui;
}


void dibujarElipse(int xc,int yc,int rx,int ry, QPainter & painter)  {

   int x=0;
   int y=ry;
   int p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
   while((2*x*ry*ry)<(2*y*rx*rx))    {
        painter.drawPoint(xc+x,yc-y);
        painter.drawPoint(xc-x,yc+y);
        painter.drawPoint(xc+x,yc+y);
        painter.drawPoint(xc-x,yc-y);

        if(p<0)
        {
     x=x+1;
     p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
     x=x+1;
     y=y-1;
     p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
   }
   p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

         while(y>=0)
   {
       painter.drawPoint(xc+x,yc-y);
       painter.drawPoint(xc-x,yc+y);
       painter.drawPoint(xc+x,yc+y);
       painter.drawPoint(xc-x,yc-y);

        if(p>0)
        {
     y=y-1;
     p=p-(2*rx*rx*y)+(rx*rx);

        }
        else
        {
     y=y-1;
     x=x+1;
     p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
   }
 }


void BresenhamLine (int x0, int y0, int x1, int y1, QPainter & painter) {
   int x, y, dx, dy, xend, p, incE, incNE;
   dx = abs(x1 - x0);
   dy = abs(y1 - y0);
   p = 2 * dy - dx;
   incE = 2 * dy;
   incNE = 2 * (dy - dx);

   if(x0 > x1 ) {
       x = x1;
       y = y1;
       xend = 0;
   }

   while(x <= xend) {
       painter.drawPoint(x, y);
       x += 1;
       if(p < 0){
           p += incE;
       }
       else {
            y += 1;
            p += incNE;
       }
   }
}


void dibujarCono(QPainter & painter) {

    double centroX = 0.0;
    double centroY = 0.0;

    int a = 60; //largo
    int b = 30; //ancho

    dibujarElipse(centroX, centroY, a, b, painter);

    int incX = 60;
    int incY = 100;

    int x0 = centroX + incX;
    int y0 = centroY;

    int x1 = centroX - incX;
    int y1 = y0;

    int x2 = centroX;
    int y2 = y0 - incY;

    BresenhamLine(x2, incY, x1, y1, painter);
    BresenhamLine(x2, y0, x2, y2, painter);
}

void Cono::paintEvent(QPaintEvent *e) {
    QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {
        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarCono(painter);
        }
    }

}

void Cono::on_dibujar_clicked(){
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);
    update();
}

void Cono::on_trasladar_clicked() {
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();
    trans.trasladar(xStr, yStr, vecTrans);
    update();
}

void Cono::on_rotar_clicked() {
    QString gradosStr = ui->boxGrados->toPlainText();
    trans.rotar(gradosStr, vecTrans);
    update();
}

void Cono::on_zoom_out_clicked() {
    trans.zoomOut(vecTrans);
    update();
}

void Cono::on_zoom_in_clicked() {
    trans.zoomIn(vecTrans);
    update();
}

void Cono::on_horizontal_clicked() {
    trans.reflexHorizontal(vecTrans);
    update();
}

void Cono::on_vertical_clicked() {
    trans.reflexVertical(vecTrans);
    update();
}
