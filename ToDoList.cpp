//
// Created by Notebook on 11/08/2021.
//

#include "ToDoList.h"
#include <iostream>
#include <fstream>

using namespace std;

void ToDoList::add(const string& text) {
    ToDo toDo(text);
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

void ToDoList::display() {
    cout << "Lista ToDo: " << endl;
    int i = 1;
    for (const auto& toDo : list){
        cout << i << ") " << toDo.getText() << "   " << toDo.isCompleted() << endl;
        i++;
    }
    cout << endl;
}

void ToDoList::write() {
    fstream file;
    file.open("list.txt", ios::out);
    if (file.is_open()) {
        for (const auto &toDo : list) {
            file << toDo.getText() << "   " << toDo.isCompleted() << endl;
        }
        file.close();
    } else throw (runtime_error) "Errore scrittura su file";
}

void ToDoList::read() {
    fstream file;
    file.open("list.txt", fstream::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty())
                continue;
            else if (line.find("+Completato+") != string::npos) {
                line = line.substr(0, line.find("+Completato+") - 3);
                ToDo toDo(line, "+Completato+");
                list.push_back(toDo);
            } else if (line.find("-Incompleto-") != string::npos) {
                line = line.substr(0, line.find("-Incompleto-") - 3);
                ToDo toDo(line);
                list.push_back(toDo);
            }
        }
        file.close();
    } else throw (runtime_error) "Errore lettura da file";
}