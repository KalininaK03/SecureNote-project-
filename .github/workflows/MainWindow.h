#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notemanager.h" // Модуль для управления заметками

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNewNote_triggered(); // Создание новой заметки
    void on_actionSaveNote_triggered(); // Сохранение заметки
    void on_actionDeleteNote_triggered(); // Удаление заметки
    void on_actionToggleTheme_triggered(); // Переключение темы

private:
    Ui::MainWindow *ui;
    NoteManager noteManager; // Менеджер заметок
    bool isDarkTheme = true; // Текущая тема
};

#endif // MAINWINDOW_H
