//
//  main.cpp
//  cnn_new
//
//  Created by nicomazz on 20/05/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

//#define TEST
#define MAXN 1010

char visited[MAXN][MAXN][2];
int memo[MAXN][MAXN][2]; // evento N, ultima libera, ultima_scelta

#define ULTIMA_R 0
#define ULTIMA_C 1
#define SCELTA_R 2
#define SCELTA_C 3

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}


struct evento
{
    int r,c;
};

evento eventi[MAXN];

int N,M; // n eventi, M lato

int f(int Ni, int last_pos, char last_choice)
{
    if ( Ni > N) return 0;
    
    char & ris = visited[Ni][last_pos][last_choice];
    if ( ris )
        return memo[Ni][last_pos][last_choice];
    
    int att_r,att_c;
    
    if ( Ni == 1)
        att_r = att_c = 1;
    else {
        att_r = (last_choice == ULTIMA_R ? eventi[Ni-1].r: last_pos);
        att_c = (last_choice == ULTIMA_C ? eventi[Ni-1].c: last_pos);
    }
    
    int muovi_r = f(Ni+1, att_c, ULTIMA_R) + abs( att_r - eventi[Ni].r);
    int muovi_c = f(Ni+1, att_r, ULTIMA_C) + abs( att_c - eventi[Ni].c);
    
    if ( muovi_r < muovi_c) {
        ris = SCELTA_R;
        return memo[Ni][last_pos][last_choice] = muovi_r;
    }
    else {
        ris = SCELTA_C;
        return memo[Ni][last_pos][last_choice] = muovi_c;
    }
}

void backtrack()
{
    int att_r = 1, att_c = 1, ultima_scelta = 0, last_pos = 0;
    for (int i = 1; i <= N; i++)
    {
        char & ris_att = visited[i][last_pos][ultima_scelta];
        if ( ris_att == SCELTA_R){
            printf("R\n");
            last_pos = att_c;
            att_r = eventi[i].r;
            ultima_scelta = ULTIMA_R;
        }
        else {
            printf("C\n");
            last_pos = att_r;
            att_c = eventi[i].c;
            ultima_scelta = ULTIMA_C;
        }
    }
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanInt(N); scanInt(M);
    for (int i = 1; i <= N; i++)
        scanInt(eventi[i].r), scanInt(eventi[i].c);
    f(1,0,0);
    backtrack();
    return 0;
}

/*
 
 7 6
 4 2
 5 2
 6 2
 4 3
 4 4
 4 5
 4 6
 */
