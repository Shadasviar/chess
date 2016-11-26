#include "myview.h"
#include <QMouseEvent>
#include<QGraphicsItem>


MyView::MyView(QGraphicsView *parent): QGraphicsView(parent)
{

}

void MyView::mousePressEvent(QMouseEvent *e)
{
    QPointF scenePt = mapToScene(e->pos());
    QGraphicsItem* item = this->scene()->itemAt(scenePt, transform());

    QPixmap pixmap(CELL_SIZE, CELL_SIZE);
    pixmap.fill( QColor(150, 250, 50, 150));

    auto* tmp = scene()->addPixmap(pixmap);
    selection.insert(tmp);
    auto i = item->pos();
    tmp->setPos(i);

}


void MyView::set_scene(QGraphicsScene *scene)
{
    setScene(scene);
    init_scene();
}


void MyView::clear_selection()
{
    for(auto* item : selection){
        delete item;
    }
    selection.clear();
}


void MyView::set_img(int i, int j, const QString src){
    QPixmap pixmap(src);
    pixmap = pixmap.scaled(CELL_SIZE, CELL_SIZE);
    field[i][j] = scene()->addPixmap(pixmap);
    field[i][j]->setPos(i*CELL_SIZE, j*CELL_SIZE);
}


QGraphicsScene *MyView::init_scene()
{
    /*create board cells*/
    for(uint i(0); i < CELLS_NUM; ++i){
        for(uint j(0); j < CELLS_NUM; ++j){

            QPixmap pixmap(CELL_SIZE, CELL_SIZE);

            if((j+i)%2 != 0){
                pixmap.fill( QColor(150, 80, 50));
            }
            else{
                pixmap.fill(Qt::white);
            }
            field[i][j] = scene()->addPixmap(pixmap);
            field[i][j]->setPos(i*CELL_SIZE, j*CELL_SIZE);
            field[i][j] = nullptr;
        }
    }

    /*init board by pieces*/
    for(uint i(0); i < CELLS_NUM; ++i){
         set_img(i,1,":/images/img/b_pawn.png");
    }
    for(uint i(0); i < CELLS_NUM; ++i){
        set_img(i,6,":/images/img/w_pawn.png");
    }
    set_img(0,0,":/images/img/b_rook.png");
    set_img(7,0,":/images/img/b_rook.png");
    set_img(0,7,":/images/img/w_rook.png");
    set_img(7,7,":/images/img/w_rook.png");

    set_img(1,0,":/images/img/b_knight.png");
    set_img(6,0,":/images/img/b_knight.png");
    set_img(1,7,":/images/img/w_knight.png");
    set_img(6,7,":/images/img/w_knight.png");

    set_img(2,0,":/images/img/b_bishop.png");
    set_img(5,0,":/images/img/b_bishop.png");
    set_img(2,7,":/images/img/w_bishop.png");
    set_img(5,7,":/images/img/w_bishop.png");

    set_img(3,0,":/images/img/b_queen.png");
    set_img(3,7,":/images/img/w_queen.png");

    set_img(4,0,":/images/img/b_king.png");
    set_img(4,7,":/images/img/w_king.png");

    return scene();
}

