#include <iostream>
#include <fstream>
#include "Item.h"
#include "ToDoList.h"

int main() {
    ToDoList elenco;
    while(true)
    {
        cout << "Scrivi il numero dell'operazione scelta" << endl;
        cout << "1) Aggiungi" << endl;
        cout << "2) Rimuovi" << endl;
        cout << "3) Imposta completato" << endl;
        cout << "0) Esci" << endl;

        string choice;
        cin >> choice;

        try{
            if (choice == "1") {
                elenco.add();
            } else if (choice == "2") {
                elenco.remove();
            } else if (choice == "3") {
                elenco.check();
            } else if (choice == "0"){
                break;
            }
        }
        catch (const out_of_range& e){
            cerr << e.what() << endl;
        }
    }
    return 0;
}
