//
// Created by Notebook on 16/08/2021.
//

#include "gtest/gtest.h"
#include "../ToDo.h"

TEST(ToDo, TestGetterSetter){
    ToDo t("Fare la spesa");
    ASSERT_EQ(t.getText(), "Fare la spesa");
    ASSERT_EQ(t.isCompleted(), "-Incompleto-");
    t.setCompleted();
    ASSERT_EQ(t.isCompleted(), "+Completato+");
}