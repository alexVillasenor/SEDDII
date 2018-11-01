/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName(QStringLiteral("LogIn"));
        LogIn->resize(232, 146);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/88468b74-d831-43af-80f0-69b18fcb7701.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        LogIn->setWindowIcon(icon);
        centralWidget = new QWidget(LogIn);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        LogIn->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LogIn);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 232, 21));
        LogIn->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LogIn);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LogIn->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LogIn);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LogIn->setStatusBar(statusBar);

        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QMainWindow *LogIn)
    {
        LogIn->setWindowTitle(QApplication::translate("LogIn", "LogIn", nullptr));
        label->setText(QApplication::translate("LogIn", "Usuario", nullptr));
        label_2->setText(QApplication::translate("LogIn", "Contrase\303\261a", nullptr));
        pushButton->setText(QApplication::translate("LogIn", "Log In", nullptr));
        pushButton_2->setText(QApplication::translate("LogIn", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
