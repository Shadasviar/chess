#ifndef MYVIEW_BOT_H
#define MYVIEW_BOT_H
#include "myview.h"

class MyView_bot : public MyView{

public:

    MyView_bot(QGraphicsView* parent):MyView(parent){}
    ~MyView_bot() {}
    void mousePressEvent(QMouseEvent * e) override;
};

#endif // MYVIEW_BOT_H
