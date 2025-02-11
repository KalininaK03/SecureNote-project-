//Database.cpp
#include "Database.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;

void Database::saveNote(const Note& note) {
    sqlite3* db;
    sqlite3_open("notes.db", &db);

    string sql = "INSERT INTO notes (title, content, created_at) VALUES ('" +
                     note.getTitle() + "', '" + note.getContent() + "', datetime('now'));";
    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
    sqlite3_close(db);
}

    vector<Note> Database::loadNotes() {
    sqlite3* db;
    sqlite3_open("notes.db", &db);
    sqlite3_stmt* stmt;

    vector<Note> notes;
    string sql = "SELECT title, content, FROM notes;";
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        string title = (const char*)sqlite3_column_text(stmt, 0);
        string content = (const char*)sqlite3_column_text(stmt, 1);
        notes.emplace_back(title, content);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return notes;
}
