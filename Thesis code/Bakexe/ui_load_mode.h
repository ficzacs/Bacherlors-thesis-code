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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Load_mode
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QPushButton *Mapload_button;
    QPushButton *Mapload2_button;
    QPushButton *Mapload3_button;

    void setupUi(QDialog *Load_mode)
    {
        if (Load_mode->objectName().isEmpty())
            Load_mode->setObjectName("Load_mode");
        Load_mode->resize(489, 235);
        widget = new QWidget(Load_mode);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 30, 441, 161));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Mapload_button = new QPushButton(widget);
        Mapload_button->setObjectName("Mapload_button");

        verticalLayout->addWidget(Mapload_button);

        Mapload2_button = new QPushButton(widget);
        Mapload2_button->setObjectName("Mapload2_button");

        verticalLayout->addWidget(Mapload2_button);

        Mapload3_button = new QPushButton(widget);
        Mapload3_button->setObjectName("Mapload3_button");

        verticalLayout->addWidget(Mapload3_button);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Load_mode);

        QMetaObject::connectSlotsByName(Load_mode);
    } // setupUi

    void retranslateUi(QDialog *Load_mode)
    {
        Load_mode->setWindowTitle(QCoreApplication::translate("Load_mode", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Load_mode", "Preset 1: Labyrinth like map:", nullptr));
        label_2->setText(QCoreApplication::translate("Load_mode", "Preset 2: Map with an obstacle in the middle:", nullptr));
        label_3->setText(QCoreApplication::translate("Load_mode", "Preset 3: Room like map:", nullptr));
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
