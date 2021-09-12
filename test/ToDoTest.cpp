//
// Created by Notebook on 16/08/2021.
//

#include "gtest/gtest.h"
#include "../ToDo.h"

TEST(ToDo, TestGetterSetter){
    Date date( 20, 10, 2021);
    ToDo t("Fare la spesa", date);
    ASSERT_EQ(t.getText(), "Fare la spesa");
    ASSERT_EQ(t.isCompleted(), false);
    t.setCompleted();
    ASSERT_EQ(t.isCompleted(), true);
}