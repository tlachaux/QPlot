#ifndef QPLOT_HPP
#define QPLOT_HPP

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
    void setCurveColor(const QColor &);
    void setAxesColor(const QColor &);
    void setMargin(const QPoint &);
    void setBackground(const QColor &);

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
    QColor                  _curveColor;
    QColor                  _axesColor;
    QColor                  _background;

    QPixmap                 _pixmap;
    QPainter                _painter;
    QVector<int>            _points;

    bool                    _update = false;
};


#endif // QPLOT_HPP
