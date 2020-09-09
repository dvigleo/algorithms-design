#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_poligono_clicked() {
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}

void Dialog::on_arco_clicked() {
    Arcos arco;
    arco.setModal(true);
    arco.exec();
}

void Dialog::on_cubo_clicked() {
    cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}

void Dialog::on_cono_clicked() {
    Cono cono;
    cono.setModal(true);
    cono.exec();
}

void Dialog::on_prismarec_clicked() {
    prismarec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();
}

void Dialog::on_prismatri_clicked() {
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}
