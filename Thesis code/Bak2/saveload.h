#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QDialog>

class MainWindow;

namespace Ui {
class saveload;
}

class saveload : public QDialog
{
    Q_OBJECT

public:
    explicit saveload(MainWindow *mainWin, QWidget *parent = nullptr);
    ~saveload();

private:
    Ui::saveload *ui;
    MainWindow *mainWindow;
};

#endif // SAVELOAD_H
