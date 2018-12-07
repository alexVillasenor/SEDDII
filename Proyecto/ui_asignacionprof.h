/********************************************************************************
** Form generated from reading UI file 'asignacionprof.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASIGNACIONPROF_H
#define UI_ASIGNACIONPROF_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AsignacionProf
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *AsignacionProf)
    {
        if (AsignacionProf->objectName().isEmpty())
            AsignacionProf->setObjectName(QStringLiteral("AsignacionProf"));
        AsignacionProf->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral("../icons/lentejas-con-chorizo-830.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        AsignacionProf->setWindowIcon(icon);
        gridLayout = new QGridLayout(AsignacionProf);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(AsignacionProf);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(AsignacionProf);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 2, 1, 1);

        label = new QLabel(AsignacionProf);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        textBrowser = new QTextBrowser(AsignacionProf);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 3);

        pushButton = new QPushButton(AsignacionProf);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setAutoDefault(true);

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(AsignacionProf);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setAutoDefault(true);

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);


        retranslateUi(AsignacionProf);

        QMetaObject::connectSlotsByName(AsignacionProf);
    } // setupUi

    void retranslateUi(QWidget *AsignacionProf)
    {
        AsignacionProf->setWindowTitle(QApplication::translate("AsignacionProf", "Asignacion de profesores", nullptr));
        label->setText(QApplication::translate("AsignacionProf", "                  ->", nullptr));
        pushButton->setText(QApplication::translate("AsignacionProf", "Asignar", nullptr));
        pushButton_2->setText(QApplication::translate("AsignacionProf", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AsignacionProf: public Ui_AsignacionProf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASIGNACIONPROF_H
