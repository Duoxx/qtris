#ifndef TETROMINO_H
#define TETROMINO_H
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QColor>
#include "colors.h"
#include "field.h"

class Field;

class Tetromino
{
public:
    Tetromino();
    void setType(char type);
    void rotateTetromino();
    void draw(QPainter& painter);
    void move(Field& f, int x, int y);
    QPoint getPosition();
private:
    void makeBrick(int size);
    void fillBrick(QVector<QPoint>& positions);
    char** brick;
    QColor color;
    QPoint position;
    int brickSize;
};

#endif // TETROMINO_H
