#ifndef SIMULATION_MODE_H
#define SIMULATION_MODE_H

#include <QDialog>

class MainWindow;

namespace Ui {
class Simulation_mode;
}

class Simulation_mode : public QDialog
{
    Q_OBJECT

public:
    explicit Simulation_mode(MainWindow *mainWin, QWidget *parent = nullptr);
    ~Simulation_mode();

private slots:
    void on_sim_init_button_clicked();

private:
    Ui::Simulation_mode *ui;
    MainWindow *mainWindow;

};

#endif // SIMULATION_MODE_H
