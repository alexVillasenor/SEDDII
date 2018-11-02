#ifndef MENUDISPONIBILIDAD_H
#define MENUDISPONIBILIDAD_H

#include <QWidget>
#include "disponibilidad.h"
#include "login.h"
#include "list.h"
#include "listainvertida.h"
#include "indice.h"
#include "programa.h"
#include <string>
#define FILAS 100
#define COLUMNAS 4


namespace Ui {
class MenuDisponibilidad;
}

class MenuDisponibilidad : public QWidget
{
    Q_OBJECT

public:
    explicit MenuDisponibilidad(QWidget *parent = 0);
    ~MenuDisponibilidad();
    void setProfesores();
    void setCarreras();
    void setMaterias();
    void loadIndex();
    void genera();
    long int dispersion(std::string clave);

    int getType() const;
    void setType(int value);

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_Carrera_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_4_clicked();

private:
    List<Indice> listaIndices;
    ListaInvertida listainvertida;
    int type;
    QString code;
    Ui::MenuDisponibilidad *ui;
};

#endif // MENUDISPONIBILIDAD_H
