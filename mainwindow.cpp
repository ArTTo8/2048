#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Grid *grid = new Grid(this);
    setCentralWidget(grid);
    setFixedSize(grid->sizeHint());
}

MainWindow::~MainWindow()
{

}
