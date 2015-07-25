//
//  main.cpp
//  talmart
//
//  Created by nicomazz on 12/06/15.
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


typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;
typedef pair<ull, ull> pi;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

#define iOS ios_base::sync_with_stdio(false)
#define error(x) cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}


pi start, fine;
vector<pi> all_q;
vector<pi> ord_q;

#define MAXS 1000100
ll spost1[MAXS];
ll spost2[MAXS];
int x_dest;
int quad_fino_x_y(int x_arrivo, int y_max, bool sopra){
    int cnt = 0;
    if ( sopra)
    {
        while ( x_dest < ord_q.size() && ord_q[x_dest].first < x_arrivo) {
            if (  ord_q[x_dest].second > y_max) cnt++;
            x_dest++;
            }
    }
    else
    {
        while ( x_dest < ord_q.size() && ord_q[x_dest].first <= x_arrivo) {
            if (  ord_q[x_dest].second < y_max) cnt++;
            x_dest++;
            }
    }

  //  cout<<"x arrivo, ymax: " <<x_arrivo<<"  "<<y_max<<"  "<<cnt<<endl;
    return cnt;
}
void normalizza(ll * v)
{
    int isx = 0, idx = 1, iatt = 0;

    while (v[isx] != 0)
    {
        v[iatt] = v[isx];
        bool s_sx = v[isx] > 0;
        while (v[idx] != 0 && ((v[idx] > 0) == s_sx))
            v[iatt] += v[idx++];
        isx = idx++;
        iatt++;
    }
    if ( iatt < isx) v[iatt] = 0;


}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
   iOS;
/*
int o = 10,p =10;
cout<<o*p+1<<endl;
for (int i = 1; i <=o ; i++)
    for (int j = 1; j <=p ;j++)
    cout<<i<<" "<<j<<endl;
*/
   int Q;
   cin>>Q;

   cin>>start.first>>start.second;
   fine = start;
    pi att;
    all_q.reserve(Q);
   for (int i  = 0; i < Q; i++)
   {
       cin>>att.first>>att.second;
       if (att.first >= start.first && att.second >= start.second)
        all_q.push_back(att);
   }

    int ind_s = 0;
    cin>>spost1[0];
    while ( spost1[ind_s] != 0){
       if ( spost1[ind_s]< 0)
        fine.first-= spost1[ind_s];
       else fine.second += spost1[ind_s];
       cin>>spost1[++ind_s];
   }

//cout<<"fine: "<<end.first<<"  "<<end.second<<endl;

    ind_s = 0;
    cin>>spost2[0];
    while ( spost2[ind_s] != 0){
            ind_s++;
       cin>>spost2[ind_s];
   }

    ord_q.reserve(all_q.size());

   for (int i = 0; i < all_q.size(); i++)
   {
       if (all_q[i].first <= fine.first &&
           all_q[i].second <= fine.second)
            ord_q.push_back(all_q[i]);
   }
   sort(all(ord_q));
    normalizza(spost1);
    normalizza(spost2);


    if ( spost1[0] < spost2[0]) swap(spost1,spost2);

 /*   cout<<"normalizzati 1: ";
 for (int i = 0; spost1[i];i++) cout<<spost1[i]<<"  ";

     cout<<"\nnormalizzati 2: ";
    for (int i = 0; spost2[i];i++) cout<<spost2[i]<<"  ";
        */
//cin>>ind_s;

    ull ris = 0;
    int i = 0;
    pi punto = start;
    while (spost1[i] != 0)
    {
        if ( spost1[i] > 0 )
            punto.second += spost1[i]; // su
        else
        {
            punto.first  -= spost1[i]; // dx
            ris += quad_fino_x_y(punto.first,punto.second,true);
        }
        i++;
    }

    x_dest = 0;

    i = 0;
    punto = start;
    while (spost2[i] != 0)
    {
        if ( spost2[i] < 0)
        {
            punto.first   -= spost2[i];
            ris += quad_fino_x_y(punto.first,punto.second,false);
        }
        else
            punto.second  += spost2[i];
        i++;
    }
    cout<<ord_q.size()-ris;
   // cout<<"  "<<ord_q.size();
    return 0;
}
/*
100
3 2
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
3 1
3 2
3 3
3 4
3 5
3 6
3 7
3 8
3 9
3 10
4 1
4 2
4 3
4 4
4 5
4 6
4 7
4 8
4 9
4 10
5 1
5 2
5 3
5 4
5 5
5 6
5 7
5 8
5 9
5 10
6 1
6 2
6 3
6 4
6 5
6 6
6 7
6 8
6 9
6 10
7 1
7 2
7 3
7 4
7 5
7 6
7 7
7 8
7 9
7 10
8 1
8 2
8 3
8 4
8 5
8 6
8 7
8 8
8 9
8 10
9 1
9 2
9 3
9 4
9 5
9 6
9 7
9 8
9 9
9 10
10 1
10 2
10 3
10 4
10 5
10 6
10 7
10 8
10 9
10 10

+3 -3 +1 -2 +1 -2 0
-2 -2 +1 -1 +1 -1 +1 -1 +2 0

5
3 2
2 7
4 5
5 3
8 5
9 2
+3 -3 +1 -2 +1 -2 0
-2 -2 +1 -1 +1 -1 +1 -1 +2 0
*/
