//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_TODOLIST_H
#define ELABORATOTODOLIST_TODOLIST_H

#include <list>
#include "Item.h"

using namespace std;


class ToDoList {
public:
    ToDoList() = default;

    ~ToDoList() = default;

    void add();

    void remove();

    void check();

    void display();

private:
    list<Item> list;
};


#endif //ELABORATOTODOLIST_TODOLIST_H
