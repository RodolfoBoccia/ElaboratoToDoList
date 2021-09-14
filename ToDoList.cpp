//
// Created by Notebook on 11/08/2021.
//

#include "ToDoList.h"
#include <iostream>

using namespace std;

void ToDoList::add(const string& text, const Date& date, const bool& completed) {
    ToDo toDo(text, date, completed);
    list.push_back(toDo);
}

void ToDoList::remove(int pos) {
    if (pos <= list.size() && pos > 0) {
        auto it = list.begin();
        advance(it, --pos);
        list.erase(it);
    } else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::setToDoCompleted(int pos) {
    if (pos <= list.size() && pos > 0) {
        auto it = list.begin();
        advance(it, --pos);
        it->setCompleted();
    } else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::displayCompleted() {
    int i = 1;
    for (const auto& toDo : list){
        if(toDo.isCompleted()){
            cout << i << ") " << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
        }
        i++;
    }
    cout << endl;
}

void ToDoList::displayNotCompleted() {
    int i = 1;
    for (const auto& toDo : list){
        if(!toDo.isCompleted()){
            cout << i << ") " << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
        }
        i++;
    }
    cout << endl;
}

void ToDoList::display() const{
    int i = 1;
    for (const auto& toDo : list){
        cout << i << ") " << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
        i++;
    }
    cout << endl;
}
