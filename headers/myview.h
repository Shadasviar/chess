#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QSet>


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

    QGraphicsPixmapItem* field[8][8];
    QSet<QGraphicsPixmapItem*> selection;
    QGraphicsPixmapItem* current_cell;
};

#endif // MYVIEW_H
