#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <QGridLayout>

class Grid : public QWidget
{
    Q_OBJECT
    QVector<QVector<Cell*> > list;
    QGridLayout *lay;
    enum Direction { Up, Down, Left, Right };

private:
    QList<int> move(QList<int> list);
    void addRandCell();
//    bool isMovePossible(Direction dir);
    bool isFull();

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    explicit Grid(QWidget *parent = 0);

};

#endif // GRID_H
