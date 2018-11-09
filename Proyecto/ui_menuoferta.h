/********************************************************************************
** Form generated from reading UI file 'menuoferta.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUOFERTA_H
#define UI_MENUOFERTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOferta
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_Periodo;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_Grupo;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_Profesor;
    QComboBox *comboBox_Asignatura;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MenuOferta)
    {
        if (MenuOferta->objectName().isEmpty())
            MenuOferta->setObjectName(QStringLiteral("MenuOferta"));
        MenuOferta->resize(573, 400);
        gridLayout = new QGridLayout(MenuOferta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(MenuOferta);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox_Periodo = new QComboBox(tab);
        comboBox_Periodo->setObjectName(QStringLiteral("comboBox_Periodo"));

        gridLayout_2->addWidget(comboBox_Periodo, 2, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        comboBox_Grupo = new QComboBox(tab);
        comboBox_Grupo->setObjectName(QStringLiteral("comboBox_Grupo"));

        gridLayout_2->addWidget(comboBox_Grupo, 3, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        comboBox_Profesor = new QComboBox(tab);
        comboBox_Profesor->setObjectName(QStringLiteral("comboBox_Profesor"));

        gridLayout_2->addWidget(comboBox_Profesor, 0, 1, 1, 1);

        comboBox_Asignatura = new QComboBox(tab);
        comboBox_Asignatura->setObjectName(QStringLiteral("comboBox_Asignatura"));

        gridLayout_2->addWidget(comboBox_Asignatura, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 1, 1, 1);

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

        pushButton = new QPushButton(MenuOferta);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(MenuOferta);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuOferta);
    } // setupUi

    void retranslateUi(QWidget *MenuOferta)
    {
        MenuOferta->setWindowTitle(QApplication::translate("MenuOferta", "Form", nullptr));
        label->setText(QApplication::translate("MenuOferta", "Periodo:", nullptr));
        label_2->setText(QApplication::translate("MenuOferta", "Grupo:", nullptr));
        label_3->setText(QApplication::translate("MenuOferta", "Profesor:", nullptr));
        label_4->setText(QApplication::translate("MenuOferta", "Asignatura:", nullptr));
        pushButton_2->setText(QApplication::translate("MenuOferta", "Agregar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuOferta", "Crear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuOferta", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuOferta", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuOferta", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuOferta", "Eliminar", nullptr));
        pushButton->setText(QApplication::translate("MenuOferta", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuOferta: public Ui_MenuOferta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOFERTA_H
