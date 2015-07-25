//
//  main.cpp
//  supereroi
//
//  Created by nicomazz on 29/05/15.
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
#include <stdio.h>


using namespace std;

//#define TEST
#define MAXN 2049

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;
int N, P;

bool mat[MAXN][MAXN];
bool usati_ora[MAXN];

void find_first_free(int r_partenza)
{
    for (; r_partenza <= N; r_partenza++)
    {
        if ( usati_ora[r_partenza]) { continue;}
        
        for (int i = r_partenza+1; i <= N; i++)
            if (usati_ora[i] == false &&  mat[r_partenza][i] == false)
            {
                mat[r_partenza][i] =true;
                usati_ora[i] = true;
                usati_ora[r_partenza] = true;
               // cout<<r_partenza<<" "<<i<<" ";
                return ;
            }
    }
}
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    scanf("%d %d",&N,&P);

    if ( P == 1)
    {
        int dt = 0;
        
        int avv;
        for (int i = 0; i < N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                avv = j + dt;
                if (avv > N) avv-=N;
                writeInt(j);  printf(" "); writeInt(avv); printf(" ");
              //  cout<<j<<" "<<avv<<" ";
            }
            printf("\n");
            //cout<<"\n";
            dt++;
        }
    }
    else
    {
        int n_mezzi = N/2;

        deque<int> h1,h2;

        for(int i = 0; i < n_mezzi; i++) h1.push_back(i+1), h2.push_back(N-i);
       
        for (int i = 0; i < N-1; i++)
        {
            for (int j = 0; j < n_mezzi; j++)
            {
                writeInt(h1[j]);  printf(" "); writeInt(h2[j]); printf(" ");

//                cout<<h1[j]<<" "<<h2[j]<<" ";
            }printf("\n");//cout<<"\n";
            
            h1.pop_front();
            h2.push_back(h1.back());
            h1.pop_back();
            h1.push_front(h2.front());
            h2.pop_front();
            h1.push_front(1);
        }
        
    }
    return 0;
}


