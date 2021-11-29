#include <CreatePlaylistPage.h>
#include <ui_createplaylistpage.h>
#include <PlaylistAlgorithm.h>

int playlistLength = 36;
vector<graph> InputGraphs;
vector<graph> FinalGraphs;

CreatePlaylistPage::CreatePlaylistPage(PlaylistGenerator *playgen, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CreatePlaylistPage) {
    ui->setupUi(this);
    qDebug() << 5;
    CreatePlaylistPage::plot();

    this->playgen = playgen;

    this->buttonResetTimer = new QTimer();
    this->buttonResetTimer->setInterval(3000);
    this->buttonResetTimer->setSingleShot(true);
    connect(buttonResetTimer, &QTimer::timeout, this, &CreatePlaylistPage::resetButton);

    connect(playgen, &PlaylistGenerator::playlistGenerating, this, &CreatePlaylistPage::onPlaylistGenerating);
    connect(playgen, &PlaylistGenerator::playlistCompleted, this, &CreatePlaylistPage::onPlaylistCreated);

}

CreatePlaylistPage::~CreatePlaylistPage() {
    delete ui;

}

void CreatePlaylistPage::plot() {
    QCustomPlot *customPlot = ui->plot;

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i = 0; i < 101; ++i) {
        x[i] = i / 50.0 - 1; // x goes from -1 to 1
        y[i] = x[i] * x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plot->addGraph();

    //INTERACTION CODE

    ui->plot->setInteractions(
            QCP::iSelectAxes | QCP::iSelectPlottables);   // Axis, legend and chart can be selected in multiple ways
    ui->plot->setSelectionRectMode(QCP::srmSelect);
    ui->plot->xAxis->setSelectableParts(QCPAxis::spAxis | QCPAxis::spAxisLabel |
                                        QCPAxis::spTickLabels);   // All three parts of the shaft can be selected
    ui->plot->yAxis->setSelectableParts(QCPAxis::spAxis | QCPAxis::spAxisLabel | QCPAxis::spTickLabels);

    //END INTERACTION CODE

    QPen pen;

    for (int i = 0; i <= 0; ++i) //Replace 0 with QCPGraph::lsImpulse for the multiple graphs.
    {
        ui->plot->addGraph();
        pen.setColor(QColor(qSin(i * 1 + 1.2) * 80 + 80, qSin(i * 0.3 + 0) * 80 + 80, qSin(i * 0.3 + 1.5) * 80 + 80));
        ui->plot->graph()->setPen(pen);       // Set the brush for the chart
        ui->plot->graph()->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle, 5));  // Sets the style of the chart scatter chart

        QVector<double> x, y;

        int count = 0;

        if (playlistLength < NUM_POINTS) {
            x.push_back(0);
            y.push_back(100);
            x.push_back(playlistLength);
            y.push_back(100);
        } else {
            for (int i = 0; i < playlistLength; i += playlistLength / NUM_POINTS) {
                x.push_back(i);
                y.push_back(100);
                count++;
            }
            if (abs(x[count - 1] - playlistLength) > playlistLength / NUM_POINTS * 2) {
                x.push_back(playlistLength);
                y.push_back(100);
                count++;
            }
        }

        ui->plot->graph()->setData(x, y);
        ui->plot->graph()->rescaleAxes(true);
    }
    // Zoom in a little bit
    ui->plot->yAxis->scaleRange(1.1, ui->plot->yAxis->range().center());
    ui->plot->xAxis->scaleRange(1.1, ui->plot->xAxis->range().center());
    ui->plot->setSelectionRectMode(QCP::srmSelect);

    for (int i = 1; i <= 1; ++i) {
        QCPGraph *graph = ui->plot->graph(i);
        graph->setSelectable(QCP::stDataRange);


        if (graph->selected()) qDebug() << QCPDataSelection(graph->selection()).isEmpty();
        QSlider *tempSlider = ui->slider;
        QComboBox *myCombo = ui->comboBox;
        QRadioButton *myRadioButton = ui->radioButton;


        connect(ui->slider, &QSlider::valueChanged, [graph, tempSlider, customPlot]() {
            qDebug() << "Slider Value=";
            qDebug() << tempSlider->value();
            int maxGraphHieght = 100;
            int setValue = maxGraphHieght * tempSlider->value() / 100; //35 is the max range for this graph
            qDebug() << "Set Value=";
            qDebug() << setValue;
            QCPDataSelection selection = QCPDataSelection(graph->selection());
            qDebug() << "Start";
            qDebug() << selection.isEmpty();
            qDebug() << "graph->dataCount()";
            qDebug() << graph->dataCount();
            int sum = 0;
                    foreach (QCPDataRange dataRange, QCPDataSelection(graph->selection()).dataRanges()) {
                    QCPGraphDataContainer::const_iterator begin = graph->data()->at(
                            dataRange.begin()); // get range begin iterator from index
                    QCPGraphDataContainer::const_iterator end = graph->data()->at(
                            dataRange.end()); // get range end iterator from index
                    for (QCPGraphDataContainer::const_iterator it = begin; it != end; ++it) {
                        qDebug() << "ACTIVE";
                        // iterator "it" will go through all selected data points, as an example, we calculate the value average
                        sum += it->value;
                        int tempKey = it->mainKey();
                        graph->data()->remove(it->mainKey());
                        graph->addData(tempKey, setValue);
                        customPlot->replot();

                    }
                }
            qDebug() << "end";
            qDebug() << "Sum =";
            qDebug() << sum;


        });
        QLineEdit *myTimeEdit = ui->timeInput;

        connect(ui->setTimeButton, &QPushButton::pressed,
                [graph, tempSlider, customPlot, myCombo, myRadioButton, myTimeEdit]() {
                    int count = 0;
                    qDebug() << "try and set time";
                    InputGraphs.clear();
                    playlistLength = myTimeEdit->text().toInt();
                    QVector<double> x, y;
                    myRadioButton->setChecked(false);
                    if (playlistLength < NUM_POINTS) {
                        x.push_back(0);
                        y.push_back(100);
                        x.push_back(playlistLength);
                        y.push_back(100);
                    } else {
                        for (int i = 0; i < playlistLength; i += playlistLength / NUM_POINTS) {
                            x.push_back(i);
                            y.push_back(100);
                            count++;
                        }
                        if (abs(x[count - 1] - playlistLength) > playlistLength / NUM_POINTS * 2) {
                            x.push_back(playlistLength);
                            y.push_back(100);
                            count++;
                        }
                    }
                    graph->setData(x, y);
                    graph->rescaleAxes(true);
                    customPlot->replot();
                    qDebug() << "Set time Successful";


                });

        connect(ui->comboBox, &QComboBox::currentTextChanged,
                [graph, tempSlider, customPlot, myCombo, myRadioButton]() {
                    qDebug() << "Combo Box Value Changed =" << myCombo->currentText() << endl;
                    QVector<double> x, y;
                    struct graph newGraph;

                    bool foundGraph = false;


                    for (int i = 0; i < InputGraphs.size(); i++) {
                        if (InputGraphs[i].variableName == myCombo->currentText().toStdString()) {
                            foundGraph = true;
                            for (int j = 0; j < InputGraphs[i].points.size(); j++) {// Reload graph
                                qDebug() << "Reload Graph";
                                qDebug() << "y = " << InputGraphs[i].points[j].value;
                                qDebug() << "x = " << InputGraphs[i].points[j].time_minutes;
                                y.push_back(InputGraphs[i].points[j].value);
                                x.push_back(InputGraphs[i].points[j].time_minutes);
                                myRadioButton->setChecked(InputGraphs[i].activeGraph);
                            }
                        }
                    }

                    if (!foundGraph) // setup new graph if there has not been a graph found
                    {
                        qDebug() << "graph not found";
                        int count = 0;
                        myRadioButton->setChecked(false);
                        if (playlistLength < NUM_POINTS) {
                            x.push_back(0);
                            y.push_back(100);
                            x.push_back(playlistLength);
                            y.push_back(100);
                        } else {
                            for (int i = 0; i < playlistLength; i += playlistLength / NUM_POINTS) {
                                x.push_back(i);
                                y.push_back(100);
                                count++;
                            }
                            if (abs(x[count - 1] - playlistLength) > playlistLength / NUM_POINTS * 2) {
                                x.push_back(playlistLength);
                                y.push_back(100);
                                count++;
                            }
                        }
                    }
                    graph->setData(x, y);
                    graph->rescaleAxes(true);
                    customPlot->replot();
                    qDebug() << "completed";

                });

        connect(ui->comboBox, &QComboBox::textHighlighted, [graph, tempSlider, customPlot, myCombo, myRadioButton]() {
            qDebug() << "Combo Box=";

            bool foundGraph = false;
            int xvalue = 0;
            int yvalue = 0;
            struct graph newGraph;
            int point = 0;
            vector<dataPoint> myDataSet;

            //Adds/Updates graph in the vector of graphs
            QCPGraphDataContainer::const_iterator begin = graph->data()->at(
                    graph->data()->dataRange().begin()); // get range begin iterator from index
            QCPGraphDataContainer::const_iterator end = graph->data()->at(
                    graph->data()->dataRange().end()); // get range end iterator from index
            for (QCPGraphDataContainer::const_iterator it = begin; it != end; ++it) {
                dataPoint initalizedPoint;
                point++;
                // iterator "it" will go through all selected data points, as an example, we calculate the value average
                yvalue = it->value;
                xvalue = it->mainKey();
                initalizedPoint.time_minutes = xvalue;
                initalizedPoint.value = yvalue;
                myDataSet.push_back(initalizedPoint);

            }

            qDebug() << myCombo->currentText() << endl;
            if (InputGraphs.empty()) {

                newGraph.variableName = myCombo->currentText().toStdString();
                newGraph.points = myDataSet;
                InputGraphs.push_back(newGraph);
                newGraph.activeGraph = myRadioButton->isChecked();

            } else {
                for (int i = 0; i < InputGraphs.size(); i++) {
                    if (InputGraphs[i].variableName == myCombo->currentText().toStdString()) {
                        InputGraphs[i].points = myDataSet;
                        InputGraphs[i].activeGraph = myRadioButton->isChecked();
                        foundGraph = true;
                    }
                }
            }
            if (!foundGraph) { // if we couldnt find a graph so create a new graph
                newGraph.variableName = myCombo->currentText().toStdString();
                newGraph.points = myDataSet;
                InputGraphs.push_back(newGraph);
                newGraph.activeGraph = false;
            }
        });


        connect(ui->pushButton_2, &QPushButton::pressed, [graph, tempSlider, customPlot, myCombo, myRadioButton]() {
            qDebug() << "Combo Box=";


            bool foundGraph = false;
            int xvalue = 0;
            int yvalue = 0;
            struct graph newGraph;
            int point = 0;
            vector<dataPoint> myDataSet;

            //Adds/Updates graph in the vector of graphs
            QCPGraphDataContainer::const_iterator begin = graph->data()->at(
                    graph->data()->dataRange().begin()); // get range begin iterator from index
            QCPGraphDataContainer::const_iterator end = graph->data()->at(
                    graph->data()->dataRange().end()); // get range end iterator from index
            for (QCPGraphDataContainer::const_iterator it = begin; it != end; ++it) {
                dataPoint initalizedPoint;
                point++;
                // iterator "it" will go through all selected data points, as an example, we calculate the value average
                yvalue = it->value;
                xvalue = it->mainKey();
                initalizedPoint.time_minutes = xvalue;
                initalizedPoint.value = yvalue;
                myDataSet.push_back(initalizedPoint);

            }

            qDebug() << myCombo->currentText() << endl;
            if (InputGraphs.empty()) {

                newGraph.variableName = myCombo->currentText().toStdString();
                newGraph.points = myDataSet;
                InputGraphs.push_back(newGraph);
                newGraph.activeGraph = myRadioButton->isChecked();

            } else {
                for (int i = 0; i < InputGraphs.size(); i++) {
                    if (InputGraphs[i].variableName == myCombo->currentText().toStdString()) {
                        InputGraphs[i].points = myDataSet;
                        InputGraphs[i].activeGraph = myRadioButton->isChecked();
                        foundGraph = true;
                    }
                }
            }
            if (!foundGraph) // if we couldnt find a graph so create a new graph
            {
                newGraph.variableName = myCombo->currentText().toStdString();
                newGraph.points = myDataSet;
                InputGraphs.push_back(newGraph);
                newGraph.activeGraph = false;
            }
        });
    }
}


