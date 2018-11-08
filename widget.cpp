#include "widget.h"
#include "ui_widget.h"
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{    
    this->brick = new Tetromino();
    this->gameOver = false;
    ui->setupUi(this);
    level = 1;
    speedup = false;
    this->playField.setSize(10, 22);
    this->brick->setType(this->brickTypes[rand()%brickTypes.size()]);
    this->framerate.setInterval(1000/60);
    this->brickFall.setInterval(500/level);
    this->framerate.start();
    this->brickFall.start();
    connect(&framerate, SIGNAL(timeout()), this, SLOT(redraw()));
    connect(&brickFall, SIGNAL(timeout()), this, SLOT(moveDown()));\
    connect(ui->moveLeftBtn, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
    connect(ui->moveRightBtn, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
    connect(ui->rotateBtn, SIGNAL(clicked(bool)), this, SLOT(rotate()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(QColor(0,0,0,25));
    playField.draw(painter);
    brick->draw(painter);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_K)
    {
        playField.score++;
        speedup = true;
    }
    if (event->key() == Qt::Key_J)
    {
        this->brick->move(playField, -1);
    }
    if (event->key() == Qt::Key_L)
    {
        this->brick->move(playField, 1);
    }
    if (event->key() == Qt::Key_I)
    {
        this->brick->rotateTetromino(playField);
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_K)
    {
        speedup = false;
    }
}


void Widget::moveLeft()
{
    this->brick->move(playField, -1);
}

void Widget::moveRight()
{
    this->brick->move(playField, 1);
}

void Widget::moveDown()
{
    if (gameOver)
    {
        ui->moveLeftBtn->setEnabled(false);
        ui->moveRightBtn->setEnabled(false);
        ui->rotateBtn->setEnabled(false);
        return;
    }
    if (this->brick->assignTetromino(playField, gameOver))
    {
        delete brick;
        this->brick = new Tetromino();
        this->brick->setType(this->brickTypes[rand()%brickTypes.size()]);

    }
    level = playField.score / 10000;
    level++;
    this->brick->moveDown();
    if (speedup == true)
    {
        this->brickFall.setInterval(50/level);
    }
    else
    {
        this->brickFall.setInterval(500/level);
    }

}

void Widget::rotate()
{
    this->brick->rotateTetromino(playField);
}

void Widget::redraw()
{
    ui->lcdLevel->display(level);
    ui->lcdNumber->display(playField.score);
    this->repaint();
}


