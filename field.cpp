#include "tetromino.h"
#include "field.h"

Field::Field()
{

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

bool Field::inBounds(Tetromino& brick)
{
    return brick.getPosition().x() > 0 &&
            brick.getPosition().y() > 0 &&
            brick.getPosition().x() < this->size.x() &&
            brick.getPosition().y() < this->size.y();
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
