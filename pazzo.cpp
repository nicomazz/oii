#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pc[300001];
ll posPC[300001];

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    ll N,M;
    
    in>>N>>M; // N:pc
    
    for (ll i = 0; i < N; i++)
    {
        pc[i] = i;
        posPC[i] = i;
    }
    
    ll tmpa,tmpb;

    ll pc0 = 0;
    for (ll i = 0; i < M; i++)
    {
        in>>tmpa>>tmpb;
        if (tmpa == pc0 || tmpb == pc0)
        {
            swap(pc[posPC[tmpa]],pc[posPC[tmpb]]);
            swap(posPC[tmpa],posPC[tmpb]);
            if (tmpa == pc0) pc0 = tmpb;
            else pc0 = tmpa;
        }
   
        
    }
    out<<pc[0];
    return 0;
}