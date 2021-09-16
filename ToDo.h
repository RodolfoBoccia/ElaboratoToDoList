//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODO_H
#define ELABORATOTODOLIST_TODO_H

#include <ctime>
#include <string>
#include "Date.h"

using namespace std;

class ToDo {
public:

    explicit ToDo(const string &text, const Date date, const bool completed = false) : text{text}, completed{completed}, date{date} {}

    ~ToDo() = default;

    string convertCompleted() const{
        string s;
        if(completed){
            s = "+Completato+";
        }
        else s = "-Incompleto-";
        return s;
    }

    const string &getText() const {
        return text;
    }

    bool isCompleted() const {
        return completed;
    }

    void setCompleted() {
        ToDo::completed = true;
    }

    const Date &getDate() const {
        return date;
    }

private:
    string text;
    bool completed;
    Date date;
};


#endif //ELABORATOTODOLIST_TODO_H
