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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOferta
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_Grupo;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_Periodo;
    QComboBox *comboBox_Asignatura;
    QComboBox *comboBox;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QTextBrowser *textBrowser_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_Profesor_2;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser_4;
    QLabel *label_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_5;

    void setupUi(QWidget *MenuOferta)
    {
        if (MenuOferta->objectName().isEmpty())
            MenuOferta->setObjectName(QStringLiteral("MenuOferta"));
        MenuOferta->resize(573, 400);
        gridLayout = new QGridLayout(MenuOferta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        pushButton = new QPushButton(MenuOferta);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        tabWidget = new QTabWidget(MenuOferta);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        comboBox_Grupo = new QComboBox(tab);
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->addItem(QString());
        comboBox_Grupo->setObjectName(QStringLiteral("comboBox_Grupo"));

        gridLayout_2->addWidget(comboBox_Grupo, 3, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 5, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 5, 1, 1, 1);

        comboBox_Periodo = new QComboBox(tab);
        comboBox_Periodo->setObjectName(QStringLiteral("comboBox_Periodo"));

        gridLayout_2->addWidget(comboBox_Periodo, 0, 1, 1, 1);

        comboBox_Asignatura = new QComboBox(tab);
        comboBox_Asignatura->setObjectName(QStringLiteral("comboBox_Asignatura"));

        gridLayout_2->addWidget(comboBox_Asignatura, 1, 1, 1, 1);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 4, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_3, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_4->addWidget(textBrowser_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_4, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        comboBox_Profesor_2 = new QComboBox(tab_4);
        comboBox_Profesor_2->setObjectName(QStringLiteral("comboBox_Profesor_2"));

        gridLayout_6->addWidget(comboBox_Profesor_2, 2, 2, 1, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(tab_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_6->addWidget(lineEdit_3, 0, 2, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_4);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_6->addWidget(textBrowser_4, 0, 3, 5, 1);

        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(tab_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(tab_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_6, 3, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_5->addWidget(textBrowser_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_5->addWidget(lineEdit_2, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 2, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);


        retranslateUi(MenuOferta);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MenuOferta);
    } // setupUi

    void retranslateUi(QWidget *MenuOferta)
    {
        MenuOferta->setWindowTitle(QApplication::translate("MenuOferta", "Menu Oferta", nullptr));
        pushButton->setText(QApplication::translate("MenuOferta", "Regresar", nullptr));
        label_3->setText(QApplication::translate("MenuOferta", "Grupo", nullptr));
        label->setText(QApplication::translate("MenuOferta", "Periodo:", nullptr));
        label_2->setText(QApplication::translate("MenuOferta", "Grado:", nullptr));
        comboBox_Grupo->setItemText(0, QApplication::translate("MenuOferta", "Primero", nullptr));
        comboBox_Grupo->setItemText(1, QApplication::translate("MenuOferta", "Segundo", nullptr));
        comboBox_Grupo->setItemText(2, QApplication::translate("MenuOferta", "Tercero", nullptr));
        comboBox_Grupo->setItemText(3, QApplication::translate("MenuOferta", "Cuarto", nullptr));
        comboBox_Grupo->setItemText(4, QApplication::translate("MenuOferta", "Quinto", nullptr));
        comboBox_Grupo->setItemText(5, QApplication::translate("MenuOferta", "Sexto", nullptr));
        comboBox_Grupo->setItemText(6, QApplication::translate("MenuOferta", "Septimo", nullptr));
        comboBox_Grupo->setItemText(7, QApplication::translate("MenuOferta", "Octavo", nullptr));

        label_4->setText(QApplication::translate("MenuOferta", "Carrera:", nullptr));
        pushButton_2->setText(QApplication::translate("MenuOferta", "Agregar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuOferta", "Crear", nullptr));
        pushButton_3->setText(QApplication::translate("MenuOferta", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuOferta", "Mostrar", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MenuOferta", "Codigo Oferta", nullptr));
        pushButton_4->setText(QApplication::translate("MenuOferta", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuOferta", "Buscar", nullptr));
        label_7->setText(QApplication::translate("MenuOferta", "Profesor:", nullptr));
        label_9->setText(QApplication::translate("MenuOferta", "Codigo Oferta:", nullptr));
        pushButton_7->setText(QApplication::translate("MenuOferta", "Buscar", nullptr));
        pushButton_6->setText(QApplication::translate("MenuOferta", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuOferta", "Modificar", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("MenuOferta", "Codigo Oferta", nullptr));
        pushButton_5->setText(QApplication::translate("MenuOferta", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuOferta", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuOferta: public Ui_MenuOferta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOFERTA_H
