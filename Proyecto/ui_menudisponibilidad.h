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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuDisponibilidad
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MenuDisponibilidad)
    {
        if (MenuDisponibilidad->objectName().isEmpty())
            MenuDisponibilidad->setObjectName(QStringLiteral("MenuDisponibilidad"));
        MenuDisponibilidad->resize(545, 422);
        gridLayout = new QGridLayout(MenuDisponibilidad);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(MenuDisponibilidad);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
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

        pushButton = new QPushButton(MenuDisponibilidad);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(MenuDisponibilidad);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MenuDisponibilidad);
    } // setupUi

    void retranslateUi(QWidget *MenuDisponibilidad)
    {
        MenuDisponibilidad->setWindowTitle(QApplication::translate("MenuDisponibilidad", "Menu Disponibilidad", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuDisponibilidad", "Crear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuDisponibilidad", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuDisponibilidad", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuDisponibilidad", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuDisponibilidad", "Eliminar", nullptr));
        pushButton->setText(QApplication::translate("MenuDisponibilidad", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuDisponibilidad: public Ui_MenuDisponibilidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUDISPONIBILIDAD_H
