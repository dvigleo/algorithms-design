#include "argo.h"
#include "ui_argo.h"

argo::argo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::argo)
{
    ui->setupUi(this);
}

argo::~argo()
{
    delete ui;
}
