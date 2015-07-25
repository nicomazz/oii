//
//  main.cpp
//  tris2
//
//  Created by nicomazz on 02/06/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <bitset>

using namespace std;

//#define TEST
#define MAXN 100010

typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

#define iOS ios_base::sync_with_stdio(false)
#define error(x) cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#define gc getchar // getchar_unlocked

inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}

int i = 0;
#define colonne(x,y,z)  griglia[0][x] == c && griglia[1][y] == c && griglia[2][z] == c

bool trovaVittoria(char griglia[3][3], char c)
{
    if ((griglia[0][0] == c && griglia[0][1] == c && griglia[0][2] == c) || /// -
        (griglia[1][0] == c && griglia[1][1] == c && griglia[1][2] == c) ||
        (griglia[2][0] == c && griglia[2][1] == c && griglia[2][2] == c) ||
        (griglia[0][0] == c && griglia[1][0] == c && griglia[2][0] == c) || /// |
        (griglia[0][1] == c && griglia[1][1] == c && griglia[2][1] == c) ||
        (griglia[0][2] == c && griglia[1][2] == c && griglia[2][2] == c) ||
        (griglia[0][0] == c && griglia[1][1] == c && griglia[2][2] == c) ||
        (griglia[0][2] == c && griglia[1][1] == c && griglia[2][0] == c)) return true;
    
    return false;
}
bool patta(char griglia[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) if (griglia[i][j] == '.') return false;
    return true;
}

bool vincente(char griglia[3][3], bool x)
{
    if (trovaVittoria(griglia, !x)) return false;
    if ( patta(griglia)) return true;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (griglia[i][j] == '.')
            {
                griglia[i][j] = x;
                if (!vincente(griglia,!x)){griglia[i][j] = '.'; return true;}
                griglia[i][j] = '.';
            }
    return false;
}

int vincente(char griglia[3][3]) {
    
    int x = 0, o = 0;
    
    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (griglia[i][j] == 'X') griglia[i][j] = 1, x++;
            else if (griglia[i][j] == 'O') griglia[i][j] = 0, o++;
    
    
    char turno;
    if (x > o) turno = false;
    else turno = true;
    
  
    bool ris = vincente(griglia, turno);
    
    
    return turno ? ris:!ris;
}


char griglia[3][3];


int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin>>griglia[i][j];
    
    cout<<vincente(griglia);
    
    return 0;
}
