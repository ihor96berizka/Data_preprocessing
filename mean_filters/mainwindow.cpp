#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
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

    clearAllData = new QAction(tr("Clear all data"), this);
    connect(clearAllData, &QAction::triggered, this, &MainWindow::clearAllDataSlot);
}

void MainWindow::createMenus()
{
    signalMenu = menuBar()->addMenu(tr("Signals"));
    signalMenu->addActions({genDiscreteNumSignal, genSinSignal, clearAllData});

    filterMenu = menuBar()->addMenu(tr("Filters"));

    meanFilters = filterMenu->addMenu(tr("Mean filters"));
    meanFilters->addActions({newMeanFilter, movingMeanFilter, expSmoothFilter});
}

void MainWindow::genDiscreteNumSignalSlot()
{

}

void MainWindow::genSinSignalSlot()
{

}

void MainWindow::newMeanFilterSlot()
{

}

void MainWindow::movingMeanFilterSlot()
{

}

void MainWindow::expSmoothFilterSlot()
{

}

void MainWindow::clearAllDataSlot()
{

}
