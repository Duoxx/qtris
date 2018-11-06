#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{    
    ui->setupUi(this);
    this->playField.setSize(10, 22);
    this->brick.setType('I');
    connect(ui->moveLeftBtn, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
    connect(ui->moveRightBtn, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    brick.draw(painter);
}

void Widget::moveLeft()
{
    this->brick.move(playField, -1, 0);
}

void Widget::moveRight()
{
    this->brick.move(playField, 1, 0);
}
