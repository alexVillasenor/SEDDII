#ifndef MENUASIGNATURA_H
#define MENUASIGNATURA_H

#include <QWidget>
#include "login.h"
#include <fstream>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QIntValidator>
#include <QRegExpValidator>
#include <regex>
#include "list.h"
#include "asignatura.h"
#include "indice.h"
#include "stack.h"
#include "listainvertida.h"
#include <sstream>



namespace Ui {
class MenuAsignatura;
}

class MenuAsignatura : public QWidget
{
    Q_OBJECT

public:
    explicit MenuAsignatura(QWidget *parent = 0);
    ~MenuAsignatura();

    void autoSave();
    void loadIndex();
    void printIndiceSec();
    void saveListaInvertida();
    void setPermisos();

    std::string getPerfil() const;
    void setPerfil(const std::string &value);

private slots:
    void timerSave();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    List<Indice> listaIndices;
    Stack<Asignatura> stack;
    Stack<long int> stackDireccion;
    ListaInvertida listainvertida;
    std::string perfil;
    Ui::MenuAsignatura *ui;
};

#endif // MENUASIGNATURA_H
