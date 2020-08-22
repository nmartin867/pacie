#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMap<QString, QString> *regions;
    Ui::MainWindow *ui;

    void initLayout();
    void initRegions();

    void attachHandlers();
};
#endif // MAINWINDOW_H
