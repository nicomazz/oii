//
//  main.cpp
//  divisori
//
//  Created by nicomazz on 25/02/15.
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

inline void scanInt(int &x)
{
    register char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}



int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, A,B;
    // 1 2 2 3 4 5 6 6
    // n = 4
    //acc 1 4
    //att 2 5
    // 1 2 2 3 4 5 6 6 7 8 9 10 11 12 12 13 14 15 16 17 18 19 20 20 21 22 23 24 25 26 27 28 29 30 30 31 32 33 34 35 36 37 38 39 40 41 42 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90
   
    scanInt(N); scanInt(A); scanInt(B);
   // for (N = 2; N < 100; N++)
    //{
        int accese = 0;
        int cnt = 1;
        for (int i = 2; ; i+=2)
        {
            accese+= i;
            cnt+=i;
            if (cnt >= N)
            {
                cout<< accese- (cnt-N) <<endl;
                break;
            }
            
            cnt++;
        }// cout<<accese<<endl;
       // cout<<accese<<" ";
      //  cout<<"N: "<<N<<"   "<<accese<<endl;
  //  }
    
  //  cout<<accese<<endl;
    
    return 0;
}


