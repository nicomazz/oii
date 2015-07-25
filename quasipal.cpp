//
//  main.cpp
//  quasipal
//
//  Created by nicomazz on 22/12/13.
//  Copyright (c) 2013 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define REP(i,d,a) for (int i = (d); i < (a); i++)

using namespace std;


int mat[9][9];
int perm[9];

int M,N;


bool colonnePal()
{
    REP(c, 0, N)
    for (int i = 0, f=M-1; i < f; i++,f--)
    {
        int ri = perm[i]; int rf = perm[f];
        if (mat[ri][c] != mat[rf][c] && mat[ri][c] != 0 && mat[rf][c] != 0) return false;
    }
    return  true;
    
}

int main(int argc, const char * argv[])
{

    ifstream in ("input.txt");
    ofstream out ("output.txt");
    
    in>>M>>N;
    string tmp;
    getline(in, tmp);
    REP(i, 0, M)
    {
        getline(in, tmp);
        REP(j, 0, tmp.size())
        mat[i][j] = tmp[j]-'0';
    }
  
    REP(i, 0,M)
        perm[i] = i;
        
    do if (colonnePal()) break; while(next_permutation(perm, perm+ M));
    
    REP(i, 0, M)
    {
        REP(j, 0, N)
            out<<mat[perm[i]][j];
        out<<endl;
    }
   
    return 0;
}

