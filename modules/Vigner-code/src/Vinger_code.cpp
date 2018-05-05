#include "include/Vinger_code.h"
string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int i, j, c, sum;
Vinger_code::Vinger_code()
{
}
Vinger_code::~Vinger_code()
{
}
//Функция получения кода символа
int Vinger_code::Keycode(char s)
{
    for (int i = 0; i < symbols.length(); i++)
    if (s == symbols[i])
        c = i;
    return c;
}
//Функция шифрования
string Vinger_code::Encode(string Text, string Key)
{
    string result;
	for (i = 0; i < Text.length(); i++)
	{
        if (j >= Key.length())
            j = 0;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum + c + 1;
        if (sum>51)
            sum = sum - 52;
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}
//Функция дешифрования
string Vinger_code::Decode(string Text, string Key)
{
    string result;
    for (i = 0; i < Text.length(); i++)
    {
        if (j >= Key.length())
            j = 0;
        Keycode(Text[i]);
        sum = c;
        Keycode(Key[j]);
        sum = sum - c - 1;
        if (sum<0)
            sum = sum + 52;
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}