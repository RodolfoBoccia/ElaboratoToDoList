//
// Created by Notebook on 16/09/2021.
//

#include "SetOfLists.h"

void SetOfLists::newList(const string &title) {
    for(const auto& list : setOfLists){
        if(title == list.getTitle())
            throw (invalid_argument) "Non si possono avere liste con titoli uguali";
    }
    ToDoList list(title);
    setOfLists.push_back(list);
}

void SetOfLists::removeList(const string &title) {
    bool found = false;
    auto it = setOfLists.begin();
    for(auto& list : setOfLists){
        if(title == list.getTitle()){
            found = true;
            setOfLists.erase(it);
            break;
        }
        else{
            advance(it, 1);
        }
    }
    if (!found) {
        throw (out_of_range) "Lista non presente";
    }
}

void SetOfLists::displayAll() {
    for (const auto& list : setOfLists){
        cout << "Lista: " << list.getTitle() << endl;
        list.display();
    }
    cout << endl;
}

