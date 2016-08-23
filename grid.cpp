#include "grid.h"
#include <QKeyEvent>

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
    QList<int> notZero;
    switch (event->key()) {
    case Qt::Key_Up:
        for (int col = 0; col < 5; col++)
        {
            for (int row = 0; row < 5; row++)
                if (list[row][col]->getNumber() != 0)
                    notZero.append(list[row][col]->getNumber());
            notZero = move(notZero);

            for (int row = 0; row < 5; row++)
            {
                if (!notZero.isEmpty())
                    list[row][col]->setNumber(notZero.takeFirst());
                else list[row][col]->setNumber(0);
            }
        }
        addRandCell();
        break;
    case Qt::Key_Down:
        for (int col = 0; col < 5; col++)
        {
            for (int row = 4; row >= 0; row--)
                if (list[row][col]->getNumber() != 0)
                    notZero.append(list[row][col]->getNumber());
            notZero = move(notZero);

            for (int row = 4; row >= 0; row--)
            {
                if (!notZero.isEmpty())
                    list[row][col]->setNumber(notZero.takeFirst());
                else list[row][col]->setNumber(0);
            }
        }
        addRandCell();
        break;
    case Qt::Key_Left:
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
                if (list[row][col]->getNumber() != 0)
                    notZero.append(list[row][col]->getNumber());
            notZero = move(notZero);

            for (int col = 0; col < 5; col++)
            {
                if (!notZero.isEmpty())
                    list[row][col]->setNumber(notZero.takeFirst());
                else list[row][col]->setNumber(0);
            }
        }
        addRandCell();
        break;
    case Qt::Key_Right:
        for (int row = 0; row < 5; row++)
        {
            for (int col = 4; col >= 0; col--)
                if (list[row][col]->getNumber() != 0)
                    notZero.append(list[row][col]->getNumber());
            notZero = move(notZero);

            for (int col = 4; col >= 0; col--)
            {
                if (!notZero.isEmpty())
                    list[row][col]->setNumber(notZero.takeFirst());
                else list[row][col]->setNumber(0);
            }
        }
        addRandCell();
        break;
    }
}

QList<int> Grid::move(QList<int> list)
{
    for (int i = 0; i < list.count() - 1; i++)
        if (list.at(i) == list.at(i + 1))
        {
            list[i] *= 2;
            list.removeAt(i + 1);
    }
    return list;
}

void Grid::addRandCell()
{
    unsigned i = rand()%5;
    unsigned j = rand()%5;
    if (list[i][j]->getNumber() == 0)
        list[i][j]->setNumber(2);
    else addRandCell();
}
