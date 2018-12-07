#ifndef MENUASISTENTE_H
#define MENUASISTENTE_H

#include <QWidget>
#include "login.h"

namespace Ui {
class MenuAsistente;
}

class MenuAsistente : public QWidget
{
    Q_OBJECT

public:
    explicit MenuAsistente(QWidget *parent = 0);
    ~MenuAsistente();

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuAsistente *ui;
    QString code;
};

#endif // MENUASISTENTE_H
