//
//  main.cpp
//  Helloworld
//
//  Created by nicomazz on 29/11/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main(int argc, const char * argv[])
{

    string s;

    cin>>s;

    string h = "hello";
    string w = "world";

    ll ris =0;

    ll cntH = 0;
    ll sz = s.size();
    int indH = 0, indW = 0;
    if ( sz < 6){cout<<0; return 0;}
    for (ll i = 0; i < sz-4; i++)
    {
        if (s[i] == 'h' && s[i+1] == 'e' && s[i+2] == 'l'&& s[i+3] == 'l'&& s[i+4] == 'o')
        {
            cntH++;
        }
        else if (s[i] == 'w' && s[i+1] == 'o' && s[i+2] == 'r'&& s[i+3] == 'l'&& s[i+4] == 'd')
        {
            ris+=cntH; indW = 0;
        }
    }
    cout<<ris;
    return 0;
}

