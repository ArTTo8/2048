#ifndef CELL_H
#define CELL_H

#include <QLabel>

struct Coords
{
    Coords(int row, int col)
    {
        this->col = col;
        this->row = row;
    }
    Coords& operator=(Coords &c)
    {
        col = c.col;
        row = c.row;
        return *this;
    }

public:
    int col;
    int row;
};

class Cell : public QLabel
{
    Q_OBJECT
    Coords *coord;

public:
    explicit Cell(int row, int col, QWidget *parent = 0);
    void setNumber(int num);
    int getNumber();
    void setCoord(Coords *coord);

};

#endif // CELL_H
