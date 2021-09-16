//
// Created by Notebook on 17/08/2021.
//

#include "gtest/gtest.h"
#include "../ToDoList.h"

TEST(ToDoList, TestRemove){
    ToDoList list("t");
    Date date(20, 10, 2021);
    list.add("Fare la spesa", date, false);
    auto& l = list.getList();
    ASSERT_EQ(l.empty(), false);
    ASSERT_NO_THROW(list.remove(1));
    ASSERT_EQ(l.empty(), true);
    ASSERT_THROW(list.remove(999999), std::out_of_range);
}

TEST(ToDoList, TestSetToDoCompleted){
    ToDoList list("t");
    Date date( 17, 9, 2021);
    list.add("Completare progetto", date, false);
    auto& l = list.getList();
    auto& s = l.front();
    ASSERT_EQ(s.isCompleted(), false);
    ASSERT_NO_THROW(list.setToDoCompleted(1));
    ASSERT_EQ(s.isCompleted(), true);
    ASSERT_THROW(list.setToDoCompleted(999999), std::out_of_range);
}