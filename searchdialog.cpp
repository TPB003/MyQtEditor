#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    connect(ui->btnFindNext, &QPushButton::clicked, this, [=]() {
        emit findNext(ui->lineEdit->text());
    });

    connect(ui->btnReplace, &QPushButton::clicked, this, [=]() {
        emit replaceOne(ui->lineEdit->text(), ui->lineEdit_2->text());
    });

    connect(ui->btnReplaceAll, &QPushButton::clicked, this, [=]() {
        emit replaceAll(ui->lineEdit->text(), ui->lineEdit_2->text());
    });
}

SearchDialog::~SearchDialog()
{
    delete ui;
}
