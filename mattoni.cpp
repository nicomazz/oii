//
//  main.cpp
//  mattoni
//
//  Created by nicomazz on 02/02/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <algorithm>

using namespace std;

#define MAXN 1000100

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int altezze[MAXN];

int main(int argc, const char * argv[])
{
    int N, M;
    scanInt(N); scanInt(M);
    int da, a;
    for (int i = 0; i < M; i++) scanInt(da), scanInt(a),altezze[--da]++, altezze[a]--;
    for (int i = 1; i <N; i++) altezze[i]+= altezze[i-1];
    nth_element(altezze, altezze+N/2, altezze+N);
    printf("%d",altezze[N/2]);
    return 0;
}

