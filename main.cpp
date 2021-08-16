#include <iostream>
#include "ToDo.h"
#include "ToDoList.h"

int main() {
    ToDoList toDoList;
    toDoList.read();

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
                case 1:
                    toDoList.add();
                    break;
                case 2:
                    toDoList.remove();
                    break;
                case 3:
                    toDoList.setToDoCompleted();
                    break;
                case 0:
                    return 0;
                default:
                    break;
            }
        }
        catch (const out_of_range &e) {
            cerr << e.what() << endl;
        }
    }
}