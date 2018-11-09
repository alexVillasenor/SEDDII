#include "menuoferta.h"
#include "ui_menuoferta.h"

MenuOferta::MenuOferta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuOferta)
{
    ui->setupUi(this);
}

MenuOferta::~MenuOferta()
{
    delete ui;
}
