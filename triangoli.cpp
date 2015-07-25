//
//  main.cpp
//  triangoli
//
//  Created by Nicolò Mazzucato on 20/07/15.
//  Copyright (c) 2015 Nicolò Mazzucato. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 1000010

typedef long long ll;
struct point{
    ll x,y;
    bool operator<(const point & b)const {
        return x < b.x || (x == b.x && y < b.y);
    }
};

 ll cross(point & O, point &A, point &B){
    return  (ll)(A.x - O.x) * (B.y - O.y) - (ll)(A.y - O.y) * (B.x - O.x);
}

point results[MAXN];
point points[MAXN];
int N;
int convex_hull()
{
    sort(points, points+N);
    int ind = 0;
    
    for (int i = 0; i < N; i++){
        while (ind >= 2 && cross(results[ind-2],results[ind-1],points[i]) <=0) ind--;
        results[ind++] = points[i];
    }
    
    int lower_cnt = ind+1;
    for (int i = N-2; i >= 0; i--)
    {
        while (ind >= lower_cnt && cross(results[ind-2],results[ind-1],points[i]) <=0)ind--;
        results[ind++] = points[i];
    }
    ind--;
    return ind;
}
#define gc getchar_unlocked

inline void scanInt(ll &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}
int main(int argc, const char * argv[]) {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
    //ios::sync_with_stdio(false);
    
    cin>>N;
    for (int i = 0;i  < N; i++)
        scanInt(points[i].x), scanInt(points[i].y);
    
    int convex_number =convex_hull();
    cout<<convex_number;
  /*
    cout<<endl;
    for (int i = 0; i < convex_number;i++)
        cout<<results[i].x<<" "<<results[i].y<<endl;
    */
    return 0;
}
/*
 7
 -1 2
 -1 5
 -2 3
 -3 1
 1 -1
 -2 -1
 -3 -4
 */
