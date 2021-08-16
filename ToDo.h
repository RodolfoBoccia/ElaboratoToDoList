//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODO_H
#define ELABORATOTODOLIST_TODO_H

#include <string>

using namespace std;

class ToDo {
public:

    explicit ToDo(const string &text, const string &completed = "-Incompleta-") : text{text}, completed{completed} {}

    ~ToDo() = default;

    void setCompleted() {
        ToDo::completed = "+Completata+";
    }

    const string &getText() const {
        return text;
    }

    const string &isCompleted() const {
        return completed;
    }

private:
    string text;
    string completed;
};


#endif //ELABORATOTODOLIST_TODO_H
