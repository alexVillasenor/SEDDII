/********************************************************************************
** Form generated from reading UI file 'nuevoenlace.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOENLACE_H
#define UI_NUEVOENLACE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NuevoEnlace
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *NuevoEnlace)
    {
        if (NuevoEnlace->objectName().isEmpty())
            NuevoEnlace->setObjectName(QStringLiteral("NuevoEnlace"));
        NuevoEnlace->resize(351, 173);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/way-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        NuevoEnlace->setWindowIcon(icon);
        gridLayout = new QGridLayout(NuevoEnlace);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_2 = new QComboBox(NuevoEnlace);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 2, 1, 3);

        comboBox = new QComboBox(NuevoEnlace);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 2);

        lineEdit = new QLineEdit(NuevoEnlace);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 4, 1, 1);

        label = new QLabel(NuevoEnlace);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(NuevoEnlace);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        pushButton = new QPushButton(NuevoEnlace);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);


        retranslateUi(NuevoEnlace);

        QMetaObject::connectSlotsByName(NuevoEnlace);
    } // setupUi

    void retranslateUi(QWidget *NuevoEnlace)
    {
        NuevoEnlace->setWindowTitle(QApplication::translate("NuevoEnlace", "Nuevo Camino", nullptr));
        label->setText(QApplication::translate("NuevoEnlace", "Distancia:", nullptr));
        pushButton_2->setText(QApplication::translate("NuevoEnlace", "Terminar", nullptr));
        pushButton->setText(QApplication::translate("NuevoEnlace", "Agregar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NuevoEnlace: public Ui_NuevoEnlace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOENLACE_H
