#include "ToDo.h"
#include "ToDoList.h"
#include <limits>
#include <iostream>

int main() {
    ToDoList toDoList;
    try{
        toDoList.read();
        toDoList.write();
    } catch (const runtime_error &e){
        cerr << e.what() << endl;
        return 0;
    }


    while (true) {
        toDoList.display();
        cout << "/ Menu /" << endl;
        cout << "1) Aggiungi" << endl;
        cout << "2) Rimuovi" << endl;
        cout << "3) Imposta completato" << endl;
        cout << "0) Esci" << endl << endl;

        int choice;
        cout << "Scrivi il numero dell'operazione da eseguire: ";
        cin >> choice;
        cout << endl;

        try {
            switch (choice) {
                case 1:{
                    string text;
                    cout << "Inserisci la descrizione del nuovo toDo: ";
                    cin.ignore();
                    getline(cin, text);
                    cout << endl;
                    toDoList.add(text);
                    toDoList.write();
                    break;
                }
                case 2:{
                    int pos;
                    cout << "Inserisci il numero del ToDo da rimuovere: ";
                    cin >> pos;
                    cout << endl;
                    toDoList.remove(pos);
                    toDoList.write();
                    break;
                }
                case 3:{
                    int pos;
                    cout << "Inserisci il numero del ToDo da segnare come completato: ";
                    cin >> pos;
                    cout << endl;
                    toDoList.setToDoCompleted(pos);
                    toDoList.write();
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
    }
}