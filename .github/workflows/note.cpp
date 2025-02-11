//Note.cpp
#include "Note.h"
#include <ctime>
#include <sstream>

using namespace std;

Note::Note(const std::string& title, const std::string& content)
    : title(title), content(content), createdAt(time(nullptr)){}

    string Note::getTitle() const {
    return title;
}
    string Note::getContent() const {
    return content;
}
    string Note::getTimestamp() const {
    char buffer[20];
    struct tm* timeinfo = localtime(&createdAt);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}
