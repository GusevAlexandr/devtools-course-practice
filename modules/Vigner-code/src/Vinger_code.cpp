#include "include/Vinger_code.h"

string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
unsigned int i, j;
int c, sum;

Vinger_code::Vinger_code() {
}

int Vinger_code::Keycode(char s)
{
    for (unsigned int k = 0; k < symbols.length(); k++)
    if (s == symbols[k])
        c = k;
    return c;
}

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