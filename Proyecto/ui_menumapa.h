/********************************************************************************
** Form generated from reading UI file 'menumapa.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUMAPA_H
#define UI_MENUMAPA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuMapa
{
public:
    QGridLayout *gridLayout_12;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget_3;
    QWidget *stackedWidget_3Page1;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser_2;
    QWidget *tab_8;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QTextBrowser *textBrowser_7;
    QLineEdit *lineEdit_7;
    QWidget *tab_9;
    QGridLayout *gridLayout_10;
    QTextBrowser *textBrowser_8;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_14;
    QWidget *stackedWidget_3Page2;
    QGridLayout *gridLayout_11;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_13;
    QTextBrowser *textBrowser_9;
    QPushButton *pushButton_mostarEdificios;
    QWidget *tab_10;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QTextBrowser *textBrowser_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_8;
    QWidget *tab_11;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QTextBrowser *textBrowser_6;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_9;
    QWidget *tab_5;
    QGridLayout *gridLayout_8;
    QTextBrowser *textBrowser_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QWidget *tab_7;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_4;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QPushButton *pushButton_7;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_16;

    void setupUi(QWidget *MenuMapa)
    {
        if (MenuMapa->objectName().isEmpty())
            MenuMapa->setObjectName(QStringLiteral("MenuMapa"));
        MenuMapa->resize(683, 452);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/descarga.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuMapa->setWindowIcon(icon);
        gridLayout_12 = new QGridLayout(MenuMapa);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer, 1, 1, 1, 1);

        stackedWidget_3 = new QStackedWidget(MenuMapa);
        stackedWidget_3->setObjectName(QStringLiteral("stackedWidget_3"));
        stackedWidget_3->setEnabled(true);
        stackedWidget_3Page1 = new QWidget();
        stackedWidget_3Page1->setObjectName(QStringLiteral("stackedWidget_3Page1"));
        gridLayout_6 = new QGridLayout(stackedWidget_3Page1);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidget = new QTabWidget(stackedWidget_3Page1);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_2, 1, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_10, 1, 2, 1, 1);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_4->addWidget(pushButton_6, 1, 3, 1, 1);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 0, 2, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_3, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout_3->addWidget(pushButton_4, 1, 2, 1, 1);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 1, 1, 1, 1);

        textBrowser_2 = new QTextBrowser(tab_3);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_3->addWidget(textBrowser_2, 0, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_9 = new QGridLayout(tab_8);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_12 = new QPushButton(tab_8);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setAutoDefault(true);

        gridLayout_9->addWidget(pushButton_12, 3, 0, 1, 1);

        pushButton_11 = new QPushButton(tab_8);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setAutoDefault(true);

        gridLayout_9->addWidget(pushButton_11, 3, 1, 1, 1);

        textBrowser_7 = new QTextBrowser(tab_8);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));

        gridLayout_9->addWidget(textBrowser_7, 0, 0, 2, 2);

        lineEdit_7 = new QLineEdit(tab_8);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_9->addWidget(lineEdit_7, 2, 0, 1, 2);

        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_10 = new QGridLayout(tab_9);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        textBrowser_8 = new QTextBrowser(tab_9);
        textBrowser_8->setObjectName(QStringLiteral("textBrowser_8"));

        gridLayout_10->addWidget(textBrowser_8, 0, 0, 1, 2);

        lineEdit_8 = new QLineEdit(tab_9);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_10->addWidget(lineEdit_8, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(tab_9);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setAutoDefault(true);

        gridLayout_10->addWidget(pushButton_13, 1, 1, 1, 1);

        lineEdit_9 = new QLineEdit(tab_9);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_10->addWidget(lineEdit_9, 2, 0, 1, 1);

        pushButton_14 = new QPushButton(tab_9);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setAutoDefault(true);

        gridLayout_10->addWidget(pushButton_14, 2, 1, 1, 1);

        tabWidget->addTab(tab_9, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);

        stackedWidget_3->addWidget(stackedWidget_3Page1);
        stackedWidget_3Page2 = new QWidget();
        stackedWidget_3Page2->setObjectName(QStringLiteral("stackedWidget_3Page2"));
        gridLayout_11 = new QGridLayout(stackedWidget_3Page2);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        tabWidget_2 = new QTabWidget(stackedWidget_3Page2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_13 = new QGridLayout(tab_4);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        textBrowser_9 = new QTextBrowser(tab_4);
        textBrowser_9->setObjectName(QStringLiteral("textBrowser_9"));

        gridLayout_13->addWidget(textBrowser_9, 0, 0, 1, 1);

        pushButton_mostarEdificios = new QPushButton(tab_4);
        pushButton_mostarEdificios->setObjectName(QStringLiteral("pushButton_mostarEdificios"));
        pushButton_mostarEdificios->setAutoDefault(true);

        gridLayout_13->addWidget(pushButton_mostarEdificios, 1, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        gridLayout = new QGridLayout(tab_10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_4 = new QLineEdit(tab_10);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 0, 0, 1, 1);

        textBrowser_5 = new QTextBrowser(tab_10);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout->addWidget(textBrowser_5, 0, 1, 3, 1);

        lineEdit_5 = new QLineEdit(tab_10);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(tab_10);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout->addWidget(pushButton_8, 2, 0, 1, 1);

        tabWidget_2->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        gridLayout_7 = new QGridLayout(tab_11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        comboBox_3 = new QComboBox(tab_11);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_7->addWidget(comboBox_3, 0, 0, 1, 1);

        label_5 = new QLabel(tab_11);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_7->addWidget(label_5, 0, 1, 1, 1);

        comboBox_4 = new QComboBox(tab_11);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_7->addWidget(comboBox_4, 0, 2, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_11);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_7->addWidget(textBrowser_6, 0, 3, 3, 1);

        lineEdit_6 = new QLineEdit(tab_11);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_7->addWidget(lineEdit_6, 1, 0, 1, 3);

        pushButton_9 = new QPushButton(tab_11);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_9, 2, 1, 1, 2);

        tabWidget_2->addTab(tab_11, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_8 = new QGridLayout(tab_5);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_8->addWidget(textBrowser_3, 0, 0, 1, 3);

        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_8->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(tab_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_8->addWidget(lineEdit_3, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_5, 1, 2, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_5 = new QGridLayout(tab_7);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textBrowser_4 = new QTextBrowser(tab_7);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_5->addWidget(textBrowser_4, 1, 0, 1, 3);

        comboBox_2 = new QComboBox(tab_7);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_5->addWidget(comboBox_2, 0, 2, 1, 1);

        comboBox = new QComboBox(tab_7);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_5->addWidget(comboBox, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(tab_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_7, 2, 0, 1, 1);

        label_4 = new QLabel(tab_7);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 0, 1, 1, 1);

        tabWidget_2->addTab(tab_7, QString());

        gridLayout_11->addWidget(tabWidget_2, 0, 0, 1, 1);

        stackedWidget_3->addWidget(stackedWidget_3Page2);

        gridLayout_12->addWidget(stackedWidget_3, 0, 0, 1, 4);

        pushButton = new QPushButton(MenuMapa);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout_12->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_16 = new QPushButton(MenuMapa);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_12->addWidget(pushButton_16, 1, 2, 1, 1);


        retranslateUi(MenuMapa);

        stackedWidget_3->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuMapa);
    } // setupUi

    void retranslateUi(QWidget *MenuMapa)
    {
        MenuMapa->setWindowTitle(QApplication::translate("MenuMapa", "Menu Mapa", nullptr));
        pushButton_2->setText(QApplication::translate("MenuMapa", "Crear Mapa", nullptr));
        label_2->setText(QApplication::translate("MenuMapa", "No. Edificios:", nullptr));
        pushButton_10->setText(QApplication::translate("MenuMapa", "Agregar Nuevo Enlace", nullptr));
        pushButton_6->setText(QApplication::translate("MenuMapa", "Agregar Nuevo Edificio", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuMapa", "Crear", nullptr));
        pushButton_3->setText(QApplication::translate("MenuMapa", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuMapa", "Mostrar", nullptr));
        pushButton_4->setText(QApplication::translate("MenuMapa", "Buscar", nullptr));
        label->setText(QApplication::translate("MenuMapa", "Edificio:", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MenuMapa", "C\303\263digo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuMapa", "Buscar", nullptr));
        pushButton_12->setText(QApplication::translate("MenuMapa", "Profundidad", nullptr));
        pushButton_11->setText(QApplication::translate("MenuMapa", "Anchura", nullptr));
        lineEdit_7->setPlaceholderText(QApplication::translate("MenuMapa", "Origen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MenuMapa", "Recorridos", nullptr));
        lineEdit_8->setPlaceholderText(QApplication::translate("MenuMapa", "Origen", nullptr));
        pushButton_13->setText(QApplication::translate("MenuMapa", "Anchura", nullptr));
        lineEdit_9->setPlaceholderText(QApplication::translate("MenuMapa", "Destino", nullptr));
        pushButton_14->setText(QApplication::translate("MenuMapa", "Profundiad", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MenuMapa", "Rutas", nullptr));
        pushButton_mostarEdificios->setText(QApplication::translate("MenuMapa", "Mostrar", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MenuMapa", "Mostrar Edificios", nullptr));
        lineEdit_4->setPlaceholderText(QApplication::translate("MenuMapa", "C\303\263digo:", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("MenuMapa", "Nombre:", nullptr));
        pushButton_8->setText(QApplication::translate("MenuMapa", "Modificar", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QApplication::translate("MenuMapa", "Modificar Edificio", nullptr));
        label_5->setText(QApplication::translate("MenuMapa", "->", nullptr));
        lineEdit_6->setPlaceholderText(QApplication::translate("MenuMapa", "Distancia", nullptr));
        pushButton_9->setText(QApplication::translate("MenuMapa", "Modificar", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QApplication::translate("MenuMapa", "Modificar Camino", nullptr));
        label_3->setText(QApplication::translate("MenuMapa", "Edificio:", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("MenuMapa", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuMapa", "Eliminar", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MenuMapa", "Eliminar Edificio", nullptr));
        pushButton_7->setText(QApplication::translate("MenuMapa", "Eliminar", nullptr));
        label_4->setText(QApplication::translate("MenuMapa", "                    ->", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MenuMapa", "Eliminar Camino", nullptr));
        pushButton->setText(QApplication::translate("MenuMapa", "Regresar", nullptr));
        pushButton_16->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuMapa: public Ui_MenuMapa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUMAPA_H
