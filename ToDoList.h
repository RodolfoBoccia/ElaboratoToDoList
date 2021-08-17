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

    void add(string text);

    void remove(int pos);

    void setToDoCompleted(int pos);

    void display();

    void write();

    void read();

private:
    list<ToDo> list;
};


#endif //ELABORATOTODOLIST_TODOLIST_H
