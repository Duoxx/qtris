#ifndef FIELD_H
#define FIELD_H
#include <QPoint>
#include <QVector>
#include <QPainter>
#include <QColor>
#include "colors.h"

class Tetromino;

class Field
{
public:
    Field();
    Field(int sx, int sy);
    ~Field();
    bool inBounds(Tetromino& brick, int prevX);
    bool placeable(Tetromino& brick);
    bool place(Tetromino& brick);
    void scan();
    bool scanLine(int lineN);
    int score;
    void setSize(int sx, int sy);
    void draw(QPainter& painter);
private:
    QPoint size;
    int** values;
};

#endif // FIELD_H
