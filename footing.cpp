#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;

#define MAXN 1010

struct strada
{
    strada(){}
    strada(int _a,int _l):a(_a),l(_l){}
    int a,l;
};

bool finit[MAXN];
bool visitato[MAXN];
vector<strada> grafo[MAXN];
int dist[MAXN];

int l_min_ciclo = 200000000;

void dfs(int inizio, int att, int l, int n)
{
    if (n >= 3 && att == inizio)
    {
        l_min_ciclo = min(l_min_ciclo,l);
        return;
    }

    if (visitato[att] || l >= l_min_ciclo || finit[att]  ) return;

    visitato[att] = true;

    for (int i = 0; i < grafo[att].size(); i++)
    {
        strada & s = grafo[att][i];
        dfs(inizio, s.a, l + s.l, n+1);
    }
    visitato[att] = false;
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M; // case, tratti di strada
    in>>N>>M;

    int da,a,l;
    for (int i = 0; i < M; i++)
    {
        in>>da>>a>>l;
        grafo[da].push_back(strada(a,l));
        grafo[a].push_back(strada(da,l));
    }

    for (int i = 1; i <= N; i++)
    {
        memset(visitato, false, sizeof(visitato));
        dfs(i,i,0,0);
        finit[i] = true;
    }

    out<<l_min_ciclo;
    //cout<<l_min_ciclo;
    return 0;
}
