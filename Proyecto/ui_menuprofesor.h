/********************************************************************************
** Form generated from reading UI file 'menuprofesor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPROFESOR_H
#define UI_MENUPROFESOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuProfesor
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QTextBrowser *textBrowser_4;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_7;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QTextBrowser *textBrowser_3;

    void setupUi(QWidget *MenuProfesor)
    {
        if (MenuProfesor->objectName().isEmpty())
            MenuProfesor->setObjectName(QStringLiteral("MenuProfesor"));
        MenuProfesor->resize(485, 313);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/34022.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuProfesor->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuProfesor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(MenuProfesor);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        tabWidget = new QTabWidget(MenuProfesor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_4, 2, 1, 1, 1);

        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 0, 0, 2, 2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_4->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_5, 1, 2, 1, 1);

        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_4->addWidget(textBrowser_2, 0, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_6->addWidget(lineEdit_7, 0, 1, 1, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_4);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_6->addWidget(textBrowser_4, 0, 2, 4, 1);

        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_9 = new QLineEdit(tab_4);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_6->addWidget(lineEdit_9, 1, 1, 1, 1);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_10 = new QLineEdit(tab_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_6->addWidget(lineEdit_10, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(tab_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_7, 3, 0, 1, 2);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lineEdit_6 = new QLineEdit(tab_5);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_5->addWidget(lineEdit_6, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_6, 1, 2, 1, 1);

        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);

        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_5->addWidget(textBrowser_3, 0, 0, 1, 3);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

        QWidget::setTabOrder(tabWidget, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton);
        QWidget::setTabOrder(pushButton, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, pushButton_5);
        QWidget::setTabOrder(pushButton_5, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, pushButton_7);
        QWidget::setTabOrder(pushButton_7, textBrowser_4);
        QWidget::setTabOrder(textBrowser_4, textBrowser_3);
        QWidget::setTabOrder(textBrowser_3, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_2);

        retranslateUi(MenuProfesor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuProfesor);
    } // setupUi

    void retranslateUi(QWidget *MenuProfesor)
    {
        MenuProfesor->setWindowTitle(QApplication::translate("MenuProfesor", "Menu Profesores", nullptr));
        pushButton_2->setText(QApplication::translate("MenuProfesor", "Regresar", nullptr));
        pushButton->setText(QApplication::translate("MenuProfesor", "Agregar", nullptr));
        label_3->setText(QApplication::translate("MenuProfesor", "Correo", nullptr));
        label_4->setText(QApplication::translate("MenuProfesor", "Tel\303\251fono", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuProfesor", "Agregar", nullptr));
        pushButton_3->setText(QApplication::translate("MenuProfesor", "Mostrar", nullptr));
        pushButton_4->setText(QApplication::translate("MenuProfesor", "Limpiar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuProfesor", "Mostrar", nullptr));
        label_5->setText(QApplication::translate("MenuProfesor", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuProfesor", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuProfesor", "Buscar", nullptr));
        label_7->setText(QApplication::translate("MenuProfesor", "C\303\263digo", nullptr));
        label_9->setText(QApplication::translate("MenuProfesor", "Correo", nullptr));
        label_10->setText(QApplication::translate("MenuProfesor", "Tel\303\251fono", nullptr));
        pushButton_7->setText(QApplication::translate("MenuProfesor", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuProfesor", "Modificar", nullptr));
        pushButton_6->setText(QApplication::translate("MenuProfesor", "Eliminar", nullptr));
        label_6->setText(QApplication::translate("MenuProfesor", "C\303\263digo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuProfesor", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuProfesor: public Ui_MenuProfesor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPROFESOR_H
