#ifndef ARGO_H
#define ARGO_H

#include <QDialog>

namespace Ui {
class argo;
}

class argo : public QDialog
{
    Q_OBJECT

public:
    explicit argo(QWidget *parent = nullptr);
    ~argo();

private:
    Ui::argo *ui;
};

#endif // ARGO_H
