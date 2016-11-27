#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->board->setFixedSize(MyView::CELLS_NUM*MyView::CELL_SIZE, MyView::CELLS_NUM*MyView::CELL_SIZE);
    view = new MyView(ui->board);
    QGraphicsScene* scene = new QGraphicsScene();
    view->set_scene(scene);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_actionSelect_triggered()
{
    view->clear_selection();
}
