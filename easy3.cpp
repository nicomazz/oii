//
//  main.cpp
//  somma pari massima
//
//  Created by nicomazz on 03/05/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long  ll;


int main(int argc, const char * argv[])
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    
    ll N;
    in>>N;
    
    ll numtmp;
    
    ll pari[2] = {-1,-1},dispari[2] = {-1,-1};
    
    for (int i = 0; i < N; i++)
    {
        in>>numtmp;
        
        if (numtmp%2 == 0) // pari
        {
            if (numtmp >= pari[0])
            {
                pari[1] = pari[0];
                pari[0] = numtmp;
            }
            else if (numtmp > pari[1])
            {
                pari[1] = numtmp;
            }
        }
        else
        {
            if (numtmp >= dispari[0])
            {
                dispari[1] = dispari[0];
                dispari[0] = numtmp;
            }
            else if (numtmp > dispari[1])
                dispari[1] = numtmp;
        }
        
    }
    
    ll sum1;
    ll sum2;
    if (pari[1] != -1 || dispari[1] != -1)
    {
        sum1 = pari[1]+pari[0];
        sum2 = dispari[1]+dispari[0];
        out<<(sum1>sum2?sum1:sum2);
    }
    else out<<-1;
    return 0;
}

