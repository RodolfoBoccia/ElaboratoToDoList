//
// Created by Notebook on 11/08/2021.
//

#include <iostream>
#include "ToDoList.h"

using namespace std;

void ToDoList::add() {
    string title;
    cout << "Inserisci descrizione ToDo" << endl;
    cin >> title;
    Item ToDo(title);
    list.push_back(ToDo);
    display();
}

void ToDoList::remove() {
    int pos;
    cout << "Inserisci numero del ToDo da rimuovere" << endl;
    cin >> pos;
    if(pos <= list.size() && pos > 0){
        auto iterator = list.begin();
        advance(iterator, --pos);
        list.erase(iterator);
        display();
    }
    else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::check() {
    int pos;
    cout << "Inserisci numero del ToDo da spuntare" << endl;
    cin >> pos;
    if(pos <= list.size() && pos > 0){
        auto iterator = list.begin();
        advance(iterator, --pos);
        iterator->setCheck("Completata");
        display();
    }
    else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::display() {
    cout << "Lista ToDo: " << endl;
    int i=1;
    for(const auto& ToDo : list){
        cout << i<<")" << ToDo.getTitle()<<"\t"<<ToDo.getCheck() << endl;
        i++;
    }
    cout << endl;
}
