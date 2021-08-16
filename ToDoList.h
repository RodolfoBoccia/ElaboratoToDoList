//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODOLIST_H
#define ELABORATOTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>

using namespace std;

class ToDoList {
public:
    ToDoList() = default;

    ~ToDoList() = default;

    void add();

    void remove();

    void setToDoCompleted();

    void display();

    void write();

    void read();

private:
    list<ToDo> list;
};


#endif //ELABORATOTODOLIST_TODOLIST_H
