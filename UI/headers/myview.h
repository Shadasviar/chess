#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QSet>
#include "igame.h"
#include "game.h"


class MyView : public QGraphicsView
{
    Q_OBJECT

public:
    MyView(QGraphicsView* parent);
    ~MyView();
    void mousePressEvent(QMouseEvent * e) override;
    void set_scene(QGraphicsScene * scene);

    static uint CELL_SIZE;
    static constexpr uint CELLS_NUM = 8;

signals:
    void data_changed(game::color);
    void under_check(QString);

protected:
    void set_img(int i, int j, const QString src);
    QGraphicsScene* init_scene();
    void highlight_moves(QPointF);
    void move(const coordinates src, const coordinates dst);
    void clear_selection();
    bool try_move(const coordinates src, const coordinates dst);

    static QPointF to_qpointf(const coordinates& c);
    static coordinates to_coordinates(const QPointF& p);

    QGraphicsPixmapItem* field[CELLS_NUM][CELLS_NUM];
    QSet<QGraphicsPixmapItem*> selection;
    QGraphicsItem* current_cell;
    Igame* current_game;
};

#endif // MYVIEW_H
