#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgridlayout.h"
#include "tutorial.h"
#include <QMainWindow>

class Simulation_mode;
class Load_mode;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialize_buttons();
    void generate_obstacle_buttons(int obstacles);
    void restart_buttons();

    void shortest_path_bfs(int& pathLength);
    void shortest_path_dfs(int& pathLength);

    void explore_randomwalk(int& explored, int& steps, bool delay);
    void explore_greedy_bfs(int& explored, int& steps, bool delay);
    void explore_dfs(int& explored, int& steps, bool delay);
    void explore_bfs(int& explored, int& steps, bool delay);
    void explore_A_star(int& explored, int& steps, bool delay);

    void load_map(int map[20][20]);
    bool is_map_valid();

private slots:
    void on_exit_button_clicked();
    void on_sim_button_clicked();
    void on_restart_button_clicked();
    void on_Obstacle_generate_button_clicked();
    void on_explore_button_clicked();
    void on_pathfind_button_clicked();
    void on_load_button_clicked();
    void switch_buttons();

    void on_tutoria_button_clicked();



private:
    Ui::MainWindow *ui;
    Simulation_mode *simMode;
    Load_mode *loadMode;
    Tutorial *tutorial;

    QGridLayout *gridLayout;
    void generateButtons();
    int start_x, start_y, finish_x, finish_y;

};
#endif // MAINWINDOW_H
