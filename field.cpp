#include "field.h"
#include "tetromino.h"

Field::Field()
{
    score = 0;
}

Field::Field(int sx, int sy)
{


    this->size.setX(sx);
    this->size.setY(sy);
    this->values = new int*[sx];
    for (int i = 0; i < sx; i++)
    {
        this->values[i] = new int[sy];
        for (int j = 0; j < sy; j++)
        {
            this->values[i][j] = 0;

        }
    }

}

Field::~Field()
{

    for (int i = 0; i < size.x(); i++)
    {
        delete[] values[i];
    }
    delete[] values;
}

bool Field::inBounds(Tetromino& brick, int prevX)
{

    for (int i = 0; i < brick.getSize(); i++)
    {
        for (int j = 0; j < brick.getSize(); j++)
        {
            if (brick.getTile(i, j) == '#')
            {
                if (i+brick.getPosition().x() < 0 || i+brick.getPosition().x() > this->size.x()-1 ||
                        brick.getPosition().y() < 0 || i+brick.getPosition().y() > this->size.y()-1)
                {
                    return false;
                }
                    if (this->values[i+brick.getPosition().x()][j+brick.getPosition().y()] > 0)
                    {
                        return false;
                    }
            }
        }
    }
        return brick.getPosition().x()+brick.getFirstTileFromLeft() >= 0 &&
                brick.getPosition().x()+brick.getWidth() < this->size.x();

}

bool Field::placeable(Tetromino &brick)
{
    if (brick.getPosition().y()+brick.getHeight() == this->size.y())
    {
        return true;
    }
    for (int i = 0; i < brick.getSize(); i++)
    {
        for (int j = 0; j < brick.getSize(); j++)
        {
            if (brick.getTile(i, j) == '#')
            {
                if (this->values[i+brick.getPosition().x()][j+brick.getPosition().y()+1] > 0)
                {
                    return true;
                }
            }
        }
    }


    return false;
}

bool Field::place(Tetromino &brick)
{

    if (brick.getPosition().y() < 0)
    {
        return false;
    }
    for (int i = 0; i < brick.getSize(); i++)
    {
        for (int j = 0; j < brick.getSize(); j++)
        {
            if (brick.getTile(j, i) == '#')
            {
                this->values[j+brick.getPosition().x()][i+brick.getPosition().y()] = brick.getColor();
            }
        }
    }
    scan();
    return true;
}

void Field::scan()
{
    int lines = 0;
    for (int i = 0; i < size.y(); i++)
    {
        if (scanLine(i) == true)
        {
            lines++;
            for (int j = i; j > 0; j--)
            {
                for (int k = 0; k < size.x(); k++)
                {
                     values[k][j] = values[k][j-1];
                }
            }
        }
    }
    score += (lines*lines) * 100;
}

bool Field::scanLine(int lineN)
{
    for (int j = 0; j < size.x(); j++)
    {
        if (this->values[j][lineN] == 0)
        {
            return false;
        }
    }
    return true;
}

void Field::setSize(int sx, int sy)
{
    this->size.setX(sx);
    this->size.setY(sy);
    this->values = new int*[sx];
    for (int i = 0; i < sx; i++)
    {
        this->values[i] = new int[sy];
        for (int j = 0; j < sy; j++)
        {
            this->values[i][j] = 0;
        }
    }
}

void Field::draw(QPainter &painter)
{
    for (int i = 0; i < size.x(); i++)
    {
        for (int j = 0; j < size.y(); j++)
        {
            painter.setBrush(QBrush(TetrisColors::getColor(values[i][j])));
            painter.drawRect(QRect(i*16,j*16,16,16));
        }
    }
}
