#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>


namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

signals:
    void findNext(const QString &text);
    void replaceOne(const QString &findText, const QString &replaceText);
    void replaceAll(const QString &findText, const QString &replaceText);

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
