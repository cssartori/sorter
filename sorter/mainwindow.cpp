#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    for(int i=0;i<this->SORT_NAMES.size();i++){
        this->ui->algList1->addItem(this->SORT_NAMES[i].c_str());
        this->ui->algList2->addItem(this->SORT_NAMES[i].c_str());
    }

    for(int i=0;i<this->VEC_NAMES.size();i++)
        this->ui->vectorList->addItem(this->VEC_NAMES[i].c_str());

    this->signaler = new SorterSignaler();
    connect(this->signaler, SIGNAL(percentChanged(double)), this, SLOT(on_signaler_percentChanged(double)));
    connect(this->signaler, SIGNAL(calcDone()), this, SLOT(on_signaler_calcDone()));

    this->xPoints = std::vector<double>(vSizes.begin(), vSizes.end());
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::getAlgFromList(QComboBox *algList){
    for(int i=0;i<this->SORT_NAMES.size();i++){
        if(algList->currentText().toStdString() == this->SORT_NAMES[i])
            return this->SORT_CODES[i];
    }

    return CODE_ERROR;
}

void MainWindow::on_compareBtn_clicked() {
    int alg1 = this->getAlgFromList(this->ui->algList1), alg2=this->getAlgFromList(this->ui->algList2);
    if(alg1 == CODE_ERROR || alg2 == CODE_ERROR){
        //TODO: print error message
        printf("WRONG algorithm\n");
        exit(-1);
    }

    std::vector<int> array = this->loadVector();
    this->sorter = new Sorter(alg1, alg2, array, vSizes, this->signaler);

    this->ui->progressBar->setValue(0);

    this->sorter->start(); //start sorter thread

}

void MainWindow::on_signaler_calcDone(){
    this->clearGraphic();
    this->on_timeRBtn_clicked();
}


void MainWindow::setupGraphic(std::vector<double> a1, std::vector<double> a2, std::string a1Name, std::string a2Name, int option){
    this->ui->graphic->addGraph();
    this->ui->graphic->addGraph();

    this->ui->graphic->graph(0)->setData(QVector<double>::fromStdVector(this->xPoints), QVector<double>::fromStdVector(a1));
    this->ui->graphic->graph(1)->setData(QVector<double>::fromStdVector(this->xPoints), QVector<double>::fromStdVector(a2));

    this->ui->graphic->graph(0)->addToLegend();
    this->ui->graphic->graph(1)->addToLegend();

    this->ui->graphic->graph(0)->setName(QString::fromStdString(a1Name));
    this->ui->graphic->graph(1)->setName(QString::fromStdString(a2Name));

    this->ui->graphic->graph(0)->setPen(QPen(Qt::black));
    this->ui->graphic->graph(1)->setPen(QPen(Qt::red));

    this->ui->graphic->legend->setVisible(true);
    this->ui->graphic->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

    this->ui->graphic->xAxis->setLabel("Vector Size");

    std::string ylabel;
    if(option == MainWindow::TIMES_PLOT_OPTION)
        ylabel = "Execution Time (sec.)";
    else if(option == MainWindow::SWAPS_PLOT_OPTION)
        ylabel = "Number of Swaps";
    else
        ylabel = "Number of Comparisons";
    this->ui->graphic->yAxis->setLabel(QString::fromStdString(ylabel));

    this->ui->graphic->rescaleAxes();
    this->ui->graphic->replot();
}

void MainWindow::clearGraphic(){
    this->ui->graphic->clearGraphs();
    this->ui->graphic->clearItems();
    this->ui->timeRBtn->setChecked(false);
    this->ui->compareRBtn->setChecked(false);
    this->ui->swapsRBtn->setChecked(false);
}

std::vector<int> MainWindow::loadVector(){
    int* a = (int*)malloc(sizeof(int)*vSizes[vSizes.size()-1]);
    int fileType = 1;

    for(int i=0;i<this->VEC_NAMES.size();i++){
        if(this->ui->vectorList->currentText().toStdString() == this->VEC_NAMES[i]){
            fileType = this->VEC_CODES[i];
        }
    }

    std::string filename;

    if(fileType == ORDERED_VECTOR_MAX_MIN || fileType == ORDERED_VECTOR_MIN_MAX)
        filename = ORDERED_VECTOR_FILENAME;
    else
        filename = RANDOM_VECTOR_FILENAME;

    FILE *file = fopen(filename.c_str(), "rb");
    if(!file){
        //TODO: print error message
        printf("File %s does not exist.\n", filename.c_str());
        exit(-1);
    }

    fread(a, sizeof(int)*vSizes[vSizes.size()-1], 1, file);

    std::vector<int> array(vSizes[vSizes.size()-1]);

    for(int i=0;i<array.size();i++){
        if(fileType != ORDERED_VECTOR_MAX_MIN)
            array[i] = a[i];
        else
            array[i] = a[array.size()-1-i]; //reverse ordered vector
    }

    return array;
}

void MainWindow::on_signaler_percentChanged(double percent){
    this->ui->progressBar->setValue(percent);
}

void MainWindow::on_timeRBtn_clicked() {
    if(this->sorter == nullptr)
        return;

    this->clearGraphic();
    this->ui->timeRBtn->setChecked(true);
    this->setupGraphic(this->sorter->getTimes().first, this->sorter->getTimes().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->TIMES_PLOT_OPTION);
}

void MainWindow::on_swapsRBtn_clicked() {
    if(this->sorter == nullptr)
        return;

    this->clearGraphic();
    this->ui->swapsRBtn->setChecked(true);
    this->setupGraphic(this->sorter->getSwaps().first, this->sorter->getSwaps().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->SWAPS_PLOT_OPTION);
}

void MainWindow::on_compareRBtn_clicked() {
    if(this->sorter == nullptr)
        return;

    this->clearGraphic();
    this->ui->compareRBtn->setChecked(true);
    this->setupGraphic(this->sorter->getComparisons().first, this->sorter->getComparisons().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->COMPS_PLOT_OPTION);
}
