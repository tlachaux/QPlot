/*
 * QPlot example
 */
 
#include <QApplication>

#include "../QPlot.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPlot plotter(QPoint(100, 100), QPair<QString, QString>("time", "speed"));

    // Minimum size of the widget
    plotter.setMinimumSize(QSize(400, 400));

    // Background color
    plotter.setBackground(QColor(100, 100, 100));

    /* Margin :
     *
     *   |-----------------------|
     *   |       ^               |
     *   |       | mx/2          |
     *   |       v               |
     *   |                       |
     *   |      |                |
     *   | my/2 |         my/2   |
     *   |<---->|        <---->  |
     *   |      |                |
     *   |      |_______         |
     *   |       ^               |
     *   |       | mx/2          |
     *   |       v               |
     *   |_______________________|
     *
     *   QPoint(mx, my)
     *
     */
    plotter.setMargin(QPoint(50, 50));

    /* Precision :
     *
     *          ^
     *  4 * py -|
     *  3 * py -|
     *  2 * py -|
     *      py -|
     *       0 -|------------->
     *          0 px ...
     *
     *   QPoint(px, py)
     *
     */
    plotter.setPrecision(QPoint(1, 10));

    /* Steps :
     *
     *     ^
     *  4 -|
     *  3 -|
     *  2 -|  +(sx * x, sy * y)
     *  1 -|
     *  0 -|------------->
     *     0 1 2 3 4
     *
     *   QPoint(sx, sy)
     *
     */
    plotter.setStep(QPoint(1, 1));

    /*
     * Random test :
     */
    for (int i=0; i<100; ++i) {
        plotter.addPoint(30 + rand()%30);
    }

    plotter.show();
    return app.exec();
}

