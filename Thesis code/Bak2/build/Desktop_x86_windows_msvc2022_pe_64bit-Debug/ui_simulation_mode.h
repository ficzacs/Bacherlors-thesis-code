/********************************************************************************
** Form generated from reading UI file 'simulation_mode.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_MODE_H
#define UI_SIMULATION_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Simulation_mode
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *info_label_5;
    QSpinBox *obs_num_box;
    QCheckBox *delay_checkbox;
    QHBoxLayout *horizontalLayout;
    QLabel *info_label2;
    QSpinBox *sim_nums_box;
    QPushButton *sim_init_button;
    QVBoxLayout *verticalLayout;
    QRadioButton *explore_mode_1;
    QRadioButton *explore_mode_2;
    QRadioButton *explore_mode_3;
    QRadioButton *explore_mode_4;
    QLabel *info_label3;
    QTextEdit *out_text_all;
    QVBoxLayout *verticalLayout_2;
    QLabel *info_label4;
    QTextEdit *out_text_final;

    void setupUi(QDialog *Simulation_mode)
    {
        if (Simulation_mode->objectName().isEmpty())
            Simulation_mode->setObjectName("Simulation_mode");
        Simulation_mode->resize(557, 523);
        verticalLayout_3 = new QVBoxLayout(Simulation_mode);
        verticalLayout_3->setObjectName("verticalLayout_3");
        info_label_5 = new QLabel(Simulation_mode);
        info_label_5->setObjectName("info_label_5");

        verticalLayout_3->addWidget(info_label_5);

        obs_num_box = new QSpinBox(Simulation_mode);
        obs_num_box->setObjectName("obs_num_box");
        obs_num_box->setMaximum(300);

        verticalLayout_3->addWidget(obs_num_box);

        delay_checkbox = new QCheckBox(Simulation_mode);
        delay_checkbox->setObjectName("delay_checkbox");

        verticalLayout_3->addWidget(delay_checkbox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        info_label2 = new QLabel(Simulation_mode);
        info_label2->setObjectName("info_label2");

        horizontalLayout->addWidget(info_label2);

        sim_nums_box = new QSpinBox(Simulation_mode);
        sim_nums_box->setObjectName("sim_nums_box");
        sim_nums_box->setMaximum(100);

        horizontalLayout->addWidget(sim_nums_box);

        sim_init_button = new QPushButton(Simulation_mode);
        sim_init_button->setObjectName("sim_init_button");

        horizontalLayout->addWidget(sim_init_button);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        explore_mode_1 = new QRadioButton(Simulation_mode);
        explore_mode_1->setObjectName("explore_mode_1");

        verticalLayout->addWidget(explore_mode_1);

        explore_mode_2 = new QRadioButton(Simulation_mode);
        explore_mode_2->setObjectName("explore_mode_2");

        verticalLayout->addWidget(explore_mode_2);

        explore_mode_3 = new QRadioButton(Simulation_mode);
        explore_mode_3->setObjectName("explore_mode_3");

        verticalLayout->addWidget(explore_mode_3);

        explore_mode_4 = new QRadioButton(Simulation_mode);
        explore_mode_4->setObjectName("explore_mode_4");

        verticalLayout->addWidget(explore_mode_4);

        info_label3 = new QLabel(Simulation_mode);
        info_label3->setObjectName("info_label3");

        verticalLayout->addWidget(info_label3);

        out_text_all = new QTextEdit(Simulation_mode);
        out_text_all->setObjectName("out_text_all");

        verticalLayout->addWidget(out_text_all);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        info_label4 = new QLabel(Simulation_mode);
        info_label4->setObjectName("info_label4");

        verticalLayout_2->addWidget(info_label4);

        out_text_final = new QTextEdit(Simulation_mode);
        out_text_final->setObjectName("out_text_final");

        verticalLayout_2->addWidget(out_text_final);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Simulation_mode);

        QMetaObject::connectSlotsByName(Simulation_mode);
    } // setupUi

    void retranslateUi(QDialog *Simulation_mode)
    {
        Simulation_mode->setWindowTitle(QCoreApplication::translate("Simulation_mode", "Dialog", nullptr));
        info_label_5->setText(QCoreApplication::translate("Simulation_mode", "Number of obstacles:", nullptr));
        delay_checkbox->setText(QCoreApplication::translate("Simulation_mode", "No delay mode", nullptr));
        info_label2->setText(QCoreApplication::translate("Simulation_mode", "Number of simulations:", nullptr));
        sim_init_button->setText(QCoreApplication::translate("Simulation_mode", "Simulate", nullptr));
        explore_mode_1->setText(QCoreApplication::translate("Simulation_mode", "Random", nullptr));
        explore_mode_2->setText(QCoreApplication::translate("Simulation_mode", "Random w mem", nullptr));
        explore_mode_3->setText(QCoreApplication::translate("Simulation_mode", "DFS", nullptr));
        explore_mode_4->setText(QCoreApplication::translate("Simulation_mode", "BFS", nullptr));
        info_label3->setText(QCoreApplication::translate("Simulation_mode", "Data of each: ", nullptr));
        info_label4->setText(QCoreApplication::translate("Simulation_mode", "Final data:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulation_mode: public Ui_Simulation_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_MODE_H
