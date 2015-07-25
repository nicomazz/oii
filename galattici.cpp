//
//  main.cpp
//  galattici
//
//  Created by nicomazz on 05/01/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct tripletta
{
    int I,J;
    char c;
};

char S[11];

vector<tripletta> triplette[26];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int M, N, K;
    
    in>>M>>N>>K;
    
    for (int i = 0; i<K;i++)
        in>>S[i];
    
    for (int i = 0; i < M; i++)
    {
        tripletta trip;
        
        int I,J;
        in>>I>>J;
        trip.I = I;
        trip.J = J;
        
        char C;
        in>>C;
        trip.c = C;
        
        triplette[int(C-'a')].push_back(trip);
    }
    
    int ConfAttuale = 1;
    
    for (int i = 0; i<K;i++)
    {
        int indiceDaChar = int(S[i] - 'a');
        
        for (int j = 0; j < triplette[indiceDaChar].size(); j++)
        {
            if (triplette[indiceDaChar].at(j).I == ConfAttuale)
            {
                ConfAttuale = triplette[indiceDaChar].at(j).J;
                break;
            }
        }
        
    }
   // cout<<ConfAttuale;
    
    out<<ConfAttuale;
    
    
    
    return 0;
}

