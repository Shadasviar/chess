#include "myview.h"
#include <QMouseEvent>
#include<QGraphicsItem>
#include<QDesktopWidget>


uint MyView::CELL_SIZE = 80;

MyView::MyView(QGraphicsView *parent):
    QGraphicsView(parent),current_cell(nullptr), current_game(new game())
{
}

MyView::~MyView()
{
    delete current_game;
    delete scene();
}


void MyView::mousePressEvent(QMouseEvent *e)
{
    QPointF scenePt = mapToScene(e->pos());
    QGraphicsItem* item = this->scene()->itemAt(scenePt, transform());
    if(selection.size() == 0){
        current_cell = item;
        highlight_moves(item->pos());
    }else{
        try_move(to_coordinates(current_cell->pos()), to_coordinates(item->pos()));
    }

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


bool MyView::try_move(const coordinates src, const coordinates dst)
{
    if(current_game->move(src, dst)){
        move(src, dst);
        clear_selection();
        if(current_game->current_player_is_under_check()){
            emit under_check("Under check!!!");
        }
        else{
            emit under_check("");
        }
        emit data_changed(current_game->get_current_player_color());
        return true;
    }else{
        clear_selection();
        return false;
    }
}


void MyView::set_img(int i, int j, const QString src){
    QPixmap pixmap(src);
    pixmap = pixmap.scaled(CELL_SIZE, CELL_SIZE, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    field[i][j] = scene()->addPixmap(pixmap);
    field[i][j]->setPos(i*CELL_SIZE, j*CELL_SIZE);
}


QGraphicsScene *MyView::init_scene()
{
    /*create board cells*/
    for(uint8_t i(0); i < CELLS_NUM; ++i){
        for(uint8_t j(0); j < CELLS_NUM; ++j){

            QPixmap pixmap(CELL_SIZE, CELL_SIZE);

            if((j+i)%2 != 0){
                pixmap.fill( QColor(150, 80, 50));
            }
            else{
                pixmap.fill(Qt::white);
            }
            field[i][j] = scene()->addPixmap(pixmap);
            field[i][j]->setPos(to_qpointf({i,j}));
            field[i][j] = nullptr;
        }
    }

    /*init board by pieces*/
    for(size_t i(0); i < CELLS_NUM; ++i){
         set_img(i,1,":/images/img/b_pawn.png");
    }
    for(size_t i(0); i < CELLS_NUM; ++i){
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


void MyView::highlight_moves(QPointF cell_pos)
{
    auto paint = [&](QPixmap pic, set<coordinates> moves){
        for(coordinates c : moves){
            auto* tmp = scene()->addPixmap(pic);
            selection.insert(tmp);
            tmp->setPos(to_qpointf(c));
        }
    };

    auto moves = current_game->get_move_cells(to_coordinates(cell_pos));
    QPixmap pixmap(CELL_SIZE, CELL_SIZE);
    pixmap.fill( QColor(150, 250, 50, 150));

    paint(pixmap, moves);

    moves = current_game->get_attack_cells(to_coordinates(cell_pos));
    pixmap = QPixmap(CELL_SIZE, CELL_SIZE);
    pixmap.fill( QColor(250, 20, 20, 120));

    paint(pixmap, moves);

    pixmap = QPixmap(CELL_SIZE, CELL_SIZE);
    pixmap.fill( QColor(20, 20, 180, 100));
    moves.clear();
    moves.insert(to_coordinates(cell_pos));
    paint(pixmap, moves);

}


void MyView::move(const coordinates src, const coordinates dst)
{
    if(field[dst.x()][dst.y()]) delete field[dst.x()][dst.y()];
    field[dst.x()][dst.y()] = field[src.x()][src.y()];
    field[src.x()][src.y()] = nullptr;
    field[dst.x()][dst.y()]->setPos(to_qpointf(dst));
}


QPointF MyView::to_qpointf(const coordinates& c)
{
    QPointF res;
    res.setX(c.x() * CELL_SIZE);
    res.setY(c.y() * CELL_SIZE);
    return res;
}


coordinates MyView::to_coordinates(const QPointF &p)
{
    return coordinates(p.x() / CELL_SIZE, p.y() / CELL_SIZE);
}

