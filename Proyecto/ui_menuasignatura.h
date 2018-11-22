/********************************************************************************
** Form generated from reading UI file 'menuasignatura.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUASIGNATURA_H
#define UI_MENUASIGNATURA_H

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

class Ui_MenuAsignatura
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QWidget *tab_9;
    QGridLayout *gridLayout_10;
    QTextBrowser *textBrowser_8;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_10;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_10;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QTextBrowser *textBrowser_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QLabel *label_14;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_3;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_6;
    QTextBrowser *textBrowser_4;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_6;
    QWidget *tab_7;
    QGridLayout *gridLayout_7;
    QTextBrowser *textBrowser_5;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_7;
    QWidget *tab_8;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_9;
    QTextBrowser *textBrowser_7;

    void setupUi(QWidget *MenuAsignatura)
    {
        if (MenuAsignatura->objectName().isEmpty())
            MenuAsignatura->setObjectName(QStringLiteral("MenuAsignatura"));
        MenuAsignatura->resize(514, 313);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/icono-titulacion.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuAsignatura->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuAsignatura);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuAsignatura);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(MenuAsignatura);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setAutoDefault(true);

        gridLayout->addWidget(pushButton_11, 1, 2, 1, 1);

        tabWidget = new QTabWidget(MenuAsignatura);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout_2->addWidget(pushButton_2, 4, 1, 1, 1);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 2, 1, 1);

        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 2, 2, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 3, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);

        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 3, 2, 1, 1);

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
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_10 = new QGridLayout(tab_9);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        textBrowser_8 = new QTextBrowser(tab_9);
        textBrowser_8->setObjectName(QStringLiteral("textBrowser_8"));

        gridLayout_10->addWidget(textBrowser_8, 0, 0, 1, 3);

        label_12 = new QLabel(tab_9);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_10->addWidget(label_12, 1, 0, 1, 1);

        lineEdit_12 = new QLineEdit(tab_9);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout_10->addWidget(lineEdit_12, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(tab_9);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setAutoDefault(true);

        gridLayout_10->addWidget(pushButton_10, 1, 2, 1, 1);

        tabWidget->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_4->addWidget(lineEdit_4, 1, 1, 1, 1);

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
        pushButton_8 = new QPushButton(tab_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout_8->addWidget(pushButton_8, 5, 0, 1, 2);

        lineEdit_11 = new QLineEdit(tab_4);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout_8->addWidget(lineEdit_11, 3, 1, 1, 1);

        lineEdit_10 = new QLineEdit(tab_4);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_8->addWidget(lineEdit_10, 2, 1, 1, 1);

        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_8->addWidget(label_10, 2, 0, 1, 1);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_8->addWidget(label_11, 3, 0, 1, 1);

        textBrowser_6 = new QTextBrowser(tab_4);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_8->addWidget(textBrowser_6, 0, 2, 6, 1);

        lineEdit_8 = new QLineEdit(tab_4);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout_8->addWidget(lineEdit_8, 0, 1, 1, 1);

        lineEdit_9 = new QLineEdit(tab_4);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_8->addWidget(lineEdit_9, 1, 1, 1, 1);

        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_8->addWidget(label_9, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_8->addWidget(comboBox_2, 4, 1, 1, 1);

        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_8->addWidget(label_14, 4, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textBrowser_3 = new QTextBrowser(tab_5);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_5->addWidget(textBrowser_3, 0, 0, 1, 3);

        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab_5);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout_5->addWidget(lineEdit_5, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout_5->addWidget(pushButton_5, 1, 2, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_6 = new QGridLayout(tab_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        textBrowser_4 = new QTextBrowser(tab_6);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_6->addWidget(textBrowser_4, 0, 0, 1, 3);

        label_6 = new QLabel(tab_6);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_6->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab_6);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_6->addWidget(lineEdit_6, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(tab_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout_6->addWidget(pushButton_6, 1, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_7 = new QGridLayout(tab_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        textBrowser_5 = new QTextBrowser(tab_7);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout_7->addWidget(textBrowser_5, 0, 0, 1, 3);

        label_7 = new QLabel(tab_7);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_7->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_7);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_7->addWidget(lineEdit_7, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(tab_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout_7->addWidget(pushButton_7, 1, 2, 1, 1);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_9 = new QGridLayout(tab_8);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_9 = new QPushButton(tab_8);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setAutoDefault(true);

        gridLayout_9->addWidget(pushButton_9, 0, 0, 1, 1);

        textBrowser_7 = new QTextBrowser(tab_8);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));

        gridLayout_9->addWidget(textBrowser_7, 0, 1, 1, 1);

        tabWidget->addTab(tab_8, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 3);

        QWidget::setTabOrder(tabWidget, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, pushButton_2);
        QWidget::setTabOrder(pushButton_2, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton_3);
        QWidget::setTabOrder(pushButton_3, textBrowser_2);
        QWidget::setTabOrder(textBrowser_2, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton_4);
        QWidget::setTabOrder(pushButton_4, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, pushButton_8);
        QWidget::setTabOrder(pushButton_8, textBrowser_6);
        QWidget::setTabOrder(textBrowser_6, textBrowser_3);
        QWidget::setTabOrder(textBrowser_3, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, pushButton_5);
        QWidget::setTabOrder(pushButton_5, textBrowser_4);
        QWidget::setTabOrder(textBrowser_4, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, pushButton_6);
        QWidget::setTabOrder(pushButton_6, textBrowser_5);
        QWidget::setTabOrder(textBrowser_5, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton);

        retranslateUi(MenuAsignatura);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MenuAsignatura);
    } // setupUi

    void retranslateUi(QWidget *MenuAsignatura)
    {
        MenuAsignatura->setWindowTitle(QApplication::translate("MenuAsignatura", "Menu Asignaturas", nullptr));
        pushButton->setText(QApplication::translate("MenuAsignatura", "Regresar", nullptr));
        pushButton_11->setText(QApplication::translate("MenuAsignatura", "Guardar", nullptr));
        pushButton_2->setText(QApplication::translate("MenuAsignatura", "Crear", nullptr));
        label_3->setText(QApplication::translate("MenuAsignatura", "Creditos:", nullptr));
        label->setText(QApplication::translate("MenuAsignatura", "Nombre:", nullptr));
        label_13->setText(QApplication::translate("MenuAsignatura", "Grado:", nullptr));
        label_2->setText(QApplication::translate("MenuAsignatura", "Programa:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MenuAsignatura", "Primero", nullptr));
        comboBox->setItemText(1, QApplication::translate("MenuAsignatura", "Segundo", nullptr));
        comboBox->setItemText(2, QApplication::translate("MenuAsignatura", "Tercero", nullptr));
        comboBox->setItemText(3, QApplication::translate("MenuAsignatura", "Cuarto", nullptr));
        comboBox->setItemText(4, QApplication::translate("MenuAsignatura", "Quinto", nullptr));
        comboBox->setItemText(5, QApplication::translate("MenuAsignatura", "Sexto", nullptr));
        comboBox->setItemText(6, QApplication::translate("MenuAsignatura", "Septimo", nullptr));
        comboBox->setItemText(7, QApplication::translate("MenuAsignatura", "Octavo", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MenuAsignatura", "Crear", nullptr));
        pushButton_3->setText(QApplication::translate("MenuAsignatura", "Mostrar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MenuAsignatura", "Mostrar", nullptr));
        label_12->setText(QApplication::translate("MenuAsignatura", "Programa:", nullptr));
        pushButton_10->setText(QApplication::translate("MenuAsignatura", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MenuAsignatura", "Buscar Programa", nullptr));
        label_4->setText(QApplication::translate("MenuAsignatura", "C\303\263digo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuAsignatura", "Buscar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MenuAsignatura", "Buscar", nullptr));
        pushButton_8->setText(QApplication::translate("MenuAsignatura", "Modificar", nullptr));
        label_8->setText(QApplication::translate("MenuAsignatura", "C\303\263digo:", nullptr));
        label_10->setText(QApplication::translate("MenuAsignatura", "Programa:", nullptr));
        label_11->setText(QApplication::translate("MenuAsignatura", "Creditos:", nullptr));
        label_9->setText(QApplication::translate("MenuAsignatura", "Nombre:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MenuAsignatura", "Primero", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MenuAsignatura", "Segundo", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MenuAsignatura", "Tercero", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("MenuAsignatura", "Cuarto", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("MenuAsignatura", "Quinto", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("MenuAsignatura", "Sexto", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("MenuAsignatura", "Septimo", nullptr));
        comboBox_2->setItemText(7, QApplication::translate("MenuAsignatura", "Octavo", nullptr));

        label_14->setText(QApplication::translate("MenuAsignatura", "Grado:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MenuAsignatura", "Modificar", nullptr));
        label_5->setText(QApplication::translate("MenuAsignatura", "C\303\263digo", nullptr));
        pushButton_5->setText(QApplication::translate("MenuAsignatura", "Eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MenuAsignatura", "Eliminar", nullptr));
        label_6->setText(QApplication::translate("MenuAsignatura", "C\303\263digo:", nullptr));
        pushButton_6->setText(QApplication::translate("MenuAsignatura", "Desactivar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MenuAsignatura", "Desactivar", nullptr));
        label_7->setText(QApplication::translate("MenuAsignatura", "C\303\263digo:", nullptr));
        pushButton_7->setText(QApplication::translate("MenuAsignatura", "Activar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MenuAsignatura", "Activar", nullptr));
        pushButton_9->setText(QApplication::translate("MenuAsignatura", "Ordenar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MenuAsignatura", "Ordenar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuAsignatura: public Ui_MenuAsignatura {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUASIGNATURA_H
