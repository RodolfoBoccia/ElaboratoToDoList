//
// Created by Notebook on 11/08/2021.
//
#include <iostream>
#include <fstream>
#include "ToDoList.h"

using namespace std;

void ToDoList::add() {
    string title;
    cout << "Inserisci la descrizione del nuovo ToDo: ";
    cin.ignore();
    getline(cin, title);
    cout << endl;
    Item ToDo(title);
    list.push_back(ToDo);
    writing();
}

void ToDoList::remove() {
    int pos;
    cout << "Inserisci il numero del ToDo da rimuovere: ";
    cin >> pos;
    cout << endl;
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
    cout << "Inserisci il numero del ToDo da spuntare: ";
    cin >> pos;
    cout << endl;
    if(pos <= list.size() && pos > 0){
        auto iterator = list.begin();
        advance(iterator, --pos);
        iterator->setCheck("+Completata+");
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
            cout << i<<") " << line << endl;
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
        while(getline(file, text))
        {
            if (text.empty())
                continue;
            else if(text.find("+Completata+") != string::npos){
                text = text.substr(0, text.find("+Completata+")-3 );
                Item item(text, "+Completata+");
                list.push_back(item);
            }
            else if(text.find("-Incompleta-") != string::npos){
                text = text.substr(0, text.find("-Incompleta-")-3 );
                Item item(text);
                list.push_back(item);
            }
        }
        file.close();
        writing();
    }
}