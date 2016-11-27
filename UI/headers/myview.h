#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QSet>
#include "game.h"


class MyView : public QGraphicsView
{
public:
    MyView(QGraphicsView* parent);
    void mousePressEvent(QMouseEvent * e) override;
    void set_scene(QGraphicsScene * scene);
    void clear_selection();

    static constexpr uint CELL_SIZE = 80;
    static constexpr uint CELLS_NUM = 8;

private:
    void set_img(int i, int j, const QString src);
    QGraphicsScene* init_scene();
    void highlight_moves(QPointF);

    static QPointF to_qpointf(const coordinates& c);
    static coordinates to_coordinates(const QPointF& p);

    QGraphicsPixmapItem* field[8][8];
    QSet<QGraphicsPixmapItem*> selection;
    QGraphicsPixmapItem* current_cell;
    game current_game;
};

#endif // MYVIEW_H
