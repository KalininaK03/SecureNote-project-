//Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "Note.h"
#include <vector>

class Database {
public:
    static void saveNote(const Note& note);
    static std::vector<Note> loadNotes();
};

#endif
