#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playlistAlgorithm.h"

int playlistLength =101;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << 5;
    MainWindow::plot();

}

MainWindow::~MainWindow()
{
    delete ui;

}





/*void QCustomPlot::myFunc(int j)
{
    qDebug() << "CHANGEGGGG";
    QCPGraph *graph = ui->plot->graph(1);
    graph->setSelectable(QCP::stDataRange);
    QCustomPlot *customPlot = ui->plot;
    foreach (QCPDataRange dataRange, QCPDataSelection(graph->selection()).dataRanges())
    {
      QCPGraphDataContainer::const_iterator begin = graph->data()->at(dataRange.begin()); // get range begin iterator from index
      QCPGraphDataContainer::const_iterator end = graph->data()->at(dataRange.end()); // get range end iterator from index
      for (QCPGraphDataContainer::const_iterator it=begin; it!=end; ++it)
      {
        // iterator "it" will go through all selected data points, as an example, we calculate the value average
        //sum += it->value;
        int tempKey= it->mainKey();
        graph->data()->remove(it->mainKey());
        graph->addData(tempKey+0.3,10);

      }
    }
}*/



void MainWindow::plot()
{
    QCustomPlot *customPlot = ui->plot;
    //ui->plot->addGraph();
    //ui->plot->setDragInfo(0, 20); // data of graph(0) is dragable, 20px margin
    //connect(ui->plot,&EQWidget::DataChanged,this,&MainWindow::RebuildResultGraph);

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plot->addGraph();

    //INTERACTION CODE

    ui->plot->setInteractions(QCP::iSelectAxes |  QCP::iSelectPlottables);   // Axis, legend and chart can be selected in multiple ways
    ui->plot->setSelectionRectMode(QCP::srmSelect);
    ui->plot->xAxis->setSelectableParts(QCPAxis::spAxis | QCPAxis::spAxisLabel | QCPAxis::spTickLabels);   // All three parts of the shaft can be selected
    ui->plot->yAxis->setSelectableParts(QCPAxis::spAxis | QCPAxis::spAxisLabel | QCPAxis::spTickLabels);




    //END INTERACTION CODE

    QPen pen;

    for (int i = 0; i <= 0; ++i) //Replace 0 with QCPGraph::lsImpulse for the multiple graphs.
    {
        ui->plot->addGraph();
        pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
        ui->plot->graph()->setPen(pen);       // Set the brush for the chart
        ui->plot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));  // Sets the style of the chart scatter chart
        int length = 36;

        QVector<double> x, y;


        int count = 0;

        if(length < NUM_POINTS){
            x.push_back(0);
            y.push_back(100);
            x.push_back(length);
            y.push_back(100);
        }
        else{
            for(int i = 0; i < length; i += length/NUM_POINTS){
                x.push_back(i);
                y.push_back(100);
                count++;
            }
            if(abs(x[count-1] - length) > length/NUM_POINTS*2){
                x.push_back(length);
                y.push_back(100);
                count++;
            }
        }




        /*
        int length = 20;
        int seperatation  = length/NUM_POINTS;
        int j;
        for (j=0; j<NUM_POINTS; ++j)
        {
            x[j] = j*seperatation;
            y[j] = 100;
        }
        x[NUM_POINTS] = length;
        y[NUM_POINTS] = 100;
        */

        ui->plot->graph()->setData(x, y);
        ui->plot->graph()->rescaleAxes(true);
    }
    // Zoom in a little bit
    ui->plot->yAxis->scaleRange(1.1, ui->plot->yAxis->range().center());
    ui->plot->xAxis->scaleRange(1.1, ui->plot->xAxis->range().center());
        ui->plot->setSelectionRectMode(QCP::srmSelect);

    for (int i=1; i <= 1; ++i) {
        QCPGraph *graph = ui->plot->graph(i);
    graph->setSelectable(QCP::stDataRange);






    if(graph->selected()) qDebug() <<  QCPDataSelection(graph->selection()).isEmpty();
    QSlider *tempSlider = ui->slider;


    connect(ui->slider, &QSlider::valueChanged, [graph,tempSlider,customPlot](){
        qDebug() <<"Slider Value=";
        qDebug() << tempSlider->value();
        int maxGraphHieght = 100;
        int setValue = maxGraphHieght*tempSlider->value()/100; //35 is the max range for this graph
        qDebug() <<"Set Value=";
        qDebug() << setValue;
            QCPDataSelection selection = QCPDataSelection(graph->selection());
        qDebug() << "Start";
        qDebug() << selection.isEmpty();
        qDebug() << "graph->dataCount()";
        qDebug() << graph->dataCount();
        int sum =0;
        foreach (QCPDataRange dataRange, QCPDataSelection(graph->selection()).dataRanges())
        {
          QCPGraphDataContainer::const_iterator begin = graph->data()->at(dataRange.begin()); // get range begin iterator from index
          QCPGraphDataContainer::const_iterator end = graph->data()->at(dataRange.end()); // get range end iterator from index
          for (QCPGraphDataContainer::const_iterator it=begin; it!=end; ++it)
          {
               qDebug() << "ACTIVE";
            // iterator "it" will go through all selected data points, as an example, we calculate the value average
            sum += it->value;
            int tempKey= it->mainKey();
            graph->data()->remove(it->mainKey());
            graph->addData(tempKey,setValue);
            customPlot->replot();

          }
        }
            //QCPDataSelection(graph->data()->dataRange());
            //graph->selection().clear();

                    qDebug() << "end";
                    qDebug() << "Sum =";
                    qDebug() << sum;


     });

    /*connect(customPlot, &QCustomPlot::selectionChangedByUser, [graph](){
            QCPDataSelection selection = QCPDataSelection(graph->selection());
        qDebug() << "Start";
        qDebug() << selection.isEmpty();
        qDebug() << "graph->dataCount()";
        qDebug() << graph->dataCount();
        int sum =0;
        foreach (QCPDataRange dataRange, QCPDataSelection(graph->selection()).dataRanges())
        {
          QCPGraphDataContainer::const_iterator begin = graph->data()->at(dataRange.begin()); // get range begin iterator from index
          QCPGraphDataContainer::const_iterator end = graph->data()->at(dataRange.end()); // get range end iterator from index
          for (QCPGraphDataContainer::const_iterator it=begin; it!=end; ++it)
          {
            // iterator "it" will go through all selected data points, as an example, we calculate the value average
            sum += it->value;
            int tempKey= it->mainKey();
            graph->data()->remove(it->mainKey());
            graph->addData(tempKey+0.3,sum);

          }
        }
            //QCPDataSelection(graph->data()->dataRange());
            //graph->selection().clear();

                    qDebug() << "end";
                    qDebug() << "Sum =";
                    qDebug() << sum;


     });*/


    }


    /*
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-1, 1);
    ui->plot->yAxis->setRange(0, 1);
    ui->plot->replot();
    */

}




