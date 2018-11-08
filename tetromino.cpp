#include "tetromino.h"

Tetromino::Tetromino()
{
    this->intColor = rand();
    if (this->intColor % 8 == 0)
    {
        this->intColor = 1;
    }
    this->color = TetrisColors::getColor(intColor);

    this->position.setX(3);
    this->position.setY(-2);
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
    else if (type == 'Z')
    {
        this->brickSize = 3;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 0));
        points.push_back(QPoint(0, 1));
        points.push_back(QPoint(1, 1));
        points.push_back(QPoint(1, 2));
        this->fillBrick(points);
    }
    else if (type == 'L')
    {
        this->brickSize = 3;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 0));
        points.push_back(QPoint(0, 1));
        points.push_back(QPoint(0, 2));
        points.push_back(QPoint(1, 2));
        this->fillBrick(points);
    }
    else if (type == 'O')
    {
        this->brickSize = 2;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 0));
        points.push_back(QPoint(0, 1));
        points.push_back(QPoint(1, 1));
        points.push_back(QPoint(1, 0));
        this->fillBrick(points);
    }
    else if (type == 'T')
    {
        this->brickSize = 3;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 0));
        points.push_back(QPoint(1, 0));
        points.push_back(QPoint(2, 0));
        points.push_back(QPoint(1, 1));
        this->fillBrick(points);
    }
    else if (type == 'S')
    {
        this->brickSize = 3;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(2, 0));
        points.push_back(QPoint(1, 0));
        points.push_back(QPoint(1, 1));
        points.push_back(QPoint(0, 1));
        this->fillBrick(points);
    }
    else if (type == 'P')
    {
        this->brickSize = 3;
        this->makeBrick(this->brickSize);
        QVector<QPoint> points;
        points.push_back(QPoint(0, 0));
        points.push_back(QPoint(0, 1));
        points.push_back(QPoint(0, 2));
        points.push_back(QPoint(1, 0));
        this->fillBrick(points);
    }
}

void Tetromino::rotateTetromino(Field& f)
{
    if (this->position.y() < 0) return;
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
    if (!f.inBounds(*this, 0))
    {
        rotateTetromino(f);
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
                painter.drawRect(QRect(16*i+position.x()*16, 16*j+position.y()*16, 16, 16));
            }
        }
    }
}

int Tetromino::getWidth()
{
    int width = 0;
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (brick[i][j] == '#')
            {
                width = i;
                break;
            }
        }
    }
    return width;
}

int Tetromino::getHeight()
{
    int height = 0;
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (brick[j][i] == '#')
            {
                height = i;
                break;
            }

        }
    }
    return height+1;
}

int Tetromino::getFirstTileFromLeft()
{
    int left = 0;
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (brick[i][j] == '#')
            {
                left = i;
                return left;
            }
        }
    }
}

int Tetromino::getLastLeftTile()
{
    int right;
    for (int i = 0; i < brickSize; i++)
    {
        for (int j = 0; j < brickSize; j++)
        {
            if (brick[i][j] == '#')
            {
                right = i;
            }
        }
    }
    return right;
}

int Tetromino::getFirstTopTile()
{
    int top = 0;
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (brick[i][j] == '#')
            {
                top = i;
                return top;
            }
        }
    }
}
int Tetromino::getLastTopTile()
{
    int topLast = 0;
    for (int i = 0; i < this->brickSize; i++)
    {
        for (int j = 0; j < this->brickSize; j++)
        {
            if (brick[i][j] == '#')
            {
                topLast = i;
            }
        }
    }
    return topLast;
}

int Tetromino::getSize()
{
    return brickSize;
}

char Tetromino::getTile(int x, int y)
{
    return this->brick[x][y];
}

int Tetromino::getColor()
{
    return intColor;
}

void Tetromino::move(Field &f, int x)
{
    int prevx = this->position.x();
    this->position.setX(this->position.x()+x);
    if (!f.inBounds(*this, -x))
    {
        this->position.setX(prevx);
    }

}

bool Tetromino::assignTetromino(Field &f, bool &gameOver)
{
    if (f.placeable(*this))
    {
        gameOver = !f.place(*this);
        return true;
    }
    return false;
}

void Tetromino::moveDown()
{
    this->position.setY(this->position.y()+1);
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
        this->brick[i] = new char[size];
        for (int j = 0; j < size; j++)
        {
            this->brick[i][j] = '0';
        }
    }
}

void Tetromino::fillBrick(QVector<QPoint> &positions)
{
    for (int i = 0; i < positions.size(); i++)
    {
        brick[positions[i].x()][positions[i].y()] = '#';
    }
}

