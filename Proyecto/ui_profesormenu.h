/********************************************************************************
** Form generated from reading UI file 'profesormenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFESORMENU_H
#define UI_PROFESORMENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfesorMenu
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ProfesorMenu)
    {
        if (ProfesorMenu->objectName().isEmpty())
            ProfesorMenu->setObjectName(QStringLiteral("ProfesorMenu"));
        ProfesorMenu->resize(263, 178);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/42912.png"), QSize(), QIcon::Normal, QIcon::Off);
        ProfesorMenu->setWindowIcon(icon);
        gridLayout = new QGridLayout(ProfesorMenu);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(ProfesorMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(ProfesorMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(ProfesorMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        QWidget::setTabOrder(pushButton, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(ProfesorMenu);

        QMetaObject::connectSlotsByName(ProfesorMenu);
    } // setupUi

    void retranslateUi(QWidget *ProfesorMenu)
    {
        ProfesorMenu->setWindowTitle(QApplication::translate("ProfesorMenu", "Profesor", nullptr));
        pushButton->setText(QApplication::translate("ProfesorMenu", "Disponibilidad", nullptr));
        pushButton_2->setText(QApplication::translate("ProfesorMenu", "Salir", nullptr));
        pushButton_3->setText(QApplication::translate("ProfesorMenu", "Oferta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfesorMenu: public Ui_ProfesorMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFESORMENU_H
