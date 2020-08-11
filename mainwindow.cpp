#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "INIReader.h"

#include <QGridLayout>
#include <QDebug>
#include <QFile>


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

    setWindowTitle("Pacie");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(8);
    gridLayout->setColumnMinimumWidth(0, 250);
    gridLayout->addWidget(ui->groupBox,0,0,1,1);
    gridLayout->addWidget(ui->mirrorTbl,0,1,1,1);
    ui->centralwidget->setLayout(gridLayout);

    initRegions();
}

void MainWindow::initRegions()
{
    QRegExp rx("([A-Za-z]{2,3})=([A-Za-z]* ?[A-Za-z]*)?$");
    QFile inputFile(resource_path);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        regions = new QMap<QString, QString>();
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
           if(rx.indexIn(in.readLine().trimmed()) < 0) continue;
           auto key = rx.cap(1); auto value = rx.cap(2);
           ui->regionComboBox->addItem(value,key);
           regions->insert(key,value);
        }
        inputFile.close();
    }

}


