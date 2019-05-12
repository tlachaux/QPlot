#include <QResizeEvent>

#include <iostream>

#include "QPlot.hpp"

QPlot::QPlot(QPoint max, QPair<QString, QString> legend)
    : _margin(40, 40)
    , _size(max.x() + (_margin.x() * 2), max.y() + (_margin.y() * 2))
    , _max(max)
    , _legend(legend)
    , _precision(50, 50)
    , _step(5, 5)
    , _curveColor(0, 200, 100)
    , _axisColor(255, 255, 255)
{
    _ratio.setX(double(_size.width() - (_margin.x() * 2)) / double(_max.x()));
    _ratio.setY(double(_size.height() - (_margin.y() * 2)) / double(_max.y()));
}

void QPlot::addPoint(int y)
{
    _points.push_back(y);
}

void QPlot::plot()
{
    _painter.begin(this);

    _painter.setRenderHint(QPainter::Antialiasing);
    _painter.setRenderHint(QPainter::HighQualityAntialiasing);
    _painter.setPen(QPen(_curveColor, 2, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    _painter.setBrush(_curveColor);

    int start = (_points.size() * _step.x() <= _max.x()) ?
                1 : ((_points.size() * _step.x()) - _max.x())/_step.x();

    int xTmp = 0;
    int yTmp = 0;

    for (int i=start; i < _points.size(); ++i) {
        xTmp = _margin.x() + int((i - start) * _step.x() * _ratio.x());
        yTmp = _size.height() - _margin.y();
        _painter.drawLine(xTmp, yTmp - int(_points[i - 1] * _step.y() * _ratio.y()),
                         xTmp + int(_step.x() * _ratio.x()),
                         yTmp - int(_points[i] * _step.y() * _ratio.y()));
    }
    _painter.end();
}

void QPlot::paintEvent(QPaintEvent *e)
{
    this->build();
    this->plot();
    QWidget::paintEvent(e);
}

void QPlot::setMax(const QPoint &max)
{
    _max = max;
}

void QPlot::setLegend(QPair<QString, QString> legend)
{
    _legend = legend;
}

void QPlot::setPrecision(const QPoint &precision)
{
    _precision = precision;
}

void QPlot::setStep(const QPoint &step)
{
    _step = step;
}

void QPlot::setCurveColor(const QColor &color)
{
    _curveColor = color;
}

void QPlot::setMargin(const QPoint &margin)
{
    _margin = margin;
}

void QPlot::setBackground(const QColor &background)
{
    _background = background;
}

void QPlot::resizeEvent(QResizeEvent *event)
{
    _size   = event->size();
    _ratio.setX(double(_size.width() - (_margin.x() * 2))/double(_max.x()));
    _ratio.setY(double(_size.height() - (_margin.x() * 2))/double(_max.y()));
}

void QPlot::build()
{
    _painter.begin(this);

    _painter.setRenderHint(QPainter::Antialiasing);
    _painter.setRenderHint(QPainter::HighQualityAntialiasing);

    _painter.fillRect(0, 0, _size.width(), _size.height(), _background);

    _painter.setPen(QPen(_axisColor, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    _painter.setBrush(_axisColor);

    _painter.rotate(-90);
    _painter.drawText(QPoint( -_margin.y() - (_legend.second.size() * 6),
                              _margin.y()/2), _legend.second);
    _painter.rotate(90);
    _painter.drawText(QPoint(_size.width() - _margin.x() - (_legend.first.size() * 6),
                             _size.height() - _margin.y()/2 + 5), _legend.first);

    _painter.drawLine(_margin.x(), _margin.y(),
                      _margin.x(), _size.height() - _margin.y());
    _painter.drawLine(_margin.x(), _size.height() - _margin.y(),
                      _size.width() - _margin.x(), _size.height() - _margin.y());

    int     max         = _max.x()/_precision.x();
    double  precision   = double(_precision.x()) * _ratio.x();
    int     tmp         = 0;

    for (int i=0; i <= max; ++i) {
        tmp = _margin.x() + int(double(i) * precision);
        _painter.drawLine(tmp, _size.height() - _margin.y(),
                          tmp, _size.height() - _margin.y() + 7);
    }

    max         = _max.y()/_precision.y();
    precision   = double(_precision.y()) * _ratio.y();

    for (int i=0; i <= max; ++i) {
        tmp = _margin.y() + int(double(i) * precision);
        _painter.drawLine(_margin.x(), tmp, _margin.x() - 7, tmp);
    }

    _painter.end();
}

void QPlot::setAxisColor(const QColor &axisColor)
{
    _axisColor = axisColor;
}


