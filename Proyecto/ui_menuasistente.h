/********************************************************************************
** Form generated from reading UI file 'menuasistente.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUASISTENTE_H
#define UI_MENUASISTENTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuAsistente
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MenuAsistente)
    {
        if (MenuAsistente->objectName().isEmpty())
            MenuAsistente->setObjectName(QStringLiteral("MenuAsistente"));
        MenuAsistente->resize(323, 228);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/1f720a0f-1f03-4299-9a11-2e83b4a61bcb.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MenuAsistente->setWindowIcon(icon);
        gridLayout = new QGridLayout(MenuAsistente);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_3 = new QPushButton(MenuAsistente);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton = new QPushButton(MenuAsistente);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(MenuAsistente);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);


        retranslateUi(MenuAsistente);

        QMetaObject::connectSlotsByName(MenuAsistente);
    } // setupUi

    void retranslateUi(QWidget *MenuAsistente)
    {
        MenuAsistente->setWindowTitle(QApplication::translate("MenuAsistente", "Menu Asistente", nullptr));
        pushButton_3->setText(QApplication::translate("MenuAsistente", "Salir", nullptr));
        pushButton->setText(QApplication::translate("MenuAsistente", "Oferta", nullptr));
        pushButton_2->setText(QApplication::translate("MenuAsistente", "Disponibilidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuAsistente: public Ui_MenuAsistente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUASISTENTE_H
