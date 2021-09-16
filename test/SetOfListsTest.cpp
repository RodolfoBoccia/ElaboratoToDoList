//
// Created by Notebook on 16/09/2021.
//

#include "gtest/gtest.h"
#include "../SetOfLists.h"

TEST(SetOfLists, TestNewList){
    SetOfLists lists;
    auto& l = lists.getSetOfLists();
    ASSERT_EQ(l.empty(), true);
    lists.newList("lavoro");
    ASSERT_EQ(l.empty(), false);
    ASSERT_THROW(lists.newList("lavoro"), std::invalid_argument);
}

TEST(SetOfLists, TestRemoveList){
    SetOfLists lists;
    auto& l = lists.getSetOfLists();
    lists.newList("lavoro");
    ASSERT_EQ(l.empty(), false);
    lists.removeList("lavoro");
    ASSERT_EQ(l.empty(), true);
    ASSERT_THROW(lists.removeList("sport"), std::out_of_range);
}