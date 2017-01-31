#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QDesktopWidget widget;
    QRect rec = widget.availableGeometry(widget.primaryScreen());
    MyView::CELL_SIZE = rec.height() / 13;

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


/*It use macro instead of function because in this part of code class MainWindow hasn't exist yet and
 * function can't find ui->board because forward declaration.*/
#define REINIT_VIEW(T) \
    delete view;\
    view = new T(ui->board);\
    QObject::connect(view, SIGNAL(data_changed(game::color)), this, SLOT(data_changed(game::color)));\
    QObject::connect(view, SIGNAL(under_check(QString)), this, SLOT(under_check(QString)));\
    QGraphicsScene* scene = new QGraphicsScene();\
    view->set_scene(scene);\
    view->show();


void MainWindow::on_actionMultiplayer_triggered()
{
    REINIT_VIEW(MyView);
}


void MainWindow::on_actionWith_computer_triggered()
{
    REINIT_VIEW(MyView_bot);
}

