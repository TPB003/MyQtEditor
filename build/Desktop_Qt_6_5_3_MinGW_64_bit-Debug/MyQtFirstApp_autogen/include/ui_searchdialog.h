/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QLabel *lineFind;
    QLineEdit *lineEdit;
    QLabel *lineReplace;
    QLineEdit *lineEdit_2;
    QPushButton *btnFindNext;
    QPushButton *btnReplace;
    QPushButton *btnReplaceAll;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(474, 161);
        lineFind = new QLabel(SearchDialog);
        lineFind->setObjectName("lineFind");
        lineFind->setGeometry(QRect(120, 20, 81, 19));
        lineEdit = new QLineEdit(SearchDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(220, 20, 113, 25));
        lineReplace = new QLabel(SearchDialog);
        lineReplace->setObjectName("lineReplace");
        lineReplace->setGeometry(QRect(120, 50, 101, 19));
        lineEdit_2 = new QLineEdit(SearchDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(220, 50, 113, 25));
        btnFindNext = new QPushButton(SearchDialog);
        btnFindNext->setObjectName("btnFindNext");
        btnFindNext->setGeometry(QRect(80, 100, 93, 28));
        btnReplace = new QPushButton(SearchDialog);
        btnReplace->setObjectName("btnReplace");
        btnReplace->setGeometry(QRect(190, 100, 93, 28));
        btnReplaceAll = new QPushButton(SearchDialog);
        btnReplaceAll->setObjectName("btnReplaceAll");
        btnReplaceAll->setGeometry(QRect(300, 100, 93, 28));

        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "Dialog", nullptr));
        lineFind->setText(QCoreApplication::translate("SearchDialog", "Find what:", nullptr));
        lineReplace->setText(QCoreApplication::translate("SearchDialog", "Replace with:", nullptr));
        btnFindNext->setText(QCoreApplication::translate("SearchDialog", "Find Next", nullptr));
        btnReplace->setText(QCoreApplication::translate("SearchDialog", "Replace", nullptr));
        btnReplaceAll->setText(QCoreApplication::translate("SearchDialog", "Replace All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
