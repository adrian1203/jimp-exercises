//
// Created by adrian on 04.03.17.
//

#include "Palindrome.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    cout<<"Sprawdź wyraz wciśnij s, wyjscie wciśnij inny znak:"<<endl;
    char wybor;
    cin>>wybor;
    if(wybor=='s')
    {
        std::string wyraz;
        std::cout<<"Podaj napis:";
        cout<<endl;
        std::cin>>wyraz;
        if(is_palindrome(wyraz)==true)
        {
            cout<<"Ten napis jest palindromem";
        }
        else
        {
            cout<<"Ten napis nie jest palindromem";
        }
        return 0;
    }
    else
    {
        return 0;
    }
    return 0;
}