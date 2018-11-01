/********************************************************************************
** Form generated from reading UI file 'nuevoedificio.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOEDIFICIO_H
#define UI_NUEVOEDIFICIO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NuevoEdificio
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *NuevoEdificio)
    {
        if (NuevoEdificio->objectName().isEmpty())
            NuevoEdificio->setObjectName(QStringLiteral("NuevoEdificio"));
        NuevoEdificio->resize(232, 67);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/building.png"), QSize(), QIcon::Normal, QIcon::Off);
        NuevoEdificio->setWindowIcon(icon);
        gridLayout = new QGridLayout(NuevoEdificio);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(NuevoEdificio);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(NuevoEdificio);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(NuevoEdificio);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(NuevoEdificio);

        QMetaObject::connectSlotsByName(NuevoEdificio);
    } // setupUi

    void retranslateUi(QWidget *NuevoEdificio)
    {
        NuevoEdificio->setWindowTitle(QApplication::translate("NuevoEdificio", "Nuevo Edificio", nullptr));
        label->setText(QApplication::translate("NuevoEdificio", "Nombre:", nullptr));
        pushButton->setText(QApplication::translate("NuevoEdificio", "Agregar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NuevoEdificio: public Ui_NuevoEdificio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOEDIFICIO_H
