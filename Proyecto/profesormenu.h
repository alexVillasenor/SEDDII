#ifndef PROFESORMENU_H
#define PROFESORMENU_H

#include <QWidget>
#include <login.h>

namespace Ui {
class ProfesorMenu;
}

class ProfesorMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ProfesorMenu(QWidget *parent = 0);
    ~ProfesorMenu();

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QString code;
    Ui::ProfesorMenu *ui;
};

#endif // PROFESORMENU_H
