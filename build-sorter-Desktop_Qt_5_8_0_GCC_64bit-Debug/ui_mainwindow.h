/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *clearPlot;
    QAction *saveastxt;
    QAction *exitAction_2;
    QAction *especs;
    QAction *let_esp;
    QAction *about_2;
    QWidget *centralWidget;
    QLabel *alg1Label;
    QLabel *alg2Label;
    QPushButton *compareBtn;
    QComboBox *vectorList;
    QLabel *vectorLabel;
    QGroupBox *graphicGroup;
    QRadioButton *timeRBtn;
    QRadioButton *swapsRBtn;
    QRadioButton *compareRBtn;
    QCustomPlot *graphic;
    QComboBox *algList1;
    QProgressBar *progressBar;
    QLabel *calcLabel;
    QComboBox *algList2;
    QMenuBar *menuBar;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(602, 451);
        MainWindow->setMinimumSize(QSize(602, 451));
        MainWindow->setMaximumSize(QSize(602, 451));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        exitAction->setCheckable(false);
        clearPlot = new QAction(MainWindow);
        clearPlot->setObjectName(QStringLiteral("clearPlot"));
        clearPlot->setShortcutContext(Qt::WidgetShortcut);
        saveastxt = new QAction(MainWindow);
        saveastxt->setObjectName(QStringLiteral("saveastxt"));
        exitAction_2 = new QAction(MainWindow);
        exitAction_2->setObjectName(QStringLiteral("exitAction_2"));
        especs = new QAction(MainWindow);
        especs->setObjectName(QStringLiteral("especs"));
        let_esp = new QAction(MainWindow);
        let_esp->setObjectName(QStringLiteral("let_esp"));
        about_2 = new QAction(MainWindow);
        about_2->setObjectName(QStringLiteral("about_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        alg1Label = new QLabel(centralWidget);
        alg1Label->setObjectName(QStringLiteral("alg1Label"));
        alg1Label->setGeometry(QRect(20, 330, 121, 16));
        alg2Label = new QLabel(centralWidget);
        alg2Label->setObjectName(QStringLiteral("alg2Label"));
        alg2Label->setGeometry(QRect(160, 330, 121, 16));
        compareBtn = new QPushButton(centralWidget);
        compareBtn->setObjectName(QStringLiteral("compareBtn"));
        compareBtn->setGeometry(QRect(480, 340, 101, 81));
        vectorList = new QComboBox(centralWidget);
        vectorList->setObjectName(QStringLiteral("vectorList"));
        vectorList->setGeometry(QRect(300, 350, 161, 22));
        vectorList->setMaxVisibleItems(3);
        vectorLabel = new QLabel(centralWidget);
        vectorLabel->setObjectName(QStringLiteral("vectorLabel"));
        vectorLabel->setGeometry(QRect(300, 330, 121, 16));
        graphicGroup = new QGroupBox(centralWidget);
        graphicGroup->setObjectName(QStringLiteral("graphicGroup"));
        graphicGroup->setGeometry(QRect(20, 10, 561, 301));
        timeRBtn = new QRadioButton(graphicGroup);
        timeRBtn->setObjectName(QStringLiteral("timeRBtn"));
        timeRBtn->setGeometry(QRect(10, 40, 82, 17));
        timeRBtn->setCheckable(true);
        timeRBtn->setChecked(false);
        swapsRBtn = new QRadioButton(graphicGroup);
        swapsRBtn->setObjectName(QStringLiteral("swapsRBtn"));
        swapsRBtn->setGeometry(QRect(10, 90, 82, 17));
        compareRBtn = new QRadioButton(graphicGroup);
        compareRBtn->setObjectName(QStringLiteral("compareRBtn"));
        compareRBtn->setGeometry(QRect(10, 150, 121, 17));
        graphic = new QCustomPlot(graphicGroup);
        graphic->setObjectName(QStringLiteral("graphic"));
        graphic->setGeometry(QRect(150, 30, 401, 261));
        algList1 = new QComboBox(centralWidget);
        algList1->setObjectName(QStringLiteral("algList1"));
        algList1->setGeometry(QRect(20, 350, 101, 22));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 400, 321, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        calcLabel = new QLabel(centralWidget);
        calcLabel->setObjectName(QStringLiteral("calcLabel"));
        calcLabel->setGeometry(QRect(20, 380, 181, 16));
        algList2 = new QComboBox(centralWidget);
        algList2->setObjectName(QStringLiteral("algList2"));
        algList2->setGeometry(QRect(160, 350, 101, 22));
        MainWindow->setCentralWidget(centralWidget);
        graphicGroup->raise();
        alg1Label->raise();
        alg2Label->raise();
        compareBtn->raise();
        vectorList->raise();
        vectorLabel->raise();
        algList1->raise();
        progressBar->raise();
        calcLabel->raise();
        algList2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 22));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(clearPlot);
        menuOptions->addAction(saveastxt);
        menuOptions->addAction(about_2);
        menuOptions->addAction(exitAction_2);

        retranslateUi(MainWindow);

        vectorList->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        exitAction->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        clearPlot->setText(QApplication::translate("MainWindow", "Limpar Gr\303\241fico", Q_NULLPTR));
        clearPlot->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
        saveastxt->setText(QApplication::translate("MainWindow", "Salvar em Texto...", Q_NULLPTR));
        saveastxt->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        exitAction_2->setText(QApplication::translate("MainWindow", "Sair", Q_NULLPTR));
        exitAction_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        especs->setText(QApplication::translate("MainWindow", "Especifica\303\247\303\265es", Q_NULLPTR));
        especs->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
        let_esp->setText(QApplication::translate("MainWindow", "LET Especial #0", Q_NULLPTR));
        let_esp->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        about_2->setText(QApplication::translate("MainWindow", "Sobre...", Q_NULLPTR));
        about_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        alg1Label->setText(QApplication::translate("MainWindow", "Algorithm 1:", Q_NULLPTR));
        alg2Label->setText(QApplication::translate("MainWindow", "Algorithm 2:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        compareBtn->setToolTip(QApplication::translate("MainWindow", "Comparar algoritmos selecionados", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        compareBtn->setText(QApplication::translate("MainWindow", "Compare", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        vectorList->setToolTip(QApplication::translate("MainWindow", "Ordena\303\247\303\243o do vetor a ser ordenado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        vectorLabel->setText(QApplication::translate("MainWindow", "Vector order:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        graphicGroup->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        graphicGroup->setTitle(QApplication::translate("MainWindow", "Graphic", Q_NULLPTR));
        timeRBtn->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        swapsRBtn->setText(QApplication::translate("MainWindow", "Swaps", Q_NULLPTR));
        compareRBtn->setText(QApplication::translate("MainWindow", "Comparissons", Q_NULLPTR));
        algList1->clear();
        algList1->insertItems(0, QStringList()
         << QString()
        );
#ifndef QT_NO_TOOLTIP
        algList1->setToolTip(QApplication::translate("MainWindow", "Algoritmo 1 a ser comparado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        calcLabel->setText(QApplication::translate("MainWindow", "Calculations done:", Q_NULLPTR));
        algList2->clear();
        algList2->insertItems(0, QStringList()
         << QString()
        );
#ifndef QT_NO_TOOLTIP
        algList2->setToolTip(QApplication::translate("MainWindow", "Algoritmo 1 a ser comparado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
