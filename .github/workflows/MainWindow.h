//MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ListWidgetItem>
#include <string>
#include "Note.h"
#include "Database.h"
#include "Crypto.h"

using namespace std;

QT_BEGIN_NAMESPACE;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(const QString &password, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void saveNote();
    void loadNotes();
    void selectNote(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    std::vector<Note> notes;
    QString userPassword;  // Пароль для шифрования
};

#endif // MAINWINDOW_H
