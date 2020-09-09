#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "poligonos.h"
#include "arcos.h"
#include "cubo.h"
#include "cono.h"
#include "prismarec.h"
#include "prismatri.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_poligono_clicked();
    void on_arco_clicked();
    void on_cubo_clicked();
    void on_cono_clicked();
    void on_prismarec_clicked();
    void on_prismatri_clicked();
private:
    Ui::Dialog *ui;
};

#endif
