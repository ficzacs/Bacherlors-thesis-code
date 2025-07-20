/********************************************************************************
** Form generated from reading UI file 'load_mode.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_MODE_H
#define UI_LOAD_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Load_mode
{
public:
    QPushButton *Mapload_button;
    QPushButton *Mapload2_button;
    QPushButton *Mapload3_button;

    void setupUi(QDialog *Load_mode)
    {
        if (Load_mode->objectName().isEmpty())
            Load_mode->setObjectName("Load_mode");
        Load_mode->resize(400, 300);
        Mapload_button = new QPushButton(Load_mode);
        Mapload_button->setObjectName("Mapload_button");
        Mapload_button->setGeometry(QRect(30, 230, 83, 29));
        Mapload2_button = new QPushButton(Load_mode);
        Mapload2_button->setObjectName("Mapload2_button");
        Mapload2_button->setGeometry(QRect(140, 230, 83, 29));
        Mapload3_button = new QPushButton(Load_mode);
        Mapload3_button->setObjectName("Mapload3_button");
        Mapload3_button->setGeometry(QRect(270, 230, 83, 29));

        retranslateUi(Load_mode);

        QMetaObject::connectSlotsByName(Load_mode);
    } // setupUi

    void retranslateUi(QDialog *Load_mode)
    {
        Load_mode->setWindowTitle(QCoreApplication::translate("Load_mode", "Dialog", nullptr));
        Mapload_button->setText(QCoreApplication::translate("Load_mode", "Load", nullptr));
        Mapload2_button->setText(QCoreApplication::translate("Load_mode", "Load", nullptr));
        Mapload3_button->setText(QCoreApplication::translate("Load_mode", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Load_mode: public Ui_Load_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_MODE_H
