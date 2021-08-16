//
// Created by Notebook on 16/08/2021.
//

#include "gtest/gtest.h"
#include "../ToDo.h"



TEST(ToDo,GetterSetter){
    ToDo t("Fare la spesa");
    ASSERT_EQ(t.getText(), "Fare la spesa");
    ASSERT_EQ(t.isCompleted(), "-Incompleta-");
    t.setCompleted();
    ASSERT_EQ(t.isCompleted(), "+Completata+");
}