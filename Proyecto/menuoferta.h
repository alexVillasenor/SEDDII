#ifndef MENUOFERTA_H
#define MENUOFERTA_H

#include <QWidget>

namespace Ui {
class MenuOferta;
}

class MenuOferta : public QWidget
{
    Q_OBJECT

public:
    explicit MenuOferta(QWidget *parent = 0);
    ~MenuOferta();

private:
    Ui::MenuOferta *ui;
};

#endif // MENUOFERTA_H
