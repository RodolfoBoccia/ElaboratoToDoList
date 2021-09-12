//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODOLIST_H
#define ELABORATOTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>

class ToDoList {
public:
    ToDoList() = default;

    ~ToDoList() = default;

    void add(const string& text, const Date& date);

    void remove(int pos);

    void setToDoCompleted(int pos);

    void displayAll();

    void displayCompleted();

    void displayNotCompleted();

    void write();

    void read();

private:
    std::list<ToDo> list;
};


#endif //ELABORATOTODOLIST_TODOLIST_H
