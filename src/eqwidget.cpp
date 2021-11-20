#include "eqwidget.h"

EQWidget::EQWidget(QWidget* parent) : QCustomPlot(parent)
{

}

void EQWidget::setDragInfo(int graph, int distance)
{
    dragable_graph_number = graph;
    max_distance_to_add_point = distance;
}

void EQWidget::mousePressEvent(QMouseEvent *event)
{
    double x,y;

    double best_dist = 1E+300;
    int best_index = 0;
    if( (dragable_graph_number >= 0) && ( dragable_graph_number < this->graphCount()) )
    {
        QCPGraph* pq_graph = this->graph(dragable_graph_number);
        pq_graph->pixelsToCoords(event->localPos(),x,y);
        if( pq_graph->data()->size() >= 1 )
        {
            for( int n=0; n<(pq_graph->data()->size()); n++ )
            {
                double dist = fabs( (pq_graph->data()->begin()+n)->value - y );
                dist += fabs( (pq_graph->data()->begin()+n)->key - x );
                if( dist < best_dist )
                {
                    best_dist = dist;
                    best_index = n;
                }
            }
            if( max_distance_to_add_point > 0 )
            {
                QPointF q_pos_gui = pq_graph->coordsToPixels( (pq_graph->data()->begin()+best_index)->key, (pq_graph->data()->begin()+best_index)->value );
                int dist_px = fabs( event->localPos().x() - q_pos_gui.x()) +  fabs( event->localPos().y() - q_pos_gui.y());
                if( dist_px/2 > max_distance_to_add_point )
                {
                    pq_graph->addData(x,y);
                    pq_graph->data().data()->sort();
                    for( int n=0; n<(pq_graph->data()->size()); n++ )
                    {
                        if(  (pq_graph->data()->begin()+n)->value == y && (pq_graph->data()->begin()+n)->key == x ) best_index = n;
                    }
                }
            }
            drag_number = best_index;
        }
    }
    QCustomPlot::mousePressEvent(event);
}

void EQWidget::mouseReleaseEvent(QMouseEvent *event)
{
    drag_number = -1;
    if( (dragable_graph_number >= 0) && ( dragable_graph_number < this->graphCount()) )
    {
        this->graph(dragable_graph_number)->data().data()->sort();
    }
    this->replot();
    emit( EditingFinished() );
    QCustomPlot::mouseReleaseEvent(event);
}

void EQWidget::mouseMoveEvent(QMouseEvent *event)
{
    double x,y;

    if( (dragable_graph_number >= 0) && ( dragable_graph_number < this->graphCount()) )
    {
        QCPGraph* pq_graph = this->graph(dragable_graph_number);
        pq_graph->pixelsToCoords(event->localPos(),x,y);

        y = round( y*16 ) / 16; //snap to grid
        x = round( x*4 ) / 4; //snap to grid

        if( drag_number >= 0 )
        {
            (pq_graph->data()->begin()+drag_number)->value = y;
            (pq_graph->data()->begin()+drag_number)->key = x;
            emit( DataChanged() );
            this->replot();
        }
    }
}
