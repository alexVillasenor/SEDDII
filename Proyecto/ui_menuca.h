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
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;

    void setupUi(QWidget *MenuCA)
    {
        if (MenuCA->objectName().isEmpty())
            MenuCA->setObjectName(QStringLiteral("MenuCA"));
        MenuCA->resize(284, 187);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuCA->setWindowIcon(icon);
        MenuCA->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(MenuCA);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(MenuCA);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 6, 0, 1, 1);

        pushButton = new QPushButton(MenuCA);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(MenuCA);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(MenuCA);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setAutoDefault(true);

        gridLayout->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(MenuCA);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setAutoDefault(true);

        gridLayout->addWidget(pushButton_5, 5, 0, 1, 1);

        label = new QLabel(MenuCA);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        QWidget::setTabOrder(pushButton, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_2);

        retranslateUi(MenuCA);

        QMetaObject::connectSlotsByName(MenuCA);
    } // setupUi

    void retranslateUi(QWidget *MenuCA)
    {
        MenuCA->setWindowTitle(QApplication::translate("MenuCA", "Coordinador Academico", nullptr));
        pushButton_2->setText(QApplication::translate("MenuCA", "Salir", nullptr));
        pushButton->setText(QApplication::translate("MenuCA", "Profesores", nullptr));
        pushButton_3->setText(QApplication::translate("MenuCA", "Asignaturas", nullptr));
        pushButton_4->setText(QApplication::translate("MenuCA", "Disponibilidad", nullptr));
        pushButton_5->setText(QApplication::translate("MenuCA", "Oferta", nullptr));
        label->setText(QApplication::translate("MenuCA", "\302\277Que desea hacer?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuCA: public Ui_MenuCA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUCA_H
