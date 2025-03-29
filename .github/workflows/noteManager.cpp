#include "notemanager.h"
#include <QFileDialog>
#include <QMessageBox>

void NoteManager::createNewNote() {
    currentNotePath = QFileDialog::getSaveFileName(nullptr, "Create New Note", "", "Text Files (*.txt)");
    if (!currentNotePath.isEmpty()) {
        QFile file(currentNotePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write("");
            file.close();
        }
    }
}

void NoteManager::saveNote(const QString &content) {
    if (currentNotePath.isEmpty()) {
        currentNotePath = QFileDialog::getSaveFileName(nullptr, "Save Note", "", "Text Files (*.txt)");
    }
    if (!currentNotePath.isEmpty()) {
        QFile file(currentNotePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.write(content.toUtf8());
            file.close();
        }
    }
}

void NoteManager::deleteNote() {
    if (!currentNotePath.isEmpty()) {
        QFile::remove(currentNotePath);
        currentNotePath.clear();
    }
}
