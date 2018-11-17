#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "data_generators/discrete_distribution.h"
#include "filters/median.h"
#include "filters/newmean.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    numberOfSamples(50),
    realSignal(numberOfSamples), filteredSignal(numberOfSamples), idealSignal(numberOfSamples)
{
    ui->setupUi(this);
    createActions();
    createMenus();

    chart = new QChart();
    chartView = new QChartView(chart, this);

    realSignalSeries = new QScatterSeries();
    realSignalSeries->setName("Real signal");
    realSignalSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    realSignalSeries->setMarkerSize(10);

    idealSignalSeries = new QScatterSeries();
    idealSignalSeries->setName("Ideal signal");
    idealSignalSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    idealSignalSeries->setMarkerSize(10);

    filteredSignalSeries = new QScatterSeries();
    filteredSignalSeries->setName("Filtered signal");
    filteredSignalSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    filteredSignalSeries->setMarkerSize(10);

    chart->addSeries(realSignalSeries);
    chart->addSeries(idealSignalSeries);
    chart->addSeries(filteredSignalSeries);
    chart->createDefaultAxes();

    setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    genDiscreteNumSignal = new QAction(tr("Discrete signal"), this);
    connect(genDiscreteNumSignal, &QAction::triggered, this, &MainWindow::genDiscreteNumSignalSlot);

    genSinSignal = new QAction(tr("Sin signal"), this);
    connect(genSinSignal, &QAction::triggered, this, &MainWindow::genSinSignalSlot);

    newMeanFilter = new QAction(tr("New mean"), this);
    connect(newMeanFilter, &QAction::triggered, this, &MainWindow::newMeanFilterSlot);

    movingMeanFilter = new QAction(tr("Moving mean"), this);
    connect(movingMeanFilter, &QAction::triggered, this, &MainWindow::movingMeanFilterSlot);

    expSmoothFilter = new QAction(tr("Exp smoothing"), this);
    connect(expSmoothFilter, &QAction::triggered, this, &MainWindow::expSmoothFilterSlot);

    medianFilter = new QAction(tr("Median"), this);
    connect(medianFilter, &QAction::triggered, this, &MainWindow::medianFilterSlot);

    clearAllData = new QAction(tr("Clear all data"), this);
    connect(clearAllData, &QAction::triggered, this, &MainWindow::clearAllDataSlot);
}

void MainWindow::createMenus()
{
    signalMenu = menuBar()->addMenu(tr("Signals"));
    signalMenu->addActions({genDiscreteNumSignal, genSinSignal, clearAllData});

    filterMenu = menuBar()->addMenu(tr("Filters"));
    filterMenu->addAction(medianFilter);

    meanFilters = filterMenu->addMenu(tr("Mean filters"));
    meanFilters->addActions({newMeanFilter, movingMeanFilter, expSmoothFilter});
}

void MainWindow::genDiscreteNumSignalSlot()
{
    realSignalSeries->clear();

    realSignal = data_generator::getDiscreteVector(numberOfSamples);
    int min_t = -1;
    int max_t = numberOfSamples + 1;

    double maxAmp = *std::max_element(realSignal.cbegin(), realSignal.cend());
    double minAmp = *std::min_element(realSignal.cbegin(), realSignal.cend());
    maxAmp += abs(maxAmp)*0.1;
    minAmp -= abs(minAmp) * 0.1;

    for (size_t i = 0; i < numberOfSamples; ++i)
    {
        qDebug() << i << " | " << realSignal[i];
        realSignalSeries->append(i, realSignal[i]);
    }
    chart->axisX()->setRange(min_t, max_t);
    chart->axisY()->setRange(minAmp, maxAmp);
}

void MainWindow::genSinSignalSlot()
{

}

void MainWindow::newMeanFilterSlot()
{
    filteredSignalSeries->clear();
    filteredSignal = filter::newMean(realSignal);
    qDebug() << "Filtered";
    for (size_t i = 0; i < filteredSignal.size(); ++i)
    {
        qDebug() << i << " | " << filteredSignal[i];
        filteredSignalSeries->append(i, filteredSignal[i]);
    }
}

void MainWindow::movingMeanFilterSlot()
{

}

void MainWindow::expSmoothFilterSlot()
{

}

void MainWindow::medianFilterSlot()
{
    filteredSignalSeries->clear();
    size_t window_size = 2;
    filteredSignal = filter::Median(realSignal, window_size);

    for (size_t i = 0; i < filteredSignal.size(); ++i)
    {
        qDebug() << i << " | " << filteredSignal[i];
        filteredSignalSeries->append(i, filteredSignal[i]);
    }
}

void MainWindow::clearAllDataSlot()
{
    realSignalSeries->clear();
    idealSignalSeries->clear();
    filteredSignalSeries->clear();
}