void MainWindow::on_pushButton_2_clicked()
{
 int xvalue = 0;
 int yvalue = 0;
 int point = 0;
 graph myGraph;
 vector<graph> InputGraphs;
 vector<dataPoint> myDataSet;
 qDebug() << "HI"; //QCPDataSelection(graph->selection()).dataRanges()

   QCPGraphDataContainer::const_iterator begin =  ui->plot->graph(1)->data()->at(ui->plot->graph(1)->data()->dataRange().begin()); // get range begin iterator from index
   QCPGraphDataContainer::const_iterator end =  ui->plot->graph(1)->data()->at(ui->plot->graph(1)->data()->dataRange().end()); // get range end iterator from index
   for (QCPGraphDataContainer::const_iterator it=begin; it!=end; ++it)
   {
      dataPoint initalizedPoint;
      point++;
     // iterator "it" will go through all selected data points, as an example, we calculate the value average
      yvalue = it->value;
      xvalue= it->mainKey();
      //qDebug() <<  "Point" << point<< " = (" << xvalue << ","<< yvalue <<")";
      initalizedPoint.time_minutes = xvalue;
      initalizedPoint.value = yvalue;
      myDataSet.push_back(initalizedPoint);

   }
   myGraph.points = myDataSet;
   myGraph.variableName = "Energy";
   for(int i =0; i<myGraph.points.size();i++)
   cout << myGraph.points[i].value<< endl;
   InputGraphs.push_back(myGraph);
   PlaylistGenerator myPlaylistGenerator(InputGraphs, 30);
   myPlaylistGenerator.generatePlaylists();
}

