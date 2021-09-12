//
// Created by Notebook on 11/08/2021.
//

#include "ToDoList.h"
#include <iostream>
#include <fstream>

using namespace std;

void ToDoList::add(const string& text, const Date& date) {
    ToDo toDo(text, date);
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
        cout << i << ") " << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
        i++;
    }
    cout << endl;
}

void ToDoList::write() {
    fstream file;
    file.open("list.txt", ios::out);
    if (file.is_open()) {
        for (const auto &toDo : list) {
            file << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
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
                string sup;
                int day;
                int month;
                int year;
                sup = line.substr(line.find("+Completato+") + 12, line.length() - line.find("+Completato+") + 12);
                day = stoi(sup.substr(0, sup.find('/')));
                month = stoi(sup.substr(sup.find_first_of('/') + 1, sup.find_last_of('/') - (sup.find('/') + 1)));
                year = stoi(sup.substr(sup.find_last_of('/') + 1, 4));
                Date date(day, month, year);
                line = line.substr(0, line.find("+Completato+") - 3);
                ToDo toDo(line, date, true);
                list.push_back(toDo);
            } else if (line.find("-Incompleto-") != string::npos) {
                string sup;
                int day;
                int month;
                int year;
                sup = line.substr(line.find("-Incompleto-") + 12, line.length() - line.find("-Incompleto-") + 12);
                day = stoi(sup.substr(0, sup.find('/')));
                month = stoi(sup.substr(sup.find_first_of('/') + 1, sup.find_last_of('/') - (sup.find('/') + 1)));
                year = stoi(sup.substr(sup.find_last_of('/') + 1, 4));
                Date date(day, month, year);
                line = line.substr(0, line.find("-Incompleto-") - 3);
                ToDo toDo(line, date);
                list.push_back(toDo);
            }
        }
        file.close();
    } else throw (runtime_error) "Errore lettura da file";
}