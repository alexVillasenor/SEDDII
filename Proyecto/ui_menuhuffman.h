/********************************************************************************
** Form generated from reading UI file 'menuhuffman.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUHUFFMAN_H
#define UI_MENUHUFFMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuHuffman
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MenuHuffman)
    {
        if (MenuHuffman->objectName().isEmpty())
            MenuHuffman->setObjectName(QStringLiteral("MenuHuffman"));
        MenuHuffman->resize(512, 386);
        gridLayout = new QGridLayout(MenuHuffman);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MenuHuffman);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(MenuHuffman);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(MenuHuffman);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setAutoDefault(true);

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        textBrowser = new QTextBrowser(MenuHuffman);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 3);


        retranslateUi(MenuHuffman);

        QMetaObject::connectSlotsByName(MenuHuffman);
    } // setupUi

    void retranslateUi(QWidget *MenuHuffman)
    {
        MenuHuffman->setWindowTitle(QApplication::translate("MenuHuffman", "Menu Huffman", nullptr));
        pushButton->setText(QApplication::translate("MenuHuffman", "Comprimir", nullptr));
        pushButton_2->setText(QApplication::translate("MenuHuffman", "Descomprimir", nullptr));
        pushButton_3->setText(QApplication::translate("MenuHuffman", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuHuffman: public Ui_MenuHuffman {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUHUFFMAN_H
