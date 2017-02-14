#ifndef __INFOMESSAGE_H__
#define __INFOMESSAGE_H__

#include <QMessageBox>

class InfoMessage {
public:
    static void processRunningErrorMsg(QWidget *parent){
        QMessageBox msgBox;
        msgBox.critical(parent, QString::fromStdString(PROCESS_RUNNING_ERROR_TITLE), QString::fromStdString(PROCESS_RUNNING_ERROR_MSG));
    }

    static void algNotChosenErrorMsg(QWidget *parent){
        QMessageBox msgBox;
        msgBox.critical(parent, QString::fromStdString(ALG_NOT_CHOSEN_ERROR_TITLE), QString::fromStdString(ALG_NOT_CHOSEN_ERROR_MSG));
    }

    static void fileNotFoundErrorMsg(QWidget *parent, QString filename){
        QMessageBox msgBox;
        QString msg = QString::fromStdString(FILE_NOT_FOUND_ERROR_MSG).replace("#", filename);
        msgBox.critical(parent, QString::fromStdString(FILE_NOT_FOUND_ERROR_TITLE), msg);
    }

    static void aboutSorterMsg(QWidget *parent){
         QMessageBox msgBox;
         msgBox.critical(parent, QString::fromStdString(ABOUT_SORTER_TITLE), ABOUT_SORTER_MSG);
    }

    static void fileSavedMsg(QWidget *parent, QString filename){
        QMessageBox msgBox;
        QString msg = QString::fromStdString(FILE_SAVED_MSG).replace("#", filename);
        msgBox.critical(parent, QString::fromStdString(FILE_SAVED_TITLE), msg);
    }

    static void createFileErrorMsg(QWidget *parent, QString filename){
        QMessageBox msgBox;
        QString msg = QString::fromStdString(CREATE_FILE_ERROR_MSG).replace("#", filename);
        msgBox.critical(parent, QString::fromStdString(CREATE_FILE_ERROR_TITLE), msg);
    }

private:
    static constexpr const char* PROCESS_RUNNING_ERROR_TITLE = "Process Running!";
    static constexpr const char* ALG_NOT_CHOSEN_ERROR_TITLE = "Algorithm not chosen!";
    static constexpr const char* FILE_NOT_FOUND_ERROR_TITLE = "File not found!";
    static constexpr const char* ABOUT_SORTER_TITLE = "About...";
    static constexpr const char* FILE_SAVED_TITLE = "File Saved!";
    static constexpr const char* CREATE_FILE_ERROR_TITLE = "Error Creating File!";

    static constexpr const char* PROCESS_RUNNING_ERROR_MSG = "A process is already running.\n Please, cancel the operation or wait it finish, and try again.";
    static constexpr const char* ALG_NOT_CHOSEN_ERROR_MSG = "No algorithm was chosen in Algorithm 1 and 2. Please, choose at least one from the least to run the sorting.";
    static constexpr const char* FILE_NOT_FOUND_ERROR_MSG = "File # was not found.\n Please make sure it is found in the same directory as this program.";
    static constexpr const char* ABOUT_SORTER_MSG = "Program Sorter\nCreated in C/C++ using Qt Creator.\n\nDone for INF01124 - Data Search and Classification, at UFRGS in 2013/2.\n\nAuthor: Carlo S. Sartori";
    static constexpr const char* FILE_SAVED_MSG = "File # saved successfully in hard drive.";
    static constexpr const char* CREATE_FILE_ERROR_MSG = "An error occurred during the creation of file #\n Please try again.";
};

#endif // __INFOMESSAGE_H__
