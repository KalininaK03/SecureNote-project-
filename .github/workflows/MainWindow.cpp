#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Подключение сигналов к слотам
    connect(ui->actionNewNote, &QAction::triggered, this, &MainWindow::on_actionNewNote_triggered);
    connect(ui->actionSaveNote, &QAction::triggered, this, &MainWindow::on_actionSaveNote_triggered);
    connect(ui->actionDeleteNote, &QAction::triggered, this, &MainWindow::on_actionDeleteNote_triggered);
    connect(ui->actionToggleTheme, &QAction::triggered, this, &MainWindow::on_actionToggleTheme_triggered);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionNewNote_triggered() {
    noteManager.createNewNote();
    QMessageBox::information(this, "Info", "New note created!");
}

void MainWindow::on_actionSaveNote_triggered() {
    QString content = ui->textEdit->toPlainText();
    noteManager.saveNote(content);
    QMessageBox::information(this, "Info", "Note saved successfully!");
}

void MainWindow::on_actionDeleteNote_triggered() {
    noteManager.deleteNote();
    QMessageBox::warning(this, "Warning", "Note deleted!");
}

void MainWindow::on_actionToggleTheme_triggered() {
    isDarkTheme = !isDarkTheme;
    QFile styleFile(isDarkTheme ? ":/styles/dark_theme.qss" : ":/styles/light_theme.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(styleSheet);
    }
}
