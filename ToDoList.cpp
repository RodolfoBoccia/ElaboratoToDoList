//
// Created by Notebook on 11/08/2021.
//

#include "ToDoList.h"
#include <iostream>
#include <fstream>

using namespace std;

void ToDoList::add() {
    string text;
    cout << "Inserisci la descrizione del nuovo toDo: ";
    cin.ignore();
    getline(cin, text);
    cout << endl;
    ToDo toDo(text);
    list.push_back(toDo);
    write();
}

void ToDoList::remove() {
    int pos;
    cout << "Inserisci il numero del ToDo da rimuovere: ";
    cin >> pos;
    cout << endl;
    if(pos <= list.size() && pos > 0){
        auto it = list.begin();
        advance(it, --pos);
        list.erase(it);
        write();
    }
    else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::setToDoCompleted() {
    int pos;
    cout << "Inserisci il numero del ToDo da spuntare: ";
    cin >> pos;
    cout << endl;
    if(pos <= list.size() && pos > 0){
        auto it = list.begin();
        advance(it, --pos);
        it->setCompleted();
        write();
    }
    else throw (out_of_range) "Accesso ad elemento non presente";
}

void ToDoList::display() {
    cout << "Lista ToDo: " << endl;
    fstream file;
    file.open("list.txt",ios::in);
    if(file.is_open()){
        int i=1;
        string line;
        while (getline(file, line)){
            cout << i<<") " << line << endl;
            i++;
        }
        file.close();
    }
    cout << endl;
}

void ToDoList::write() {
    fstream file;
    file.open("list.txt", ios::out);
    if(file.is_open()){
        for(const auto& toDo : list){
            file << toDo.getText() << "   " << toDo.isCompleted() << endl;
        }
        file.close();
    }
}

void ToDoList::read()
{
    fstream file;
    file.open("list.txt", fstream::in);
    if(file.is_open()){
        string line;
        while(getline(file, line))
        {
            if (line.empty())
                continue;
            else if(line.find("+Completata+") != string::npos){
                line = line.substr(0, line.find("+Completata+") - 3 );
                ToDo toDo(line, "+Completata+");
                list.push_back(toDo);
            }
            else if(line.find("-Incompleta-") != string::npos){
                line = line.substr(0, line.find("-Incompleta-") - 3 );
                ToDo toDo(line);
                list.push_back(toDo);
            }
        }
        file.close();
        write();
    }
}