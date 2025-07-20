/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGridLayout *buttons_layout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *tutoria_button;
    QPushButton *load_button;
    QPushButton *sim_button;
    QPushButton *exit_button;
    QPushButton *restart_button;
    QVBoxLayout *verticalLayout_4;
    QScrollBar *Delay_input_data;
    QLabel *Delay_text;
    QCheckBox *Delay_mode;
    QVBoxLayout *verticalLayout;
    QRadioButton *Ex_rand_walk;
    QRadioButton *Ex_BFS;
    QRadioButton *Ex_DFS;
    QRadioButton *Ex_rand_walkmem;
    QRadioButton *Ex_A_star;
    QPushButton *explore_button;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *Pf_BFS;
    QRadioButton *Pf_DFS;
    QSpacerItem *verticalSpacer;
    QPushButton *pathfind_button;
    QVBoxLayout *verticalLayout_5;
    QLabel *Obstacle_text;
    QSpinBox *obstacle_input_data;
    QPushButton *Obstacle_generate_button;
    QVBoxLayout *verticalLayout_7;
    QLabel *explore_text;
    QTextEdit *output_statistics;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(895, 867);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttons_layout = new QGridLayout();
        buttons_layout->setObjectName("buttons_layout");
        buttons_layout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);

        horizontalLayout->addLayout(buttons_layout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        tutoria_button = new QPushButton(centralwidget);
        tutoria_button->setObjectName("tutoria_button");

        verticalLayout_3->addWidget(tutoria_button);

        load_button = new QPushButton(centralwidget);
        load_button->setObjectName("load_button");

        verticalLayout_3->addWidget(load_button);

        sim_button = new QPushButton(centralwidget);
        sim_button->setObjectName("sim_button");

        verticalLayout_3->addWidget(sim_button);

        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName("exit_button");
        sizePolicy.setHeightForWidth(exit_button->sizePolicy().hasHeightForWidth());
        exit_button->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(exit_button);

        restart_button = new QPushButton(centralwidget);
        restart_button->setObjectName("restart_button");
        sizePolicy.setHeightForWidth(restart_button->sizePolicy().hasHeightForWidth());
        restart_button->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(restart_button);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        Delay_input_data = new QScrollBar(centralwidget);
        Delay_input_data->setObjectName("Delay_input_data");
        Delay_input_data->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        Delay_input_data->setMinimum(0);
        Delay_input_data->setMaximum(100);
        Delay_input_data->setOrientation(Qt::Orientation::Horizontal);
        Delay_input_data->setInvertedAppearance(true);
        Delay_input_data->setInvertedControls(true);

        verticalLayout_4->addWidget(Delay_input_data);

        Delay_text = new QLabel(centralwidget);
        Delay_text->setObjectName("Delay_text");

        verticalLayout_4->addWidget(Delay_text);

        Delay_mode = new QCheckBox(centralwidget);
        Delay_mode->setObjectName("Delay_mode");

        verticalLayout_4->addWidget(Delay_mode);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Ex_rand_walk = new QRadioButton(centralwidget);
        Ex_rand_walk->setObjectName("Ex_rand_walk");
        sizePolicy.setHeightForWidth(Ex_rand_walk->sizePolicy().hasHeightForWidth());
        Ex_rand_walk->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Ex_rand_walk);

        Ex_BFS = new QRadioButton(centralwidget);
        Ex_BFS->setObjectName("Ex_BFS");

        verticalLayout->addWidget(Ex_BFS);

        Ex_DFS = new QRadioButton(centralwidget);
        Ex_DFS->setObjectName("Ex_DFS");
        sizePolicy.setHeightForWidth(Ex_DFS->sizePolicy().hasHeightForWidth());
        Ex_DFS->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Ex_DFS);

        Ex_rand_walkmem = new QRadioButton(centralwidget);
        Ex_rand_walkmem->setObjectName("Ex_rand_walkmem");
        sizePolicy.setHeightForWidth(Ex_rand_walkmem->sizePolicy().hasHeightForWidth());
        Ex_rand_walkmem->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Ex_rand_walkmem);

        Ex_A_star = new QRadioButton(centralwidget);
        Ex_A_star->setObjectName("Ex_A_star");

        verticalLayout->addWidget(Ex_A_star);

        explore_button = new QPushButton(centralwidget);
        explore_button->setObjectName("explore_button");
        sizePolicy.setHeightForWidth(explore_button->sizePolicy().hasHeightForWidth());
        explore_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(explore_button);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        Pf_BFS = new QRadioButton(centralwidget);
        Pf_BFS->setObjectName("Pf_BFS");

        verticalLayout_2->addWidget(Pf_BFS);

        Pf_DFS = new QRadioButton(centralwidget);
        Pf_DFS->setObjectName("Pf_DFS");

        verticalLayout_2->addWidget(Pf_DFS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pathfind_button = new QPushButton(centralwidget);
        pathfind_button->setObjectName("pathfind_button");

        verticalLayout_2->addWidget(pathfind_button);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        Obstacle_text = new QLabel(centralwidget);
        Obstacle_text->setObjectName("Obstacle_text");
        sizePolicy.setHeightForWidth(Obstacle_text->sizePolicy().hasHeightForWidth());
        Obstacle_text->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(Obstacle_text);

        obstacle_input_data = new QSpinBox(centralwidget);
        obstacle_input_data->setObjectName("obstacle_input_data");
        sizePolicy.setHeightForWidth(obstacle_input_data->sizePolicy().hasHeightForWidth());
        obstacle_input_data->setSizePolicy(sizePolicy);
        obstacle_input_data->setMaximum(398);

        verticalLayout_5->addWidget(obstacle_input_data);

        Obstacle_generate_button = new QPushButton(centralwidget);
        Obstacle_generate_button->setObjectName("Obstacle_generate_button");
        sizePolicy.setHeightForWidth(Obstacle_generate_button->sizePolicy().hasHeightForWidth());
        Obstacle_generate_button->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(Obstacle_generate_button);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        explore_text = new QLabel(centralwidget);
        explore_text->setObjectName("explore_text");
        sizePolicy.setHeightForWidth(explore_text->sizePolicy().hasHeightForWidth());
        explore_text->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(explore_text);

        output_statistics = new QTextEdit(centralwidget);
        output_statistics->setObjectName("output_statistics");
        sizePolicy.setHeightForWidth(output_statistics->sizePolicy().hasHeightForWidth());
        output_statistics->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(output_statistics);


        verticalLayout_6->addLayout(verticalLayout_7);


        horizontalLayout->addLayout(verticalLayout_6);


        horizontalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 895, 25));
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tutoria_button->setText(QCoreApplication::translate("MainWindow", "\303\232tmutat\303\263", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "Load maps", nullptr));
        sim_button->setText(QCoreApplication::translate("MainWindow", "Simulation mode", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        restart_button->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        Delay_text->setText(QCoreApplication::translate("MainWindow", "Delay:", nullptr));
        Delay_mode->setText(QCoreApplication::translate("MainWindow", "No delay mode", nullptr));
        Ex_rand_walk->setText(QCoreApplication::translate("MainWindow", "Random walk", nullptr));
        Ex_BFS->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        Ex_DFS->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        Ex_rand_walkmem->setText(QCoreApplication::translate("MainWindow", "Greedy BFS", nullptr));
        Ex_A_star->setText(QCoreApplication::translate("MainWindow", "A* algorithm", nullptr));
        explore_button->setText(QCoreApplication::translate("MainWindow", "Explore", nullptr));
        Pf_BFS->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        Pf_DFS->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        pathfind_button->setText(QCoreApplication::translate("MainWindow", "Find path", nullptr));
        Obstacle_text->setText(QCoreApplication::translate("MainWindow", "Number of obstacles:", nullptr));
        Obstacle_generate_button->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        explore_text->setText(QCoreApplication::translate("MainWindow", "Explore the graph:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
