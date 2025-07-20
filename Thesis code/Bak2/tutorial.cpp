#include "tutorial.h"
#include "ui_tutorial.h"
#include "mainwindow.h"

Tutorial::Tutorial(MainWindow * mainWin, QWidget *parent)
    : QDialog(parent), ui(new Ui::Tutorial), mainWindow(mainWin)
{
    ui->setupUi(this);
}

Tutorial::~Tutorial()
{
    delete ui;
}
