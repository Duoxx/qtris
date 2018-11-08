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
    void rotateTetromino(Field& f);
    void draw(QPainter& painter);
    int getWidth();
    int getHeight();
    int getFirstTileFromLeft();
    int getLastLeftTile();
    int getFirstTopTile();
    int getLastTopTile();
    int getSize();
    char getTile(int x, int y);
    int getColor();
    void move(Field& f, int x);
    bool assignTetromino(Field& f, bool &gameOver);
    void moveDown();
    QPoint getPosition();
private:
    void makeBrick(int size);
    void fillBrick(QVector<QPoint>& positions);
    char** brick;
    QColor color;
    QPoint position;
    int intColor;
    int brickSize;
};

#endif // TETROMINO_H
