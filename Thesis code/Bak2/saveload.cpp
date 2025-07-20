#include "saveload.h"
#include "ui_saveload.h"

saveload::saveload(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::saveload)
{
    ui->setupUi(this);
}

saveload::~saveload()
{
    delete ui;
}
