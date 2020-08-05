#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initLayout();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLayout()
{
    auto resources = StringResources::getInstance();
    auto regions = resources->getValue("regions");

    setWindowTitle("Pacie");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(8);
    gridLayout->setColumnMinimumWidth(0, 250);
    gridLayout->addWidget(ui->groupBox,0,0,1,1);
    gridLayout->addWidget(ui->mirrorTbl,0,1,1,1);
    ui->centralwidget->setLayout(gridLayout);
}


