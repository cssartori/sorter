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


    connect(this->sorter, SIGNAL(calcPercentChanged(double)), this, SLOT(on_calc_percent_update(double)));

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
    this->sorter = new Sorter(alg1, alg2, array, vSizes);

    this->ui->progressBar->setValue(0);

    this->sorter->start(); //start sorter thread

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

void MainWindow::on_calc_percent_update(double percent){
    this->ui->progressBar->setValue(percent);
}
