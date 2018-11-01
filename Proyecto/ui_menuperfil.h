/********************************************************************************
** Form generated from reading UI file 'menuperfil.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPERFIL_H
#define UI_MENUPERFIL_H

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

class Ui_MenuPerfil
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_8;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLabel *label_7;
    QTextBrowser *textBrowser_6;
    QPushButton *pushButton_9;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_3;
    QWidget *tab_6;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser_4;
    QWidget *tab_7;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_5;

    void setupUi(QWidget *MenuPerfil)
    {
        if (MenuPerfil->objectName().isEmpty())
            MenuPerfil->setObjectName(QStringLiteral("MenuPerfil"));
        MenuPerfil->resize(480, 316);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/d606055a-5a8e-49a3-a152-517730d111df.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MenuPerfil->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuPerfil);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuPerfil);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(343, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        tabWidget = new QTabWidget(MenuPerfil);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_7->addWidget(lineEdit_6, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_8, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_7, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_3, 1, 2, 1, 1);

        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_3->addWidget(textBrowser_2, 0, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        lineEdit_5 = new QLineEdit(tab_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_8->addWidget(lineEdit_5, 0, 1, 1, 1);

        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_8->addWidget(lineEdit_7, 1, 1, 1, 1);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_8->addWidget(label_5, 0, 0, 1, 1);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_8->addWidget(label_7, 1, 0, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_4);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_8->addWidget(textBrowser_6, 0, 2, 3, 1);

        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_9, 2, 1, 1, 1);

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

        gridLayout_5->addWidget(label_3, 1, 0, 2, 1);

        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 1, 2, 2, 1);

        lineEdit_3 = new QLineEdit(tab_6);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_5->addWidget(lineEdit_3, 2, 1, 1, 1);

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

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);

        QWidget::setTabOrder(tabWidget, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, pushButton_8);
        QWidget::setTabOrder(pushButton_8, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_7);
        QWidget::setTabOrder(pushButton_7, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, pushButton_9);
        QWidget::setTabOrder(pushButton_9, textBrowser_6);
        QWidget::setTabOrder(textBrowser_6, textBrowser_3);
        QWidget::setTabOrder(textBrowser_3, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton_4);
        QWidget::setTabOrder(pushButton_4, textBrowser_4);
        QWidget::setTabOrder(textBrowser_4, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton_5);
        QWidget::setTabOrder(pushButton_5, textBrowser_5);
        QWidget::setTabOrder(textBrowser_5, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton);

        retranslateUi(MenuPerfil);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MenuPerfil);
    } // setupUi

    void retranslateUi(QWidget *MenuPerfil)
    {
        MenuPerfil->setWindowTitle(QApplication::translate("MenuPerfil", "Perfiles", nullptr));
        pushButton->setText(QApplication::translate("MenuPerfil", "Regresar", nullptr));
        label_6->setText(QApplication::translate("MenuPerfil", "Nombre", nullptr));
        pushButton_8->setText(QApplication::translate("MenuPerfil", "Agregar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuPerfil", "Agregar", nullptr));
        pushButton_2->setText(QApplication::translate("MenuPerfil", "Mostrar", nullptr));
        pushButton_7->setText(QApplication::translate("MenuPerfil", "Limpiar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuPerfil", "Mostrar", nullptr));
        label->setText(QApplication::translate("MenuPerfil", "C\303\263digo", nullptr));
        pushButton_3->setText(QApplication::translate("MenuPerfil", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuPerfil", "Buscar", nullptr));
        label_5->setText(QApplication::translate("MenuPerfil", "C\303\263digo", nullptr));
        label_7->setText(QApplication::translate("MenuPerfil", "Nombre", nullptr));
        pushButton_9->setText(QApplication::translate("MenuPerfil", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuPerfil", "Modificar", nullptr));
        label_2->setText(QApplication::translate("MenuPerfil", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuPerfil", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuPerfil", "Eliminar", nullptr));
        label_3->setText(QApplication::translate("MenuPerfil", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuPerfil", "Desactivar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MenuPerfil", "Desactivar", nullptr));
        label_4->setText(QApplication::translate("MenuPerfil", "C\303\263digo", nullptr));
        pushButton_6->setText(QApplication::translate("MenuPerfil", "Activar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MenuPerfil", "Activar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPerfil: public Ui_MenuPerfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPERFIL_H
