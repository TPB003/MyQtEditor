#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QShortcut>
#include "searchdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionNEW_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    SearchDialog *searchDlg;

};
#endif // MAINWINDOW_H
