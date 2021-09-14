//
// Created by Notebook on 17/08/2021.
//

#include "gtest/gtest.h"
#include "../ToDoList.h"

TEST(ToDoList, TestRemove){
    ToDoList list("t");
    Date date(20, 10, 2021);
    list.add("Fare la spesa", date, false);
    ASSERT_NO_THROW(list.remove(1));
    ASSERT_THROW(list.remove(999999), std::out_of_range);
}

TEST(ToDoList, TestSetToDoCompleted){
    ToDoList list("t");
    Date date( 17, 9, 2021);
    list.add("Completare progetto", date, false);
    ASSERT_NO_THROW(list.setToDoCompleted(1));
    ASSERT_THROW(list.setToDoCompleted(999999), std::out_of_range);
}