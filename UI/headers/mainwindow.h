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
    void on_actionSelect_triggered();
    void data_changed(game::color);

private:
    /*
    void set_img(int i, int j, const QString src);
    QGraphicsScene* init_scene();
    */

    Ui::MainWindow *ui;
    MyView* view;
    /*
    QGraphicsPixmapItem* field[8][8];
    QSet<QGraphicsPixmapItem*> selection;
    QGraphicsPixmapItem* current_cell;
    QGraphicsScene* scene;
    static constexpr uint CELL_SIZE = 80;
    static constexpr uint CELLS_NUM = 8;
    */
};

#endif // MAINWINDOW_H
