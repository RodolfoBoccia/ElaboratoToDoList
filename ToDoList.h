//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODOLIST_H
#define ELABORATOTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>

class ToDoList {
public:
    explicit ToDoList(const string& title): title{title} {}

    ~ToDoList() = default;

    void add(const string& text, const Date& date, const bool& completed);

    void remove(int pos);

    void setToDoCompleted(int pos);

    void displayCompleted();

    void displayNotCompleted();

    void display() const;

    bool operator==(const ToDoList& right) const {
        if ( title == right.title )
            return true;
        else return false;
    }

    const string &getTitle() const {
        return title;
    }

    const std::list<ToDo> &getList() const {
        return list;
    }

private:
    string title;
    std::list<ToDo> list;
};


#endif //ELABORATOTODOLIST_TODOLIST_H
