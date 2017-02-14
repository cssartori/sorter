#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "infomessage.h"

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
    connect(this->ui->clearGraphicOpt, SIGNAL(triggered(bool)), this, SLOT(on_clearGraphicOpt_triggered(bool)));


    this->xPoints = std::vector<double>(vSizes.begin(), vSizes.end());
    this->xPoints.insert(this->xPoints.begin(), 0);
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
    if(this->sorter != nullptr && this->sorter->isRunning()){
        InfoMessage::processRunningErrorMsg(this);
        return;
    }

    int alg1 = this->getAlgFromList(this->ui->algList1), alg2=this->getAlgFromList(this->ui->algList2);
    if((alg1 == CODE_ERROR || alg2 == CODE_ERROR) || (alg1 == Sorter::NO_SORT_METHOD && alg2 == Sorter::NO_SORT_METHOD)){
        InfoMessage::algNotChosenErrorMsg(this);
        return;
    }

    if(this->sorter != nullptr)
        delete this->sorter;

    std::vector<int> array = this->loadVector();
    if(array.size() == 0)
        return;

    this->sorter = new Sorter(alg1, alg2, array, vSizes, this->signaler);

    this->ui->progressBar->setValue(0);

    this->clearGraphic();
    this->sorter->start(); //start sorter thread

    this->ui->compareBtn->setEnabled(false);
    this->ui->cancelBtn->setEnabled(true);
}

void MainWindow::on_signaler_calcDone(){
    this->clearGraphic();
    this->on_timeRBtn_clicked();
    this->ui->compareBtn->setEnabled(true);
    this->ui->cancelBtn->setEnabled(false);
}


void MainWindow::setupGraphic(std::vector<double> a1, std::vector<double> a2, std::string a1Name, std::string a2Name, int option){
    int gi = 0; //graph index
    if(this->sorter->getAlgs().first != Sorter::NO_SORT_METHOD){
        this->ui->graphic->addGraph();
        a1.insert(a1.begin(), 0);
        this->ui->graphic->graph(gi)->setData(QVector<double>::fromStdVector(this->xPoints), QVector<double>::fromStdVector(a1));
        this->ui->graphic->graph(gi)->addToLegend();
        this->ui->graphic->graph(gi)->setName(QString::fromStdString(a1Name));
        this->ui->graphic->graph(gi)->setPen(QPen(Qt::black));
        gi++;
    }

    if(this->sorter->getAlgs().second != Sorter::NO_SORT_METHOD){
        this->ui->graphic->addGraph();
        a2.insert(a2.begin(), 0);
        this->ui->graphic->graph(gi)->setData(QVector<double>::fromStdVector(this->xPoints), QVector<double>::fromStdVector(a2));
        this->ui->graphic->graph(gi)->addToLegend();
        this->ui->graphic->graph(gi)->setName(QString::fromStdString(a2Name));
        this->ui->graphic->graph(gi)->setPen(QPen(Qt::red));
        gi++;
    }

    if(gi > 0){
        this->ui->graphic->legend->setVisible(true);
        this->ui->graphic->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);

        this->ui->graphic->xAxis->setLabel(QString::fromStdString(XLABEL));

        std::string ylabel;
        if(option == MainWindow::TIMES_PLOT_OPTION)
            ylabel = YLABEL_TIMES;
        else if(option == MainWindow::SWAPS_PLOT_OPTION)
            ylabel = YLABEL_SWAPS;
        else
            ylabel = YLABEL_COMPS;
        this->ui->graphic->yAxis->setLabel(QString::fromStdString(ylabel));

        this->ui->graphic->rescaleAxes();
        this->ui->graphic->replot();
    }

}

void MainWindow::clearGraphic(){
    this->ui->graphic->clearGraphs();
    this->ui->graphic->clearItems();
    this->ui->graphic->legend->setVisible(false);
    this->ui->graphic->xAxis->setLabel("");
    this->ui->graphic->yAxis->setLabel("");
    this->ui->timeRBtn->setChecked(false);
    this->ui->comparisonRBtn->setChecked(false);
    this->ui->swapsRBtn->setChecked(false);

    this->ui->graphic->replot();
}

std::vector<int> MainWindow::loadVector(){
    for(int i=0;i<this->VEC_NAMES.size();i++){
        if(this->ui->vectorList->currentText().toStdString() == this->VEC_NAMES[i]){
            this->fileType = this->VEC_CODES[i];
        }
    }

    std::string filename;

    if(this->fileType == ORDERED_VECTOR_MAX_MIN || this->fileType == ORDERED_VECTOR_MIN_MAX)
        filename = ORDERED_VECTOR_FILENAME;
    else
        filename = RANDOM_VECTOR_FILENAME;

    std::vector<int> array;

    FILE *file = fopen(filename.c_str(), "rb");
    if(!file){
        InfoMessage::fileNotFoundErrorMsg(this, QString::fromStdString(filename));
        return array;
    }

    int* a = (int*)malloc(sizeof(int)*vSizes[vSizes.size()-1]);
    fread(a, sizeof(int)*vSizes[vSizes.size()-1], 1, file);

    array = std::vector<int>(vSizes[vSizes.size()-1]);

    for(int i=0;i<array.size();i++){
        if(fileType != ORDERED_VECTOR_MAX_MIN)
            array[i] = a[i];
        else
            array[i] = a[array.size()-1-i]; //reverse ordered vector
    }

    fclose(file);
    free(a);
    return array;
}

