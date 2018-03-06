#pragma once
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
class Menu
{
private:
    vector<string> menu;
public:
    string choice;
    string exit = "0";
    void print()
    {
        int i = 1;
        for (string &s : menu)
            cout << i++ << ") " <<s << '\n';
        cout << "press '" << exit <<"' to exit\n\n";
    }
    void clear()
    {
        system("cls");
    }
    void push_back(string s)
    {
        menu.push_back(s);
    }
};