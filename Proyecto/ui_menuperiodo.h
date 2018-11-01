/********************************************************************************
** Form generated from reading UI file 'menuperiodo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPERIODO_H
#define UI_MENUPERIODO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPeriodo
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_7;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QDateEdit *dateEdit_2;
    QLabel *label_7;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QDateEdit *dateEdit_4;
    QPushButton *pushButton_8;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QDateEdit *dateEdit_3;
    QLabel *label_9;
    QTextBrowser *textBrowser_6;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_3;
    QWidget *tab_6;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_4;
    QWidget *tab_7;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_5;

    void setupUi(QWidget *MenuPeriodo)
    {
        if (MenuPeriodo->objectName().isEmpty())
            MenuPeriodo->setObjectName(QStringLiteral("MenuPeriodo"));
        MenuPeriodo->resize(513, 316);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icons/38162852-piso-icono-azul-vector-ronda-con-blanco-calendario-silueta-para-el-per\303\255odo-menstrual-en-el.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MenuPeriodo->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuPeriodo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButton = new QPushButton(MenuPeriodo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        tabWidget = new QTabWidget(MenuPeriodo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_7->addWidget(lineEdit_5, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_7, 3, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_7->addWidget(label_5, 1, 1, 1, 1);

        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout_7->addWidget(dateEdit, 1, 2, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_7->addWidget(label_6, 2, 1, 1, 1);

        dateEdit_2 = new QDateEdit(tab);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        gridLayout_7->addWidget(dateEdit_2, 2, 2, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_7->addWidget(label_7, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 0, 2, 1);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_3, 1, 2, 2, 1);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 2, 1, 1, 1);

        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_3->addWidget(textBrowser_2, 0, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        dateEdit_4 = new QDateEdit(tab_4);
        dateEdit_4->setObjectName(QStringLiteral("dateEdit_4"));

        gridLayout_8->addWidget(dateEdit_4, 3, 1, 1, 1);

        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_8, 4, 0, 1, 2);

        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_8->addWidget(lineEdit_6, 0, 1, 1, 1);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_8->addWidget(label_10, 3, 0, 1, 1);

        dateEdit_3 = new QDateEdit(tab_4);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));

        gridLayout_8->addWidget(dateEdit_3, 2, 1, 1, 1);

        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_8->addWidget(label_9, 2, 0, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_4);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_8->addWidget(textBrowser_6, 0, 2, 5, 1);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_8->addWidget(label_11, 1, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_8->addWidget(lineEdit_7, 1, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_4, 1, 2, 1, 1);

        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_4->addWidget(textBrowser_3, 0, 0, 1, 3);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_5 = new QGridLayout(tab_6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_3 = new QLabel(tab_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(tab_6);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 1, 2, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_6);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_5->addWidget(textBrowser_4, 0, 0, 1, 3);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_6 = new QGridLayout(tab_7);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_4 = new QLabel(tab_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_6->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(tab_7);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_6->addWidget(lineEdit_4, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_7);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_6, 1, 2, 1, 1);

        textBrowser_5 = new QTextBrowser(tab_7);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout_6->addWidget(textBrowser_5, 0, 0, 1, 3);

        tabWidget->addTab(tab_7, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);

        QWidget::setTabOrder(tabWidget, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, dateEdit);
        QWidget::setTabOrder(dateEdit, dateEdit_2);
        QWidget::setTabOrder(dateEdit_2, pushButton_7);
        QWidget::setTabOrder(pushButton_7, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton_2);
        QWidget::setTabOrder(pushButton_2, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, textBrowser_3);
        QWidget::setTabOrder(textBrowser_3, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton_4);
        QWidget::setTabOrder(pushButton_4, textBrowser_4);
        QWidget::setTabOrder(textBrowser_4, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton_5);
        QWidget::setTabOrder(pushButton_5, textBrowser_5);
        QWidget::setTabOrder(textBrowser_5, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton);

        retranslateUi(MenuPeriodo);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuPeriodo);
    } // setupUi

    void retranslateUi(QWidget *MenuPeriodo)
    {
        MenuPeriodo->setWindowTitle(QApplication::translate("MenuPeriodo", "Menu Periodo", nullptr));
        pushButton->setText(QApplication::translate("MenuPeriodo", "Regresar", nullptr));
        pushButton_7->setText(QApplication::translate("MenuPeriodo", "Agregar", nullptr));
        label_5->setText(QApplication::translate("MenuPeriodo", "Fecha de inicio", nullptr));
        label_6->setText(QApplication::translate("MenuPeriodo", "Fecha de fin", nullptr));
        label_7->setText(QApplication::translate("MenuPeriodo", "Nombre", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuPeriodo", "Crear", nullptr));
        pushButton_2->setText(QApplication::translate("MenuPeriodo", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuPeriodo", "Mostrar", nullptr));
        label->setText(QApplication::translate("MenuPeriodo", "C\303\263digo", nullptr));
        pushButton_3->setText(QApplication::translate("MenuPeriodo", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuPeriodo", "Buscar", nullptr));
        pushButton_8->setText(QApplication::translate("MenuPeriodo", "Modificar", nullptr));
        label_8->setText(QApplication::translate("MenuPeriodo", "C\303\263digo", nullptr));
        label_10->setText(QApplication::translate("MenuPeriodo", "Fecha de fin", nullptr));
        label_9->setText(QApplication::translate("MenuPeriodo", "Fecha de inicio", nullptr));
        label_11->setText(QApplication::translate("MenuPeriodo", "Nombre", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuPeriodo", "Modificar", nullptr));
        label_2->setText(QApplication::translate("MenuPeriodo", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuPeriodo", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuPeriodo", "Eliminar", nullptr));
        label_3->setText(QApplication::translate("MenuPeriodo", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuPeriodo", "Desactivar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MenuPeriodo", "Desactivar", nullptr));
        label_4->setText(QApplication::translate("MenuPeriodo", "C\303\263digo", nullptr));
        pushButton_6->setText(QApplication::translate("MenuPeriodo", "Activar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MenuPeriodo", "Activar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPeriodo: public Ui_MenuPeriodo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPERIODO_H
