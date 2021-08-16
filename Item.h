//
// Created by Notebook on 11/08/2021.
//

#ifndef ELABORATOTODOLIST_ITEM_H
#define ELABORATOTODOLIST_ITEM_H

#include "string"
using namespace std;

class Item {
public:

    explicit Item(const string& newTitle, const string& isCheck = "-Incompleta-") : title{newTitle}, check{isCheck} {}

    ~Item() = default;

    void setCheck(const string &completed) {
        Item::check = completed;
    }

    const string &getTitle() const {
        return title;
    }

    const string &getCheck() const {
        return check;
    }

private:
    string title;
    string check;
};


#endif //ELABORATOTODOLIST_ITEM_H
