#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <QLabel>
#include <QPainter>
#include <QVector>

class QPlot : public QLabel
{
public:
    QPlot(QPoint, QPair<QString, QString>);

    void addPoint(int);
    void plot();
    void clear();

    void setUnableAutoUpdate(bool);
    void setMax(const QPoint &);
    void setLegend(QPair<QString, QString>);
    void setPrecision(const QPoint &);
    void setStep(const QPoint &);
    void setColor(const QColor &);
    void setMargin(const QPoint &);
    void setBackground(const QColor &background);

    void resizeEvent(QResizeEvent *);

private:

    void                    build();

    QPoint                  _margin;
    QSize                   _size;
    QPoint                  _max;
    QPointF                 _ratio;
    QPair<QString, QString> _legend;
    QPoint                  _precision;
    QPoint                  _step;
    QColor                  _color;
    QColor                  _background;

    QPixmap                 _pixmap;
    QPainter                _painter;
    QVector<int>            _points;

    bool                    _update = false;
};


#endif // GRAPH_HPP
