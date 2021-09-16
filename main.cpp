#include "ToDo.h"
#include "ToDoList.h"
#include "SetOfLists.h"
#include <limits>
#include <iostream>
#include <fstream>

void write( SetOfLists& setOfLists);
void read(SetOfLists& setOfLists);


int main() {
    SetOfLists setOfLists;
    try{
        read(setOfLists);
        write(setOfLists);
    } catch (const runtime_error &e){
        cerr << e.what() << endl;
        return 0;
    }
    setOfLists.displayAll();

    while (true) {
        cout << "/ Menu /" << endl;
        cout << "1) Crea nuova lista" << endl;
        cout << "2) Rimuovi lista" << endl;
        cout << "3) Aggiungi todo" << endl;
        cout << "4) Rimuovi todo" << endl;
        cout << "5) Imposta completato" << endl;
        cout << "6) Visualizza completati" << endl;
        cout << "7) Visualizza non completati" << endl;
        cout << "8) Visualizza tutti" << endl;
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
                    setOfLists.newList(title);
                    write(setOfLists);
                    break;
                }
                case 2:{
                    string title;
                    cout << "Inserisci il titolo della lista da rimuovere: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    setOfLists.removeList(title);
                    write(setOfLists);
                    break;
                }
                case 3:{
                    string title;
                    bool found = false;
                    cout << "Scrivi il titolo della lista dove inserire il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : setOfLists.getSetOfLists()){
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
                            list.add(text, date, false);
                            write(setOfLists);
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
                    cout << "Scrivi il titolo della lista dove rimuovere il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : setOfLists.getSetOfLists()){
                        if(title == list.getTitle()){
                            int pos;
                            found = true;
                            cout << "Inserisci il numero del ToDo da rimuovere: ";
                            cin >> pos;
                            cout << endl;
                            list.remove(pos);
                            write(setOfLists);
                            break;
                        }
                    }
                    if(found)
                        break;
                    else throw (invalid_argument) "Lista non presente";
                }
                case 5:{
                    string title;
                    bool found = false;
                    cout << "Scrivi il titolo della lista dove segnare come completato il toDo: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << endl;
                    for(auto& list : setOfLists.getSetOfLists()){
                        if(title == list.getTitle()){
                            int pos;
                            found = true;
                            cout << "Inserisci il numero del ToDo da segnare come completato: ";
                            cin >> pos;
                            cout << endl;
                            list.setToDoCompleted(pos);
                            write(setOfLists);
                            break;
                        }
                    }
                    if(found)
                        break;
                    else throw (out_of_range) "Lista non presente";
                }
                case 6:{
                    for (auto& list : setOfLists.getSetOfLists()){
                        cout << "Lista: " << list.getTitle() << endl;
                        list.displayCompleted();
                    }
                    break;
                }
                case 7:{
                    for (auto& list : setOfLists.getSetOfLists()){
                        cout << "Lista: " << list.getTitle() << endl;
                        list.displayNotCompleted();
                    }
                    break;
                }
                case 8:{
                    setOfLists.displayAll();
                    break;
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



void write( SetOfLists& setOfLists) {
    fstream file;
    file.open("list.txt", ios::out);
    if (file.is_open()) {
        for (const auto& list : setOfLists.getSetOfLists()) {
            file << list.getTitle() << endl;
            for (const auto& toDo : list.getList()){
                file << toDo.getText() << "   " << toDo.convertCompleted() << "   "  << toDo.getDate().getDay() << "/" << toDo.getDate().getMonth() << "/" << toDo.getDate().getYear() << endl;
            }
        }
        file.close();
    } else throw (runtime_error) "Errore scrittura su file";
}



void read(SetOfLists& setOfLists){
    fstream file;
    auto& lists = setOfLists.getSetOfLists();
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
                        list.add(line, date, true);
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
                        list.add(line, date, false);
                    }
                }
                lists.push_back(list);
            }
        }
        file.close();
    } else throw (runtime_error) "Errore lettura da file";
}