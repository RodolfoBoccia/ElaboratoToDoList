//
// Created by Notebook on 11/08/2021.
//

#include <iostream>
#include <fstream>
#include "ToDoList.h"

using namespace std;

void ToDoList::add() {
    string title;
    cout << "Inserisci descrizione ToDo" << endl;
    cin >> title;
    Item ToDo(title);
    list.push_back(ToDo);
    writing();
}

void ToDoList::remove() {
    int pos;
    cout << "Inserisci numero del ToDo da rimuovere" << endl;
    cin >> pos;
    if(pos <= list.size() && pos > 0){
        auto iterator = list.begin();
        advance(iterator, --pos);
        list.erase(iterator);
        writing();
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
        writing();
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
            cout << i<<")" << line << endl;
            i++;
        }
        file.close();
    }
    cout << endl;
}

void ToDoList::writing() {
    fstream file;
    file.open("list.txt", ios::out);
    if(file.is_open()){
        for(const auto& ToDo : list){
            file << ToDo.getTitle() << "   " << ToDo.getCheck() << endl;
        }
        file.close();
    }
}

void ToDoList::read()
{
    fstream file;
    file.open("list.txt", fstream::in);

    if(file.is_open()){
        string text;
        string check = "Incompleta";
        while(getline(file, text))
        {
            if (text.empty())
                continue;
            else if(text.find("Completata") != string::npos){
                check = "Completata";
                text = text.substr(0, text.find("Completata")-3 );
            }
            else if(text.find("Incompleta") != string::npos){
                check = "Incompleta";
                text = text.substr(0, text.find("Incompleta")-3 );
            }
            Item item(text, check);
            list.push_back(item);
        }
        file.close();
        writing();
    }
}