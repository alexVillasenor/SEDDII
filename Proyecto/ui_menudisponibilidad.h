/********************************************************************************
** Form generated from reading UI file 'menudisponibilidad.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUDISPONIBILIDAD_H
#define UI_MENUDISPONIBILIDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuDisponibilidad
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Materias;
    QComboBox *comboBox_Profesor;
    QLabel *label_3;
    QComboBox *comboBox_Carrera;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;

    void setupUi(QWidget *MenuDisponibilidad)
    {
        if (MenuDisponibilidad->objectName().isEmpty())
            MenuDisponibilidad->setObjectName(QStringLiteral("MenuDisponibilidad"));
        MenuDisponibilidad->resize(376, 320);
        gridLayout = new QGridLayout(MenuDisponibilidad);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuDisponibilidad);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        tabWidget = new QTabWidget(MenuDisponibilidad);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox_Materias = new QComboBox(tab);
        comboBox_Materias->setObjectName(QStringLiteral("comboBox_Materias"));

        gridLayout_2->addWidget(comboBox_Materias, 2, 1, 1, 1);

        comboBox_Profesor = new QComboBox(tab);
        comboBox_Profesor->setObjectName(QStringLiteral("comboBox_Profesor"));

        gridLayout_2->addWidget(comboBox_Profesor, 0, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        comboBox_Carrera = new QComboBox(tab);
        comboBox_Carrera->setObjectName(QStringLiteral("comboBox_Carrera"));

        gridLayout_2->addWidget(comboBox_Carrera, 1, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 3, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_3, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);


        retranslateUi(MenuDisponibilidad);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MenuDisponibilidad);
    } // setupUi

    void retranslateUi(QWidget *MenuDisponibilidad)
    {
        MenuDisponibilidad->setWindowTitle(QApplication::translate("MenuDisponibilidad", "Menu Disponibilidad", nullptr));
        pushButton->setText(QApplication::translate("MenuDisponibilidad", "Regresar", nullptr));
        label_3->setText(QApplication::translate("MenuDisponibilidad", "Materia", nullptr));
        label_2->setText(QApplication::translate("MenuDisponibilidad", "Carrera", nullptr));
        pushButton_2->setText(QApplication::translate("MenuDisponibilidad", "Agregar", nullptr));
        label->setText(QApplication::translate("MenuDisponibilidad", "Profesor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuDisponibilidad", "Crear", nullptr));
        pushButton_3->setText(QApplication::translate("MenuDisponibilidad", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuDisponibilidad", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuDisponibilidad", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuDisponibilidad", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuDisponibilidad", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuDisponibilidad: public Ui_MenuDisponibilidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUDISPONIBILIDAD_H
