// Copyright 2018 Gusev Alexandr

#ifndef MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_
#define MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_
#include <iostream>
#include <string>
using namespace std;

class Vinger_code {
public:
    Vinger_code();
    int Keycode(char s);
    string Encode(string Text, string Key);
    string Decode(string Text, string Key);
};

#endif  // MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_