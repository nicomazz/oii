#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string.h>
using namespace std;
typedef long long ll;

#define MAXN 100010

typedef pair<ll, ll> pii;
typedef pair<ll,pii> piii;
typedef vector<ll> vii;
typedef unsigned long long ull;
typedef pair<long long,ll> pli;

struct strada
{
    ll a,l;
    strada(ll _a, ll _l)
    {
        a = _a; l = _l;
    }
};

vector<strada> graph[MAXN];
ll dist[MAXN];
int parent[MAXN];
int n;
void bfs(ll start)
{
    memset(dist, ll(2e8), sizeof(dist));

    stack<pii> pila;
    pila.push(pii(0,start));
    parent[start] = -1;

    while (!pila.empty())
    {
        pii att = pila.top();
        pila.pop();

        dist[att.second] = att.first;
        for (auto & s : graph[att.second])
            if (s.a != parent[att.second])
            {
                parent[s.a] = att.second;
                pila.push(pii(att.first + s.l, s.a));
            }

    }

}
int find_center(ll start)
{
    //cout<<"centro?"<<endl;
    bfs(start);

    ll furthest = 0;
    ll val_furthest = 0;
    for (ll i = 0; i < n; i++)
        if (dist[i] > val_furthest)
        {
            val_furthest = dist[i];
            furthest = i;
        }

    bfs(furthest);
    ll new_furthest = 0;
    val_furthest = 0;
    for (ll i = 0; i < n; i++)
        if (dist[i] > val_furthest)
        {
            val_furthest = dist[i];
            new_furthest = i;
        }
       // cout<<"c'�";
    return val_furthest;
}
int main()
{
   ifstream in("input.txt");
   ofstream out("output.txt");

    in>>n;
//cout<<"allora?"<<endl;
    for (int i = 0; i < n-1; i++)
    {
        int da, a, L;
        in>>da>>a>>L;
        da--;a--;

        graph[da].push_back(strada(a,L));
        graph[a].push_back(strada(da,L));
    }
  //  cout<<"quasi"<<endl;
    out<<find_center(0);
    return 0;
}
/*
4 2
3 2
4 2 2
2 1 1
*/
