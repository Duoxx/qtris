#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
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
    Tetromino brick;
protected:
    void paintEvent(QPaintEvent* e);
private slots:
    void moveLeft();
    void moveRight();
};

#endif // WIDGET_H
