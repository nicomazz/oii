#include <stdio.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define MAXN 10010
#define MAXK 10010
#define MAXM 100100

using namespace std;

vector<int> GRAFO[MAXN];

void bfs(int start,int * dist)
{
    queue<int> pila;
    
    pila.push(start);
    dist[start] = 0;
    while (!pila.empty())
    {
        int att = pila.front();
        pila.pop();
        
        for (auto adj: GRAFO[att])
        {
            if (dist[adj] == -1)
            {
                dist[adj] = dist[att]+1;
                pila.push(adj);
            }
        }
    }
}

int dist_nonna[MAXN];
int dist_g[MAXN];

int compra(int N, int M, int K, int supermercati[], int da[], int a[]) {
    memset(dist_nonna, -1, sizeof(dist_nonna));
    memset(dist_g, -1, sizeof(dist_g));
    
    for (int i = 0; i < M; i++)
    {
        GRAFO[da[i]].push_back(a[i]);
        GRAFO[a[i]].push_back(da[i]);
    }
    
    bfs(1, dist_nonna);
    bfs(N,dist_g);
    
    int dist_min = 200000000;
    
    
    for (int i = 0; i < K; i++)
        dist_min =  min(dist_min, dist_nonna[supermercati[i]]+dist_g[supermercati[i]]);
        
    
    
    return dist_min;
}


int supermercati[MAXK], da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d%d%d", &N, &M, &K));
    for(i=0; i<K; i++)
        assert(1 == fscanf(fr, "%d", &supermercati[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));
    fprintf(fw, "%d\n", compra(N, M, K, supermercati, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
