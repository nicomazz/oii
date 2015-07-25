//
//  main.cpp
//  Deciphering the Mayan writing
//
//  Created by nicomazz on 05/01/15.
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
#include <time.h>
#include <string.h>

using namespace std;

//#define TEST
#define MAXA 5010
#define MAXB 5000010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
void getString(char* stringa)
{
    register char c = getchar_unlocked();
    while (c < 'A' || c > 'z') c = getchar_unlocked();
    int ind = 0;
    for(;c>= 'A' && c<= 'z';c = getchar_unlocked())stringa[ind++] = c;
}
char parola1[MAXA];
char parola2[MAXB];
int firmaParola[130]; // tutte le lettere

int A,B;
bool presenti[130]; // le presenti sono a true
int verifica[130];

stack<int> da_controllare;
int att;
int controlla_uguaglianza()
{
    while (!da_controllare.empty())
    {
        att = da_controllare.top();
        if ( firmaParola[att] != verifica[att]) return 0;
        else da_controllare.pop();
    }
    return 1;
}
int controlla(int da, int a) // a esclusa
{
    if (a-da < A) // lunghezza parola
        return 0;
    
    memset(verifica, 0, sizeof(verifica));
    int ris = 0;
    int intervallo = a-da;
    int fino = da+intervallo-A;

    for (int j = 0; j < A; j++)
        verifica[parola2[da+j]]++;
    for (int j = 'A'; j < 'z'; j++)
        if (verifica[j] != firmaParola[j]) da_controllare.push(j);
    
    ris+=controlla_uguaglianza();
    for (int i = da; i < fino; i++)
    {
        verifica[parola2[i]]--;
        verifica[parola2[i+A]]++;
        da_controllare.push(parola2[i+A]);
        ris+= controlla_uguaglianza();
    }
    return ris;
    
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    scanInt(A); scanInt(B);
    
   
    getString(parola1);
    for (int i = 0; i < A; i++)
        firmaParola[parola1[i]]++;
    
    getString(parola2);

    printf("%d",controlla(0, B));
        
    
    return 0;
}

