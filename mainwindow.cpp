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
    QRegExp rx("([A-Za-z]{2})=([A-Za-z]* ?[A-Za-z]*)?$");
    QFile inputFile(resource_path);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {

            auto line = in.readLine();
            if(!line.isEmpty()) {
                rx.indexIn(line);
                qDebug() << rx.cap(1);
                qDebug() << rx.cap(2);
            }

            //qDebug() << line;

            //qDebug() << rx.captureCount();

            //if(rx.indexIn(in.readLine()) < 0 || rx.captureCount() < 3) continue;
            //qDebug() << rx.cap(1);
            //qDebug() << rx.cap(2);

        }
        inputFile.close();
    }
}


