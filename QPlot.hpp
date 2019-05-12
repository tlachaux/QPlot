#ifndef QPLOT_HPP
#define QPLOT_HPP

#include <QLabel>
#include <QPainter>
#include <QVector>

class QPlot : public QWidget
{
public:
    QPlot(QPoint, QPair<QString, QString>);

    void addPoint(int);

    void setMax(const QPoint &);
    void setLegend(QPair<QString, QString>);
    void setPrecision(const QPoint &);
    void setStep(const QPoint &);
    void setCurveColor(const QColor &);
    void setAxisColor(const QColor &);
    void setMargin(const QPoint &);
    void setBackground(const QColor &);


private:
    virtual void            resizeEvent(QResizeEvent *);
    virtual void            paintEvent(QPaintEvent *e);
    void                    build();
    void                    plot();

    QPoint                  _margin;
    QSize                   _size;
    QPoint                  _max;
    QPointF                 _ratio;
    QPair<QString, QString> _legend;
    QPoint                  _precision;
    QPoint                  _step;
    QColor                  _curveColor;
    QColor                  _axisColor;
    QColor                  _background;

    QPainter                _painter;
    QVector<int>            _points;
};


#endif // QPLOT_HPP
