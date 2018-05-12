// Copyright 2018 Gusev Alexandr

#include <gtest/gtest.h>
#include <string>
#include "include/Vigner_code.h"

TEST(Gusev_Alexandr_VignerCodeTest, Can_Get_Symbol) {
    // Arrange
    Vigner_code vigner;
    char sym = 'e';
    // Act
    int res = vigner.Keycode(sym);
    // Assert
    int ans = 4;
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Can_Encode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "abcABC";
    std::string Key = "abc";
    // Act
    std::string res = vigner.Encode(Text, Key);
    // Assert
    std::string ans = "bdfBDF";
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Can_Decode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "bdfBDF";
    std::string Key = "abc";
    // Act
    std::string res = vigner.Decode(Text, Key);
    // Assert
    std::string ans = "abcABC";
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Encode_and_Decode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "ajffAZBtC";
    std::string Key = "abcZs";
    // Act
    std::string res = vigner.Encode(Text, Key);
    std::string res2 = vigner.Decode(res, Key);
    // Assert
    EXPECT_EQ(res2, Text);
}
