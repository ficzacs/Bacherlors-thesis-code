#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QDialog>

class MainWindow;

namespace Ui {
class Tutorial;
}

class Tutorial : public QDialog
{
    Q_OBJECT

public:
    explicit Tutorial(MainWindow *mainWin, QWidget *parent = nullptr);
    ~Tutorial();

private:
    Ui::Tutorial *ui;
    MainWindow *mainWindow;
};

#endif // TUTORIAL_H
