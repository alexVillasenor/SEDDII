#ifndef ASIGNACIONPROF_H
#define ASIGNACIONPROF_H

#include <QWidget>
#include "login.h"

namespace Ui {
class AsignacionProf;
}

class AsignacionProf : public QWidget
{
    Q_OBJECT

public:
    explicit AsignacionProf(QWidget *parent = 0);
    ~AsignacionProf();

    void setComboOferta();
    void setComboProfesores();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::AsignacionProf *ui;
};

#endif // ASIGNACIONPROF_H
