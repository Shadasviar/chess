#include "myview_bot.h"
#include <QMouseEvent>
#include<QGraphicsItem>
#include <cstdlib>
#include <QMessageBox>
#include <ctime>
#include <QString>
#include <thread>


void MyView_bot::mousePressEvent(QMouseEvent *e)
{
    QPointF scenePt = mapToScene(e->pos());
    QGraphicsItem* item = this->scene()->itemAt(scenePt, transform());
    if(selection.size() == 0){
        current_cell = item;
        highlight_moves(item->pos());
    }else{
        if(try_move(to_coordinates(current_cell->pos()), to_coordinates(item->pos()))){

            std::srand(unsigned(std::time(0)));
            auto pieces = current_game->get_pieces_of_player(current_game->get_current_player_color());

            while(pieces.size() > 0){
                auto p = std::next(pieces.begin(), std::rand() % pieces.size());

                auto moves(current_game->get_attack_cells(*p));
                while(moves.size() > 0){
                    auto dst = std::next(moves.begin(), std::rand() % moves.size());
                    if(try_move(*p, *dst)){
                        return;
                    }
                    moves.erase(dst);
                }
                pieces.erase(p);
            }

            pieces = current_game->get_pieces_of_player(current_game->get_current_player_color());

            while(pieces.size() > 0){
                auto p = std::next(pieces.begin(), std::rand() % pieces.size());

                auto moves = current_game->get_move_cells(*p);
                while(moves.size() > 0){
                    auto dst = std::next(moves.begin(), std::rand() % moves.size());
                    if(try_move(*p, *dst)){
                        return;
                    }
                    moves.erase(dst);
                }
                pieces.erase(p);
            }

            /*show messagebox*/
            QMessageBox msg;
            msg.setText(QString(current_game->get_current_player_color() == game::white
                                ? tr("White")
                                : tr("Black")) +"Lose");
            msg.setWindowTitle("Win!");
            msg.exec();

        }
    }

}
