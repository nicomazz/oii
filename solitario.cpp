//
//  main.cpp
//  tris in solitaria
//
//  Created by nicomazz on 20/02/15.
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
#define MAXN 100010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register int c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
}

int R,C;
bool mat[11][11];
bool vis[11][11];

bool verifica(char pos) // true se si vince mettendola lì
{
    int r = pos / C;
    int c = pos % C;
    
    int mr = max(r-2,0);
    int mc = max(c-2,0);
    
    int Mr = min(R-1,r+2);
    int Mc = min(C-1,c+2);
    
    // orizzontale
    int cnt = 0;
    for (int i = mc; i <= Mc && cnt < 3; i++)
        if (mat[r][i]) cnt++;
        else cnt = 0;
    if (cnt == 3) return true;
    
    //verticale
    cnt = 0;
    for (int i = mr; i <= Mr&& cnt < 3; i++)
        if (mat[i][c]) cnt++;
        else cnt = 0;
    if (cnt == 3) return true;

    // obliquo da susx
     cnt = 0;
    for (int _r = mr, _c = mc; _r <= Mr && _c <= Mc && cnt < 3; _r++,_c++)
        if (mat[_r][_c]) cnt++;
        else cnt = 0;
    if (cnt == 3) return true;
    
    // obliquo da sudx
    cnt = 0;
    for (int _r = mr, _c = Mc; _r <= Mr && _c >= mc && cnt < 3; _r++,_c--)
        if (mat[_r][_c]) cnt++;
        else cnt = 0;
    if (cnt == 3) return true;
    
    return false;
}

int f(int pos)
{
    if (pos >=R*C) return 0;
    char r = pos / C;
    char c = pos % C;

    mat[r][c] = true;
    if (verifica(pos))
    {
        mat[r][c] = false;
        return f(pos+1);
    }
    else
    {
        int mettendo = 1+f(pos+1);
        mat[r][c] = false;
        int non_mettendo = f(pos+1);
        return max(mettendo,non_mettendo);
    }
    // proviamo con questo a false
    
}

int ris[6][6] ={
    { 1, 2, 2, 3, 4, 4 },
    { 0,4, 4, 6, 8, 8 },
    { 0,0,6, 7, 9, 10 },
    { 0,0,0,9, 12, 13 },
    { 0,0,0,0,16, 17 },
    { 0,0,0,0,0,20 }};
int risFinale[10][10] =
{   { 1,2,2,3,4,4,5, 6, 6, 7 },
    { 0,4,4,6,8,8,10, 12, 12, 14 },
    { 0,0,6,7,9,10,12, 14, 15, 17 },
    { 0,0,0,9,12,13,16, 18, 20, 0},
    { 0,0,0,0,16,17,20, 0,0,0},
    { 0,0,0,0,0,20,0,0,0,0},
    { 0,0,0,0,0,0,0,0,0,0},
    { 0,0,0,0,0,0,0,0,0,0},
    { 0,0,0,0,0,0,0,0,0,0},
    { 0,0,0,0,0,0,0,0,0,0}};

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
/*
   
    for (int i = 1; i <= 10; i++)
    {
        cout<<"{ ";
        for (int j = 1; j <= 10; j++)
        {
            if (i*j > 36 || j < i) cout<<"0,";
            
            else{
                
                if (i <=6 && j  <= 6)
                    cout<<ris[i-1][j-1]<<",";
                else
                {
                    memset(mat, 0, sizeof mat);
                    R = i; C = j;
                    cout<<f(0)<<", ";
                }
            }
            //cout<<i<<"  x  "<<j<<"   =  "<<f(0)<<endl;
        }
        cout<<"},\n";
    }*/
    scanInt(R); scanInt(C);
    cout<<risFinale[min(R-1,C-1)][max(R-1,C-1)];

   // cout<<f(0);
    return 0;
}
/**
 { 1,2,2,3,4,4,5, 6, 6, 7, },
 { 0,4,4,6,8,8,10, 12, 12, 14, },
 { 0,0,6,7,9,10,12, 14, 15, 17, },
 { 0,0,0,9,12,13,16, 18, 20, 0,},
 { 0,0,0,0,16,17,20, 0,0,0,},
 { 0,0,0,0,0,20,0,0,0,0,},
 { 0,0,0,0,0,0,0,0,0,0,},
 { 0,0,0,0,0,0,0,0,0,0,},
 { 0,0,0,0,0,0,0,0,0,0,},
 { 0,0,0,0,0,0,0,0,0,0,},*/
/**
 { 1, 2, 2, 3, 4, 4, },
 { 0,4, 4, 6, 8, 8, },
 { 0,0,6, 7, 9, 10, },
 { 0,0,0,9, 12, 13, },
 { 0,0,0,0,16, 17, },
 { 0,0,0,0,0,20, },
 */
