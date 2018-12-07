/********************************************************************************
** Form generated from reading UI file 'menugrupo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUGRUPO_H
#define UI_MENUGRUPO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_MenuGrupo
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLabel *label_10;
    QComboBox *comboBox_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QTextBrowser *textBrowser_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_5;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_4;
    QWidget *tab_6;
    QGridLayout *gridLayout_7;
    QTextBrowser *textBrowser_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_7;
    QWidget *tab_7;
    QGridLayout *gridLayout_8;
    QTextBrowser *textBrowser_6;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_8;

    void setupUi(QWidget *MenuGrupo)
    {
        if (MenuGrupo->objectName().isEmpty())
            MenuGrupo->setObjectName(QStringLiteral("MenuGrupo"));
        MenuGrupo->resize(480, 313);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/group_users_13234.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuGrupo->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuGrupo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuGrupo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        tabWidget = new QTabWidget(MenuGrupo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 3, 0, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 1, 1, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        comboBox_3 = new QComboBox(tab);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_2->addWidget(comboBox_3, 2, 1, 1, 1);

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
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_4, 1, 2, 1, 1);

        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_4->addWidget(textBrowser_2, 0, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 3, 0, 1, 2);

        lineEdit_3 = new QLineEdit(tab_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 1);

        textBrowser_3 = new QTextBrowser(tab_4);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_5->addWidget(textBrowser_3, 0, 2, 4, 1);

        lineEdit_4 = new QLineEdit(tab_4);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_5->addWidget(lineEdit_4, 1, 1, 1, 1);

        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_5->addWidget(comboBox, 2, 1, 1, 1);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab_5);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_6->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_6, 1, 2, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_5);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_6->addWidget(textBrowser_4, 0, 0, 1, 3);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_7 = new QGridLayout(tab_6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        textBrowser_5 = new QTextBrowser(tab_6);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout_7->addWidget(textBrowser_5, 0, 0, 1, 3);

        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_7->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab_6);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_7->addWidget(lineEdit_6, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_7, 1, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_8 = new QGridLayout(tab_7);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        textBrowser_6 = new QTextBrowser(tab_7);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_8->addWidget(textBrowser_6, 0, 0, 1, 3);

        label_9 = new QLabel(tab_7);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_8->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_7);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_8->addWidget(lineEdit_7, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(tab_7);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_8, 1, 2, 1, 1);

        tabWidget->addTab(tab_7, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);


        retranslateUi(MenuGrupo);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MenuGrupo);
    } // setupUi

    void retranslateUi(QWidget *MenuGrupo)
    {
        MenuGrupo->setWindowTitle(QApplication::translate("MenuGrupo", "Menu Grupo", nullptr));
        pushButton->setText(QApplication::translate("MenuGrupo", "Regresar", nullptr));
        label->setText(QApplication::translate("MenuGrupo", "Nombre:", nullptr));
        pushButton_2->setText(QApplication::translate("MenuGrupo", "Agregar", nullptr));
        label_6->setText(QApplication::translate("MenuGrupo", "Periodo:", nullptr));
        label_10->setText(QApplication::translate("MenuGrupo", "Grado:", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("MenuGrupo", "Primero", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MenuGrupo", "Segundo", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("MenuGrupo", "Tercero", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuGrupo", "Crear", nullptr));
        pushButton_3->setText(QApplication::translate("MenuGrupo", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuGrupo", "Mostrar", nullptr));
        label_2->setText(QApplication::translate("MenuGrupo", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuGrupo", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuGrupo", "Buscar", nullptr));
        pushButton_5->setText(QApplication::translate("MenuGrupo", "Modificar", nullptr));
        label_4->setText(QApplication::translate("MenuGrupo", "Nombre", nullptr));
        label_3->setText(QApplication::translate("MenuGrupo", "C\303\263digo", nullptr));
        label_5->setText(QApplication::translate("MenuGrupo", "Periodo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuGrupo", "Modificar", nullptr));
        label_7->setText(QApplication::translate("MenuGrupo", "C\303\263digo", nullptr));
        pushButton_6->setText(QApplication::translate("MenuGrupo", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuGrupo", "Eliminar", nullptr));
        label_8->setText(QApplication::translate("MenuGrupo", "C\303\263digo", nullptr));
        pushButton_7->setText(QApplication::translate("MenuGrupo", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MenuGrupo", "Desactivar", nullptr));
        label_9->setText(QApplication::translate("MenuGrupo", "C\303\263digo", nullptr));
        pushButton_8->setText(QApplication::translate("MenuGrupo", "Activar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MenuGrupo", "Activar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuGrupo: public Ui_MenuGrupo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUGRUPO_H
