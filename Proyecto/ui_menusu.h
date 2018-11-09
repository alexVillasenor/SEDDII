/********************************************************************************
** Form generated from reading UI file 'menusu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUSU_H
#define UI_MENUSU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuSU
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_10;

    void setupUi(QWidget *MenuSU)
    {
        if (MenuSU->objectName().isEmpty())
            MenuSU->setObjectName(QStringLiteral("MenuSU"));
        MenuSU->resize(347, 333);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/4ec047f471eefe7fb35ff00de2ce83a9.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuSU->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuSU);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_8 = new QPushButton(MenuSU);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setAutoDefault(true);

        gridLayout->addWidget(pushButton_8, 4, 0, 1, 1);

        pushButton_6 = new QPushButton(MenuSU);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setAutoDefault(true);

        gridLayout->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(MenuSU);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout->addWidget(pushButton_4, 6, 0, 1, 2);

        pushButton_9 = new QPushButton(MenuSU);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setAutoDefault(true);

        gridLayout->addWidget(pushButton_9, 4, 1, 1, 1);

        label_2 = new QLabel(MenuSU);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        pushButton = new QPushButton(MenuSU);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(MenuSU);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setAutoDefault(true);

        gridLayout->addWidget(pushButton_7, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(MenuSU);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(MenuSU);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(MenuSU);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_10 = new QPushButton(MenuSU);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setAutoDefault(true);

        gridLayout->addWidget(pushButton_10, 5, 0, 1, 1);

        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_10);
        QWidget::setTabOrder(pushButton_10, pushButton_4);

        retranslateUi(MenuSU);

        QMetaObject::connectSlotsByName(MenuSU);
    } // setupUi

    void retranslateUi(QWidget *MenuSU)
    {
        MenuSU->setWindowTitle(QApplication::translate("MenuSU", "Menu Administrador", nullptr));
        pushButton_8->setText(QApplication::translate("MenuSU", "Mapa", nullptr));
        pushButton_6->setText(QApplication::translate("MenuSU", "Grupo", nullptr));
        pushButton_4->setText(QApplication::translate("MenuSU", "Salir", nullptr));
        pushButton_9->setText(QApplication::translate("MenuSU", "Disponibilidad", nullptr));
        label_2->setText(QApplication::translate("MenuSU", "Seleccion a que menu desea ir", nullptr));
        pushButton->setText(QApplication::translate("MenuSU", "Usuario", nullptr));
        pushButton_7->setText(QApplication::translate("MenuSU", "Asignatura", nullptr));
        pushButton_5->setText(QApplication::translate("MenuSU", "Periodo", nullptr));
        pushButton_2->setText(QApplication::translate("MenuSU", "Perfil", nullptr));
        pushButton_3->setText(QApplication::translate("MenuSU", "Profesor", nullptr));
        pushButton_10->setText(QApplication::translate("MenuSU", "Oferta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuSU: public Ui_MenuSU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUSU_H
