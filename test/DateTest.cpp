//
// Created by Notebook on 12/09/2021.
//

#include "gtest/gtest.h"
#include "../Date.h"


TEST(Date, TestIsLeap){
    Date date(24, 8, 2024);
    ASSERT_EQ(date.isLeap(), true);
    date.setYear(2018);
    ASSERT_EQ(date.isLeap(), false);
}

TEST(Date, TestDaysOfMonth){
    Date date(30, 2, 2021);
    ASSERT_EQ(date.daysOfMonth(), 28);
}

TEST(Date, TestValidityDate){
    Date date(10, 5, 2022);
    ASSERT_EQ(date.validityDate(), true);
    date.setDay(29);
    date.setMonth(2);
    ASSERT_THROW(date.validityDate(), std::out_of_range);
    date.setYear(2024);
    ASSERT_NO_THROW(date.validityDate());
}