#include "tetromino.h"

Tetromino::Tetromino()
{
    this->color = TetrisColors::getColor(rand());
    this->position.setX(0);
    this->position.setY(0);
}

void Tetromino::setType(char type)
{
    if (type == 'I')
    {
        this->brickSize = 4;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 1));
        points.push_back(QPoint(1, 1));
        points.push_back(QPoint(2, 1));
        points.push_back(QPoint(3, 1));
        this->fillBrick(points);
    }
}

void Tetromino::rotateTetromino()
{
    for (int x = 0; x < this->brickSize/2; x++)
    {
        for (int y = x; y < this->brickSize-x-1; y++)
        {
            char temp = brick[x][y];
            brick[x][y] = brick[y][this->brickSize-1-x];
            brick[y][this->brickSize-1-x] = brick[this->brickSize-1-x][this->brickSize-1-y];
            brick[this->brickSize-1-x][this->brickSize-1-y] = brick[this->brickSize-1-y][x];
            brick[this->brickSize-1-y][x] = temp;
        }
    }
}

void Tetromino::draw(QPainter &painter)
{
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (this->brick[i][j] == '#')
            {
                painter.setBrush(QBrush(this->color));
                painter.drawRect(QRect(10*i+position.x(), 10*j+position.y(), 10, 10));
            }
        }
    }
}

void Tetromino::move(Field &f, int x, int y = 0)
{
    int prevx = this->position.x();
    int prevy = this->position.y();
    this->position.setX(this->position.x()+(x*10));
    this->position.setY(this->position.y()+(y*10));
    if (!f.inBounds(this))
    {
        this->position.setX(prevx);
        this->position.setY(prevy);
    }

}

QPoint Tetromino::getPosition()
{
    return position;
}

void Tetromino::makeBrick(int size)
{
    this->brick = new char*[size];
    for (int i = 0; i < size; i++)
    {
        this->brick[i] = new char[size]{'0'};
    }
}

void Tetromino::fillBrick(QVector<QPoint> &positions)
{
    for (int i = 0; i < positions.size(); i++)
    {
        brick[positions[i].x()][positions[i].y()] = '#';
    }
}

