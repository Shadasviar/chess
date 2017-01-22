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
    view = new MyView_bot(ui->board);

    QObject::connect(view, SIGNAL(data_changed(game::color)), this, SLOT(data_changed(game::color)));
    QObject::connect(view, SIGNAL(under_check(QString)), this, SLOT(under_check(QString)));

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


void MainWindow::data_changed(game::color col)
{
    ui->curr_player_name_label->setText((col == game::white)
                                        ? tr("White")
                                        : tr("Black"));
}


void MainWindow::under_check(QString s)
{
    ui->check_label->setText(s);
}


void MainWindow::on_actionMultiplayer_triggered()
{
    delete view;
    view = new MyView(ui->board);

    QObject::connect(view, SIGNAL(data_changed(game::color)), this, SLOT(data_changed(game::color)));
    QObject::connect(view, SIGNAL(under_check(QString)), this, SLOT(under_check(QString)));

    QGraphicsScene* scene = new QGraphicsScene();
    view->set_scene(scene);
    view->show();
}


void MainWindow::on_actionWith_computer_triggered()
{
    delete view;
    view = new MyView_bot(ui->board);

    QObject::connect(view, SIGNAL(data_changed(game::color)), this, SLOT(data_changed(game::color)));
    QObject::connect(view, SIGNAL(under_check(QString)), this, SLOT(under_check(QString)));

    QGraphicsScene* scene = new QGraphicsScene();
    view->set_scene(scene);
    view->show();
}
