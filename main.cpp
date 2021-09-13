#include "ToDo.h"
#include "ToDoList.h"
#include <limits>
#include <iostream>
#include <list>
#include <fstream>

void displayAll(const std::list<ToDoList>& lists);
void write(const std::list<ToDoList>& lists);
void read(std::list<ToDoList>& lists);


int main() {
    std::list<ToDoList> toDoLists;
    try{
        read(toDoLists);
        write(toDoLists);
    } catch (const runtime_error &e){
        cerr << e.what() << endl;
        return 0;
    }
    displayAll(toDoLists);

    while (true) {
        cout << "/ Menu /" << endl;
        cout << "1) Crea nuova lista" << endl;
        cout << "2) Aggiungi todo" << endl;
        cout << "3) Rimuovi todo" << endl;
        cout << "4) Imposta completato" << endl;
        cout << "5) Visualizza completati" << endl;
        cout << "6) Visualizza non completati" << endl;
        cout << "7) Visualizza tutti" << endl;
        cout << "8) Rimuovi lista" << endl;
        cout << "0) Esci" << endl << endl;

        int choice;
        cout << "Scrivi il numero dell'operazione da eseguire: ";
        cin >> choice;
        cout << endl;

        try {
            switch (choice) {
                case 1: {
                    string title;
                    cout << "Inserisci il titolo della nuova lista: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(const auto& list : toDoLists){
                        if(title == list.getTitle())
                            throw (invalid_argument) "Non si possono avere liste con titoli uguali";
                    }
                    ToDoList list(title);
                    toDoLists.push_back(list);
                    write(toDoLists);
                    break;
                }
                case 2:{
                    string title;
                    bool found = false;
                    cout << "Scrivi il titolo della lista dove inserire il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : toDoLists){
                        if(title == list.getTitle()){
                            string text;
                            int day;
                            int month;
                            int year;
                            found = true;
                            cout << "Inserisci la descrizione del nuovo toDo: ";
                            getline(cin, text);
                            cout << endl;
                            cout << "Inserisci il giorno (es 23): ";
                            cin >> day;
                            cout << "Inserisci il mese (es 8): ";
                            cin >> month;
                            cout << "Inserisci l anno (deve essere compreso tra 1900 e 2200): ";
                            cin >> year;
                            cout << endl;
                            Date date(day, month, year);
                            date.validityDate();
                            list.add(text, date);
                            write(toDoLists);
                            break;
                        }
                    }
                    if(found)
                        break;
                    else throw (invalid_argument) "Lista non presente";
                }
                case 3:{
                    string title;
                    bool found = false;
                    cout << "Scrivi il titolo della lista dove rimuovere il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : toDoLists){
                        if(title == list.getTitle()){
                            int pos;
                            found = true;
                            cout << "Inserisci il numero del ToDo da rimuovere: ";
                            cin >> pos;
                            cout << endl;
                            list.remove(pos);
                            write(toDoLists);
                            break;
                        }
                    }
                    if(found)
                        break;
                    else throw (invalid_argument) "Lista non presente";
                }
                case 4:{
                    string title;
                    bool found = false;
                    cout << "Scrivi il titolo della lista dove segnare come completato il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : toDoLists){
                        if(title == list.getTitle()){
                            int pos;
                            found = true;
                            cout << "Inserisci il numero del ToDo da segnare come completato: ";
                            cin >> pos;
                            cout << endl;
                            list.setToDoCompleted(pos);
                            write(toDoLists);
                            break;
                        }
                    }
                    if(found)
                        break;
                    else throw (out_of_range) "Lista non presente";
                }
                case 5:{
                    for (auto& list : toDoLists){
                        cout << "Lista: " << list.getTitle() << endl;
                        list.displayCompleted();
                    }
                    break;
                }
                case 6:{
                    for (auto& list : toDoLists){
                        cout << "Lista: " << list.getTitle() << endl;
                        list.displayNotCompleted();
                    }
                    break;
                }
                case 7:{
                    displayAll(toDoLists);
                    break;
                }
                case 8:{
                    string title;
                    bool found = false;
                    cout << "Inserisci il titolo della lista da rimuovere: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    auto it = toDoLists.begin();
                    for(auto& list : toDoLists){
                        if(title == list.getTitle()){
                            found = true;
                            toDoLists.erase(it);
                            break;
                        }
                        else{
                            advance(it, 1);
                        }
                    }
                    if (found) {
                        write(toDoLists);
                        break;
                    }
                    else throw (out_of_range) "Lista non presente";
                }
                case 0:
                    return 0;
                default:
                    break;
            }
        }
        catch (const out_of_range &e) {
            cerr << e.what() << endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const runtime_error &e) {
            cerr << e.what() << endl;
            return 0;
        }
        catch (const invalid_argument &e){
            cerr << e.what() << endl;
            std::cin.clear();
        }
    }
}

void displayAll(const std::list<ToDoList>& lists) {
    for (const auto& list : lists){
        cout << "Lista: " << list.getTitle() << endl;
        list.display();
    }
    cout << endl;
}

void write(const std::list<ToDoList>& lists) {
    fstream file;
    file.open("list.txt", ios::out);
    if (file.is_open()) {
        for (const auto& list : lists) {
            file << list.getTitle() << endl;
            for (const auto& toDo : list.getList()){
                file << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
            }
        }
        file.close();
    } else throw (runtime_error) "Errore scrittura su file";
}

void read(std::list<ToDoList>& lists){
    fstream file;
    file.open("list.txt", fstream::in);
    if (file.is_open()) {
        string line;
        getline(file, line);
        while (!line.empty()) {
            if (line.find("+Completato+") == string::npos && line.find("-Incompleto-") == string::npos){
                ToDoList list(line);
                while (getline(file, line) && (line.find("+Completato+") != string::npos || line.find("-Incompleto-") != string::npos)) {
                    if (line.find("+Completato+") != string::npos) {
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
                        list.add(line, date);
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
                        list.add(line, date);
                    }
                }
                lists.push_back(list);
            }
        }
        file.close();
    } else throw (runtime_error) "Errore lettura da file";
}