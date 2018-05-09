//Copyright 2018 Gusev Alexandr 

#include <gtest\gtest.h>
#include "include\Vinger_code.h"

TEST(Gusev_Alexandr_VingerCodeTest, Can_Get_Symbol)
{
    // Arrange
    Vinger_code vinger;
    char sym = 'e';
    // Act
    int res = vinger.Keycode(sym);
    // Assert
    int ans = 4;
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VingerCodeTest, Can_Encode_Symbol)
{
    // Arrange
    Vinger_code vinger;
    string Text = "abcABC";
    string Key = "abc";
    // Act
    string res = vinger.Encode(Text, Key);
    // Assert
    string ans = "bdfBDF";
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VingerCodeTest, Can_Decode_Symbol)
{
    // Arrange
    Vinger_code vinger;
    string Text = "bdfBDF";
    string Key = "abc";
    // Act
    string res = vinger.Decode(Text, Key);
    // Assert
    string ans = "abcABC";
    EXPECT_EQ(res, ans);
}



