#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsPixmapItem>
#include <QSet>
#include <QMainWindow>
#include "myview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void data_changed(game::color);
    void under_check(QString);

private:
    Ui::MainWindow *ui;
    MyView* view;

};

#endif // MAINWINDOW_H
