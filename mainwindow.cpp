#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSplitter>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建一个水平分割器
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

    // 左边：Markdown 编辑器
    QPlainTextEdit *editor = new QPlainTextEdit(splitter);
    editor->setObjectName("editor");

    // 右边：HTML 预览窗口
    QTextBrowser *preview = new QTextBrowser(splitter);
    preview->setObjectName("preview");

    // 设置比例
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);

    // 设置为主窗口中心控件
    setCentralWidget(splitter);

    connect(editor, &QPlainTextEdit::textChanged, this, [=]() {
        QString md = editor->toPlainText();

        // 简单 Markdown 转 HTML
        QString html;
        QStringList lines = md.split("\n");

        for (QString line : lines) {
            if (line.startsWith("### ")) {
                html += "<h3>" + line.mid(4) + "</h3>";
            } else if (line.startsWith("## ")) {
                html += "<h2>" + line.mid(3) + "</h2>";
            } else if (line.startsWith("# ")) {
                html += "<h1>" + line.mid(2) + "</h1>";
            } else if (!line.isEmpty()) {
                html += "<p>" + line + "</p>";
            } else {
                html += "<br/>";
            }
        }

        preview->setHtml(html);


    });

    // -------------------------
    // 搜索窗口
    // -------------------------
    searchDlg = new SearchDialog(this);

    // Ctrl+F 显示搜索框
    new QShortcut(QKeySequence("Ctrl+F"), this, [=](){
        searchDlg->show();
        searchDlg->raise();
        searchDlg->activateWindow();
    });

    // 搜索
    connect(searchDlg, &SearchDialog::findNext, this, [=](const QString &text){
        QTextCursor cursor = editor->textCursor();
        cursor = editor->document()->find(text, cursor);

        if (!cursor.isNull())
            editor->setTextCursor(cursor);
    });

    // 替换一次
    connect(searchDlg, &SearchDialog::replaceOne, this,
            [=](const QString &findText, const QString &replaceText){

                QTextCursor cursor = editor->textCursor();
                if (cursor.selectedText() == findText)
                    cursor.insertText(replaceText);
            });

    // 替换全部
    connect(searchDlg, &SearchDialog::replaceAll, this,
            [=](const QString &findText, const QString &replaceText){

                QString all = editor->toPlainText();
                all.replace(findText, replaceText);
                editor->setPlainText(all);
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Open File",
        "",
        "Text Files (*.txt *.md);;All Files (*)"
        );

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();

    auto editor = findChild<QPlainTextEdit*>("editor");
    if (editor) editor->setPlainText(content);

    currentFile = fileName;  // 保存当前路径
}


void MainWindow::on_actionNEW_triggered()
{
    auto editor = findChild<QPlainTextEdit*>("editor");
    if (!editor) return;

    editor->clear();
    currentFile.clear();  // 清空当前文件路径
}


void MainWindow::on_actionSave_triggered()
{
    auto editor = findChild<QPlainTextEdit*>("editor");
    if (!editor) return;

    QString fileName = currentFile;

    // 如果之前没保存（新建文件）
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(
            this,
            "Save File",
            "",
            "Text Files (*.txt *.md);;All Files (*)"
            );
        if (fileName.isEmpty()) return;

        currentFile = fileName;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot save file");
        return;
    }

    QTextStream out(&file);
    out << editor->toPlainText();
}

