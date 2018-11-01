/********************************************************************************
** Form generated from reading UI file 'menuuser.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUUSER_H
#define UI_MENUUSER_H

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

class Ui_MenuUser
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_2;
    QLabel *label_11;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLabel *label_14;
    QLineEdit *lineEdit_8;
    QLabel *label_13;
    QPushButton *pushButton_9;
    QTextBrowser *textBrowser_6;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_3;
    QWidget *tab_6;
    QGridLayout *gridLayout_6;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_7;
    QTextBrowser *textBrowser_4;
    QWidget *tab_7;
    QGridLayout *gridLayout_7;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_8;
    QTextBrowser *textBrowser_5;

    void setupUi(QWidget *MenuUser)
    {
        if (MenuUser->objectName().isEmpty())
            MenuUser->setObjectName(QStringLiteral("MenuUser"));
        MenuUser->resize(535, 332);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/136f44b4-5bee-4460-a450-b041a78ae746.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MenuUser->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuUser);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        pushButton = new QPushButton(MenuUser);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        label_2 = new QLabel(MenuUser);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 3, 1, 1);

        label = new QLabel(MenuUser);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        tabWidget = new QTabWidget(MenuUser);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 2, 1, 1);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 2, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_6, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_4->addWidget(lineEdit_3, 1, 1, 1, 1);

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
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_8->addWidget(comboBox_2, 3, 1, 1, 1);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_8->addWidget(label_11, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(tab_4);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_8->addWidget(lineEdit_9, 1, 1, 1, 1);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_8->addWidget(label_12, 1, 0, 1, 1);

        lineEdit_10 = new QLineEdit(tab_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_8->addWidget(lineEdit_10, 2, 1, 1, 1);

        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_8->addWidget(label_14, 3, 0, 1, 1);

        lineEdit_8 = new QLineEdit(tab_4);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_8->addWidget(lineEdit_8, 0, 1, 1, 1);

        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_8->addWidget(label_13, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_9, 4, 0, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_4);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_8->addWidget(textBrowser_6, 0, 2, 5, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(tab_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_5->addWidget(lineEdit_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 1, 2, 1, 1);

        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_5->addWidget(textBrowser_3, 0, 0, 1, 3);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_6 = new QGridLayout(tab_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab_6);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_6->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_7, 1, 2, 1, 1);

        textBrowser_4 = new QTextBrowser(tab_6);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_6->addWidget(textBrowser_4, 0, 0, 1, 3);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_7 = new QGridLayout(tab_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_9 = new QLabel(tab_7);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_7->addWidget(label_9, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab_7);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_7->addWidget(lineEdit_6, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(tab_7);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_8, 1, 2, 1, 1);

        textBrowser_5 = new QTextBrowser(tab_7);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout_7->addWidget(textBrowser_5, 0, 0, 1, 3);

        tabWidget->addTab(tab_7, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 2);

        QWidget::setTabOrder(tabWidget, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, comboBox);
        QWidget::setTabOrder(comboBox, pushButton_3);
        QWidget::setTabOrder(pushButton_3, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_6);
        QWidget::setTabOrder(pushButton_6, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, comboBox_2);
        QWidget::setTabOrder(comboBox_2, pushButton_9);
        QWidget::setTabOrder(pushButton_9, textBrowser_6);
        QWidget::setTabOrder(textBrowser_6, textBrowser_3);
        QWidget::setTabOrder(textBrowser_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, textBrowser_4);
        QWidget::setTabOrder(textBrowser_4, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, pushButton_7);
        QWidget::setTabOrder(pushButton_7, textBrowser_5);
        QWidget::setTabOrder(textBrowser_5, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton);

        retranslateUi(MenuUser);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuUser);
    } // setupUi

    void retranslateUi(QWidget *MenuUser)
    {
        MenuUser->setWindowTitle(QApplication::translate("MenuUser", "Usuarios", nullptr));
        pushButton->setText(QApplication::translate("MenuUser", "Regresar", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QApplication::translate("MenuUser", "Administrador", nullptr));
        comboBox->setItemText(2, QApplication::translate("MenuUser", "Coordinador Academico", nullptr));
        comboBox->setItemText(3, QApplication::translate("MenuUser", "Asistente Academico", nullptr));
        comboBox->setItemText(4, QApplication::translate("MenuUser", "Profesor", nullptr));

        label_3->setText(QApplication::translate("MenuUser", "Nombre", nullptr));
        label_4->setText(QApplication::translate("MenuUser", "Contrase\303\261a", nullptr));
        label_5->setText(QApplication::translate("MenuUser", "Perfil", nullptr));
        pushButton_3->setText(QApplication::translate("MenuUser", "Agregar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuUser", "Agregar", nullptr));
        pushButton_2->setText(QApplication::translate("MenuUser", "Mostrar", nullptr));
        pushButton_6->setText(QApplication::translate("MenuUser", "Limpiar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuUser", "Mostrar", nullptr));
        label_6->setText(QApplication::translate("MenuUser", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuUser", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuUser", "Buscar", nullptr));
        comboBox_2->setItemText(0, QString());
        comboBox_2->setItemText(1, QApplication::translate("MenuUser", "Administrador", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MenuUser", "Coordinador Academico", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MenuUser", "Asistente Academico", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("MenuUser", "Profesor", nullptr));

        label_11->setText(QApplication::translate("MenuUser", "C\303\263digo", nullptr));
        label_12->setText(QApplication::translate("MenuUser", "Nombre", nullptr));
        label_14->setText(QApplication::translate("MenuUser", "Perfil", nullptr));
        label_13->setText(QApplication::translate("MenuUser", "Contrase\303\261a", nullptr));
        pushButton_9->setText(QApplication::translate("MenuUser", "Modificar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuUser", "Modificar", nullptr));
        label_7->setText(QApplication::translate("MenuUser", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuUser", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuUser", "Eliminar", nullptr));
        label_8->setText(QApplication::translate("MenuUser", "C\303\263digo", nullptr));
        pushButton_7->setText(QApplication::translate("MenuUser", "Desactivar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MenuUser", "Desactivar", nullptr));
        label_9->setText(QApplication::translate("MenuUser", "C\303\263digo", nullptr));
        pushButton_8->setText(QApplication::translate("MenuUser", "Activar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MenuUser", "Activar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuUser: public Ui_MenuUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUUSER_H
