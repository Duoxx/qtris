#ifndef COLORS_H
#define COLORS_H
#include <QVector>
#include <QColor>

class TetrisColors
{
public:
    static QColor& getColor(int color)
    {
        QVector<QColor> tetrisColors
        {
            QColor(255, 255, 255), //white
            QColor(0, 200,   255), //cyan
            QColor(0, 128,   255), //blue
            QColor(255, 128, 0), //orange
            QColor(255, 255, 0), //yellow
            QColor(0, 200,   0), //green
            QColor(255, 0, 128), //purple
            QColor(200, 0,   0) //red
        }; // color equivalents

        return tetrisColors[color%8];
    }
};


#endif // COLORS_H
