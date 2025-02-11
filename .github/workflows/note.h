//Note.h
#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <ctime>

using namespace std;

class Note
{
private:
    string title;
    string content;
    time_t createdAt;
public:
    Note(const string& title, const string& content);
    string getTitle() const;
    string getContent() const;
    string getTimestamp() const;
};

#endif
