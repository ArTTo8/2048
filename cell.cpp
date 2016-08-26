#include "cell.h"

const QString mStyle = "font:20pt; font-weight:400; border-radius: 5px;";

Cell::Cell(int row, int col, QWidget *parent) :
    QLabel(parent)
{
    setMinimumSize(65, 65);
    setAlignment(Qt::AlignCenter);
    coord = new Coords(row, col);
    setNumber(0);
}

void Cell::setNumber(int num)
{
    switch (num) {
    case 0:
        setStyleSheet(mStyle + "background-color: #cdc1b5; color: black;");
        setText("");
        break;
    case 2:
        setStyleSheet(mStyle + "background-color: #eee4da; color: black;");
        setText(QString::number(num));
        break;
    case 4:
        setStyleSheet(mStyle + "background-color: #eddfc4; color: black;");
        setText(QString::number(num));
        break;
    case 8:
        setStyleSheet(mStyle + "background-color: #f4b17a; color: white;");
        setText(QString::number(num));
        break;
    case 16:
        setStyleSheet(mStyle + "background-color: #f79663; color: white;");
        setText(QString::number(num));
        break;
    case 32:
        setStyleSheet(mStyle + "background-color: #f67d62; color: white;");
        setText(QString::number(num));
        break;
    case 64:
        setStyleSheet(mStyle + "background-color: #f65e39; color: white;");
        setText(QString::number(num));
        break;
    case 128:
        setStyleSheet(mStyle + "background-color: #edce73; color: white;");
        setText(QString::number(num));
        break;
    case 256:
        setStyleSheet(mStyle + "background-color: #e9cf58; color: white;");
        setText(QString::number(num));
        break;
    case 512:
        setStyleSheet(mStyle + "background-color: #edc651; color: white;");
        setText(QString::number(num));
        break;
    case 1024:
        setStyleSheet(mStyle + "background-color: #eec744; color: white;");
        setText(QString::number(num));
        break;
    case 2048:
        setStyleSheet(mStyle + "background-color: #edca64; color: white;");
        setText(QString::number(num));
        break;
    }
}

int Cell::getNumber()
{
    return text().toInt();
}

void Cell::setCoord(Coords *coord)
{
    this->coord = coord;
}
