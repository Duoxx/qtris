#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QKeyEvent>
#include "field.h"
#include "tetromino.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Field playField;
    QVector<char> brickTypes {'L', 'I', 'Z', 'O', 'T', 'P', 'S'};
    QTimer brickFall;
    Tetromino* brick;
    QTimer framerate;
    QTimer speedupTimeout;
    int level;
    bool speedup;
    bool gameOver;
protected:
    void paintEvent(QPaintEvent* e);
private:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotate();
    void redraw();
};

#endif // WIDGET_H
