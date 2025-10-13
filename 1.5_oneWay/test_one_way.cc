#include "gtest/gtest.h"

extern "C"{
    #include "one_way.h"
}

TEST(TestOneWay, HelloTest) {
    EXPECT_EQ(4, hello());
}

TEST(TestOneWay, OneWayTest) {
    char* str1 = "pale";
    char* str2 = "pales";
    char* str3 = "bake";
    char* str4 = "babe";
    char* str5 = "dade";
    char* str6 = "bad";
    char* str7 = "apple";
    char* str8 = "appl";
    char* str9 = "appa";

    EXPECT_TRUE(one_way(str1, str2));
    EXPECT_FALSE(one_way(str1, str3));
    EXPECT_TRUE(one_way(str3, str4));
    EXPECT_TRUE(one_way(str4, str5));
    EXPECT_FALSE(one_way(str4, str6));
    EXPECT_TRUE(one_way(str7, str8));
    EXPECT_FALSE(one_way(str7, str9));


}