// Copyright 2018 Gusev Alexandr

#include "include/Vigner_code.h"
#include <string>

std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned int i, j;
int c, sum;

Vigner_code::Vigner_code() {
}

int Vigner_code::Keycode(char s) {
    for (unsigned int k = 0; k < symbols.length(); k++)
        if (s == symbols[k])
            c = k;
    return c;
}

std::string Vigner_code::Encode(std::string Text, std::string Key) {
    std::string result;
    for (i = 0; i < Text.length(); i++) {
        if (j >= Key.length())
            j = 0;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum + c + 1;
        if (sum > 51)
            sum = sum - 52;
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}

std::string Vigner_code::Decode(std::string Text, std::string Key) {
    std::string result;
    for (i = 0; i < Text.length(); i++) {
        if (j >= Key.length())
            j = 0;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum - c - 1;
        if (sum < 0)
            sum = sum + 52;
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}
