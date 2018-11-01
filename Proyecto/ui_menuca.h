/********************************************************************************
** Form generated from reading UI file 'menuca.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUCA_H
#define UI_MENUCA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuCA
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *MenuCA)
    {
        if (MenuCA->objectName().isEmpty())
            MenuCA->setObjectName(QStringLiteral("MenuCA"));
        MenuCA->resize(110, 89);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuCA->setWindowIcon(icon);
        MenuCA->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(MenuCA);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuCA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(MenuCA);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        label = new QLabel(MenuCA);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(MenuCA);

        QMetaObject::connectSlotsByName(MenuCA);
    } // setupUi

    void retranslateUi(QWidget *MenuCA)
    {
        MenuCA->setWindowTitle(QApplication::translate("MenuCA", "Coordinador Academico", nullptr));
        pushButton->setText(QApplication::translate("MenuCA", "Profesores", nullptr));
        pushButton_2->setText(QApplication::translate("MenuCA", "Salir", nullptr));
        label->setText(QApplication::translate("MenuCA", "\302\277Que desea hacer?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCA: public Ui_MenuCA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCA_H
