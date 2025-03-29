#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QString>
#include <QFile>

class NoteManager {
public:
    void createNewNote();
    void saveNote(const QString &content);
    void deleteNote();

private:
    QString currentNotePath;
};

#endif // NOTEMANAGER_H
