#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QScatterSeries>


using namespace QtCharts;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //menu and buttons
    QMenu* signalMenu;
    QMenu* filterMenu;
    QMenu* meanFilters;

    QAction* genDiscreteNumSignal;
    QAction* genSinSignal;

    QAction* newMeanFilter;
    QAction* movingMeanFilter;
    QAction* expSmoothFilter;
    QAction* medianFilter;

    QAction* clearAllData;

    //chart routine
    QChartView* chartView;
    QChart* chart;
    QScatterSeries* realSignalSeries;
    QScatterSeries* filteredSignalSeries;
    QScatterSeries* idealSignalSeries;

//vectors with sampled signals
    const size_t numberOfSamples;
    std::vector<double> realSignal;
    std::vector<double> filteredSignal;
    std::vector<double> idealSignal;

    void createActions();
    void createMenus();
private slots:
    void genDiscreteNumSignalSlot();
    void genSinSignalSlot();
    void newMeanFilterSlot();
    void movingMeanFilterSlot();
    void expSmoothFilterSlot();
    void medianFilterSlot();
    void clearAllDataSlot();
};

#endif // MAINWINDOW_H
