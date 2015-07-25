//
//  main.cpp
//  sottostringa
//
//  Created by nicomazz on 25/11/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

char car[1000001];

int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    
    ios_base::sync_with_stdio(false);
    int n;

    in>>n;
    
    for (int i = 0; i < n; i++)
        in>>car[i];
    
    char carMax = 0;
    int posPrec = 0;
    
    for (int i = 0; i < n;i++)
    {
        if (car[i] > carMax)
        {
            carMax = car[i];
            posPrec = i;
           // while (car[i+1] == carMax)i++;
        }
        else if (car[i] < carMax);
        else // se è uguale
        {
            int a = i,p = posPrec;
            while(car[a] == car[p] && a<n)
                a++,p++;
            
            if (a == n)
            {
                out<<posPrec;
                return 0;
            }
            else if (car[p] < car[a] )//|| p == i)
            {
                posPrec = i;
                while (car[i+1] == carMax)i++;

            }
        }
    }
    
    out<<posPrec;
    return 0;
}