void MainWindow::on_signaler_percentChanged(double percent){
    this->ui->progressBar->setValue(percent);
}

void MainWindow::on_timeRBtn_clicked() {
    if(this->sorter == nullptr || this->sorter->isRunning() || this->sorter->isAborted())
        return;

    this->clearGraphic();
    this->ui->timeRBtn->setChecked(true);
    this->setupGraphic(this->sorter->getTimes().first, this->sorter->getTimes().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->TIMES_PLOT_OPTION);
}

void MainWindow::on_swapsRBtn_clicked() {
    if(this->sorter == nullptr || this->sorter->isRunning() || this->sorter->isAborted())
        return;

    this->clearGraphic();
    this->ui->swapsRBtn->setChecked(true);
    this->setupGraphic(this->sorter->getSwaps().first, this->sorter->getSwaps().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->SWAPS_PLOT_OPTION);
}

void MainWindow::on_comparisonRBtn_clicked() {
    if(this->sorter == nullptr || this->sorter->isRunning() || this->sorter->isAborted())
        return;

    this->clearGraphic();
    this->ui->compareBtn->setChecked(true);
    this->setupGraphic(this->sorter->getComparisons().first, this->sorter->getComparisons().second, this->SORT_NAMES[this->sorter->getAlgs().first], this->SORT_NAMES[this->sorter->getAlgs().second], this->COMPS_PLOT_OPTION);
}

void MainWindow::on_cancelBtn_clicked() {
    if(this->sorter != nullptr && this->sorter->isRunning()){
        this->sorter->abortSorter();
    }

    this->ui->cancelBtn->setEnabled(false);
    this->ui->compareBtn->setEnabled(true);
}

void MainWindow::on_clearGraphicOpt_triggered(bool){
    this->clearGraphic();
    this->on_cancelBtn_clicked();
    if(this->sorter != nullptr){
        this->sorter->abortSorter();
    }
}

void MainWindow::on_saveTxtOpt_triggered(bool){
    if(this->sorter == nullptr || this->sorter->isAborted() || this->sorter->isRunning()){
        //TODO: Error message
        return;
    }

    std::string a1Name = "";
    std::string a2Name = "";
    if(this->sorter->getAlgs().first != Sorter::NO_SORT_METHOD)
        a1Name = SORT_NAMES[this->sorter->getAlgs().first];
    if(this->sorter->getAlgs().second != Sorter::NO_SORT_METHOD)
        a2Name = SORT_NAMES[this->sorter->getAlgs().second];

    std::string filename;
    std::string a1Out = "", a2Out = "";
    std::string tab = "\t\t";
    std::string nl = "\n";

    if(a1Name != ""){
        filename = a1Name;
        char a1o[5000];
        for(int i=0;i<vSizes.size();i++){
            sprintf(a1o, "%i \t\t %.2f \t\t %.2f \t\t %.2f\n", vSizes[i], this->sorter->getTimes().first[i], this->sorter->getSwaps().first[i], this->sorter->getComparisons().first[i]);
        }
        a1Out = a1o;
    }

    if(a2Name != ""){
        filename = a2Name;
        char a2o[5000];
        for(int i=0;i<vSizes.size();i++){
            sprintf(a2o, "%i \t\t %.2f \t\t %.2f \t\t %.2f\n", vSizes[i], this->sorter->getTimes().second[i], this->sorter->getSwaps().second[i], this->sorter->getComparisons().second[i]);
        }
        a2Out = a2o;
    }


    if(a1Name != "" && a2Name != "")
        filename = a1Name + " x " + a2Name;

    std::string title = filename;
    filename += ".txt";

    std::string vecTypeName;
    if(this->fileType == ORDERED_VECTOR_MIN_MAX)
        vecTypeName = "Ordered Vector (Min. to Max.)";
    else if(this->fileType == ORDERED_VECTOR_MAX_MIN)
        vecTypeName = "Reverse Ordered Vector (Max. to Min.)";
    else
        vecTypeName = "Random Vector";

    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime ( &rawtime );

    FILE *file = fopen(filename.c_str(), "wt");
    if(!file){
        //TODO: error message
        return;
    }

    fprintf(file, "Test: %s\nDate: %s\nVector Type: %s\n", title.c_str(), asctime (timeinfo), vecTypeName.c_str());
    if(a1Name != ""){
        fprintf(file, "\nAlgorithm: %s\n", a1Name.c_str());
        fprintf(file, "\n\t\tTime (sec.)\t\tNum. of Swaps (x10^6)\t\tNum. of Comparisons (x10^6)\n");
        fprintf(file, "%s", a1Out.c_str());
    }
    if(a2Name != ""){
        fprintf(file, "\nAlgorithm: %s\n", a2Name.c_str());
        fprintf(file, "\n\t\tTime (sec.)\t\tNum. of Swaps (x10^6)\t\tNum. of Comparisons (x10^6)\n");
        fprintf(file, "%s", a2Out.c_str());
    }

    fclose(file);
}

void MainWindow::on_aboutOpt_triggered(bool){

}

void MainWindow::on_exitOpt_triggered(bool){

}
