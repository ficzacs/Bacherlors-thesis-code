#ifndef LOAD_MODE_H
#define LOAD_MODE_H

#include <QDialog>

class MainWindow;

namespace Ui {
class Load_mode;
}

class Load_mode : public QDialog
{
    Q_OBJECT

public:
    explicit Load_mode(MainWindow *mainWin, QWidget *parent = nullptr);
    ~Load_mode();

private slots:
    void on_Mapload_button_clicked();
    void on_Mapload2_button_clicked();
    void on_Mapload3_button_clicked();

private:
    Ui::Load_mode *ui;
    MainWindow *mainWindow;
};
#endif // LOAD_MODE_H