void CreatePlaylistPage::on_pushButton_2_clicked() {

    graph myGraph;
    vector<dataPoint> myDataSet;
    qDebug() << "HI"; //QCPDataSelection(graph->selection()).dataRanges()
    FinalGraphs.clear(); // Resets final graph list with every button press


    bool alreadyInFinalGraph = false;
    for (int i = 0; i < InputGraphs.size(); i++) {
        if (InputGraphs[i].activeGraph && !alreadyInFinalGraph)
            FinalGraphs.push_back(InputGraphs[i]); // If the graph isnt already present, and
    }

    for (int i = 0; i < FinalGraphs.size(); i++) {
        qDebug() << "PRINTING";
        qDebug() << QString::fromStdString(FinalGraphs[i].variableName);
    }

    playgen->getGraphs(FinalGraphs, playlistLength);
    playgen->generatePlaylists();

    //ADD THIS
    playgen->addPlaylistToAccount();

}

void CreatePlaylistPage::onPlaylistGenerating() {
    this->ui->pushButton_2->setText("Playlist Generating!");
    this->ui->pushButton_2->setEnabled(false);
}

void CreatePlaylistPage::onPlaylistCreated() {
    this->ui->pushButton_2->setText("Playlist Created!");
    this->buttonResetTimer->start();
}

void CreatePlaylistPage::resetButton() {
    this->ui->pushButton_2->setText("Create Playlist");
    this->ui->pushButton_2->setEnabled(true);
}

