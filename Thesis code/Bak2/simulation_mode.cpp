#include "simulation_mode.h"
#include "ui_simulation_mode.h"
#include "mainwindow.h"
#include <QRandomGenerator>
#include <QGridLayout>
#include <QIntValidator>
#include <QThread>
#include <QSet>
#include <QQueue>
#include <QMessageBox>
#include <QStack>

Simulation_mode::Simulation_mode(MainWindow *mainWin, QWidget *parent)
    : QDialog(parent), ui(new Ui::Simulation_mode), mainWindow(mainWin)
{
    ui->setupUi(this);
}

Simulation_mode::~Simulation_mode()
{
    delete ui;
}

void Simulation_mode::on_sim_init_button_clicked()
{
    int simulation = ui->sim_nums_box->value();
    double allExp = 0;
    double allStep = 0;
    double allPathLen = 0;

    QString mode = "";

    int explore_mode = 0;
    if(ui->explore_mode_1->isChecked() == true) explore_mode = 1, mode = "RndW";
    if(ui->explore_mode_2->isChecked() == true) explore_mode = 2, mode = "G-BFS";
    if(ui->explore_mode_3->isChecked() == true) explore_mode = 3, mode = "DFS";
    if(ui->explore_mode_4->isChecked() == true) explore_mode = 4, mode = "BFS";
    if(ui->explore_mode_5->isChecked() == true) explore_mode = 5, mode = "A*";


    int obstacles = ui->obs_num_box->value();

    bool delay = !ui->delay_checkbox->isChecked() == true;

    int i = 0;
    while(i < simulation){
        int explored = 0;
        int steps = 0;
        int pathLength = 0;

        mainWindow->restart_buttons();
        mainWindow->initialize_buttons();
        mainWindow->generate_obstacle_buttons(obstacles);

        if(!mainWindow->is_map_valid()){
            ui->out_text_all->append("No path found");
            continue;
        }

        if(explore_mode == 1) mainWindow->explore_randomwalk(explored, steps, false);
        else if(explore_mode == 2) mainWindow->explore_greedy_bfs(explored,steps, false);
        else if(explore_mode == 3) mainWindow->explore_dfs(explored, steps, false);
        else if(explore_mode == 4) mainWindow->explore_bfs(explored, steps, false);
        else if(explore_mode == 5) mainWindow->explore_A_star(explored, steps, false);
        else{
            QMessageBox::warning(this, "Warning", "Choose a mode please.");
            break;
        }

        mainWindow->shortest_path_bfs(pathLength);

        allExp += explored;
        allStep += steps;
        if(pathLength > 0)allPathLen += pathLength;

        if(explore_mode != 5){
        ui->out_text_all->append(mode + "- " + QString::number(i + 1) + " Explored: " + QString::number(explored) + " Steps: " + QString::number(steps) + " Path Length: " + QString::number(pathLength));
        } else {
        ui->out_text_all->append(mode + "- " + QString::number(i + 1) + " Explored: " + QString::number(steps) + " Path Length: " + QString::number(explored));
        }
        if(delay){
        QCoreApplication::processEvents();
        QThread::msleep(100);
        }
        i++;
    }

    allExp = allExp / simulation;
    allStep = allStep / simulation;
    allPathLen = allPathLen / simulation;

    if(explore_mode != 5){
    ui->out_text_final->append(QString::number(simulation) + " " + mode + " Num of obstacles: " +QString::number(obstacles) + " - Average of tiles explored: " + QString::number(allExp) + " Average of steps: " + QString::number(allStep) +  " Average shortest path length: " + QString::number(allPathLen));
    } else {
    ui->out_text_final->append(QString::number(simulation) + " " + mode + " Num of obstacles: " +QString::number(obstacles) + " - Average of tiles explored: " + QString::number(allStep) +  " Average shortest path length: " + QString::number(allExp));
    }
}

