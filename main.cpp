#include <iostream>
#include "Item.h"
#include "ToDoList.h"

int main() {
    ToDoList elenco;
    elenco.read();

    while(true)
    {
        elenco.display();
        cout << "/ Menu /" << endl;
        cout << "1) Aggiungi" << endl;
        cout << "2) Rimuovi" << endl;
        cout << "3) Imposta completato" << endl;
        cout << "0) Esci" << endl << endl;

        int choice;
        cout << "Scrivi il numero dell'operazione da eseguire: ";
        cin >> choice;
        cout << endl;

        try{
            switch (choice) {
                case 1:
                    elenco.add();
                    break;
                case 2:
                    elenco.remove();
                    break;
                case 3:
                    elenco.check();
                    break;
                case 0:
                    return 0;
                default:
                    break;
            }
        }
        catch (const out_of_range& e){
            cerr << e.what() << endl;
        }
    }
}