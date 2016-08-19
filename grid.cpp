#include "grid.h"
#include <QKeyEvent>
#include <QTime>

Grid::Grid(QWidget *parent) :
    QWidget(parent)
{
    lay = new QGridLayout(this);
    setLayout(lay);
    lay->setSpacing(3);
    lay->setMargin(2);
    setFocus();

    list.resize(5);
    for (int i = 0; i < 5; i++)
        list[i].resize(5);

    for (int col = 0; col < 5; col++)
        for (int row = 0; row < 5; row++)
        {
            list[row][col] = new Cell(row, col);
            lay->addWidget(list[row][col], row, col);
        }

    list.at(0).at(0)->setNumber(2);
    list.at(1).at(0)->setNumber(2);
}

void Grid::keyPressEvent(QKeyEvent *event)
{
  switch (event->key()) {
  case Qt::Key_Up:
        moveUp();
        break;
  case Qt::Key_Down:
        moveDown();
        break;
  case Qt::Key_Left:
        moveLeft();
        break;
  case Qt::Key_Right:
        moveRight();
        break;
  }
}

void Grid::moveUp()
{
    for (int col = 0; col < 5; col++)
        for (int row = 0; row < 4; row++)
        {
            if (list[row][col]->getNumber() == list[row + 1][col]->getNumber())
            {
                list[row][col]->setNumber(list[row][col]->getNumber() * 2);
            }
        }
    addRandCell();
}

void Grid::moveDown()
{
    for (int col = 0; col < 5; col++)
        for (int row = 0; row < 4; row++)
        {
            if (list[row][col]->getNumber() == list[row + 1][col]->getNumber())
            {
                list[row][col]->setNumber(0);
                list[row + 1][col]->setNumber(list[row + 1][col]->getNumber() * 2);
                continue;
            }
            if (list[row + 1][col]->getNumber() == 0)
            {
                list[row + 1][col]->setNumber(list[row][col]->getNumber());
                list[row][col]->setNumber(0);
                continue;
            }
        }
    addRandCell();
}

void Grid::moveLeft()
{
    for (int col = 4; col > 0; col--)
        for (int row = 0; row < 5; row++)
        {
            if (list[row][col]->getNumber() == list[row][col - 1]->getNumber())
            {
                list[row][col]->setNumber(0);
                list[row][col - 1]->setNumber(list[row][col - 1]->getNumber() * 2);
                continue;
            }
            if (list[row][col - 1]->getNumber() == 0)
            {
                list[row][col - 1]->setNumber(list[row][col]->getNumber());
                list[row][col]->setNumber(0);
                continue;
            }
        }
    addRandCell();
}

void Grid::moveRight()
{
    for (int col = 0; col < 4; col++)
        for (int row = 0; row < 5; row++)
        {
            if (list[row][col]->getNumber() == list[row][col + 1]->getNumber())
            {
                list[row][col]->setNumber(0);
                list[row][col + 1]->setNumber(list[row][col + 1]->getNumber() * 2);
                continue;
            }
            if (list[row][col + 1]->getNumber() == 0)
            {
                list[row][col + 1]->setNumber(list[row][col]->getNumber());
                list[row][col]->setNumber(0);
                continue;
            }
        }
    addRandCell();
}

void Grid::addRandCell()
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    unsigned short int i = rand()%4;
    unsigned short int j = rand()%4;
    if (list[i][j]->getNumber() == 0)
        list[i][j]->setNumber(2);
}
