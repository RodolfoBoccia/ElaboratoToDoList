//
// Created by Notebook on 16/09/2021.
//

#ifndef ELABORATOTODOLIST_SETOFLISTS_H
#define ELABORATOTODOLIST_SETOFLISTS_H

#include <vector>
#include "ToDoList.h"

class SetOfLists {
public:
    void newList(const string& title);

    void removeList(const string& title);

    void displayAll();

    vector<ToDoList> &getSetOfLists() {
        return setOfLists;
    }

private:
    std::vector<ToDoList> setOfLists;

};


#endif //ELABORATOTODOLIST_SETOFLISTS_H
