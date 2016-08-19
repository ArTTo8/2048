#include "cell.h"

Cell::Cell(int row, int col, QWidget *parent) :
    QLabel(parent)
{
    resize(70, 70);
    number = 0;
    coord = new Coords(row, col);
    setNumber(0);
}

void Cell::setNumber(unsigned short num)
{
    QPixmap pix;
    switch (num) {
    case 0:
        pix.load(":/sprites/base.png");
        setPixmap(pix);
        number = 0;
        break;
    case 2:
        pix.load(":/sprites/2.png");
        setPixmap(pix);
        number = 2;
        break;
    case 4:
        pix.load(":/sprites/4.png");
        setPixmap(pix);
        number = 4;
        break;
    case 8:
        pix.load(":/sprites/8.png");
        setPixmap(pix);
        number = 8;
        break;
    case 16:
        pix.load(":/sprites/16.png");
        setPixmap(pix);
        number = 16;
        break;
    case 32:
        pix.load(":/sprites/32.png");
        setPixmap(pix);
        number = 32;
        break;
    case 64:
        pix.load(":/sprites/64.png");
        setPixmap(pix);
        number = 64;
        break;
    case 128:
        pix.load(":/sprites/128.png");
        setPixmap(pix);
        number = 128;
        break;
    case 256:
        pix.load(":/sprites/256.png");
        setPixmap(pix);
        number = 256;
        break;
    case 512:
        pix.load(":/sprites/512.png");
        setPixmap(pix);
        number = 512;
        break;
    case 1024:
        pix.load(":/sprites/1024.png");
        setPixmap(pix);
        number = 1024;
        break;
    case 2048:
        pix.load(":/sprites/2048.png");
        setPixmap(pix);
        number = 2048;
        break;
    }
}

int Cell::getNumber()
{
    return number;
}

void Cell::setCoord(Coords *coord)
{
    this->coord = coord;
}
