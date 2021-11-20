#ifndef EQWIDGET_H
#define EQWIDGET_H

#include "qcustomplot.h"


class EQWidget : public QCustomPlot
{
    Q_OBJECT
public:
    EQWidget(QWidget* parent);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setDragInfo( int graph = -1, int distance = -1);
signals:
    void DataChanged( void );
    void EditingFinished(void);
private:
    int drag_number = -1;
    int dragable_graph_number = -1;
    int max_distance_to_add_point = -1;
};

#endif // EQWIDGET_H
