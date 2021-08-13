#include <iostream>
#include <fstream>
#include "Item.h"
#include "ToDoList.h"

int main() {
    ToDoList elenco;
    while(true)
    {
        cout << "1) Add" << endl;
        cout << "2) remove" << endl;
        cout << "3) Check" << endl;
        cout << "0) quit" << endl;

        string choice;
        cin >> choice;

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
    return 0;
}
