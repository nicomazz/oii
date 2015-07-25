//
//  main.cpp
//  viaggio
//
//  Created by nicomazz on 28/11/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define MAXN 100001
using namespace std;

struct arco
{
    int a,d;
    arco(int A,int b) { a = A; d = b;}
    bool operator<(const arco & b)const
    {
        return d > b.d;
    }
};


vector<arco> grafo[MAXN];
//vector< vector<arco> > mat;
priority_queue<arco> nodi;

int dist[MAXN];
bool v[MAXN];

 int a,b;
void visita()
{
    nodi.push(arco(1,0));
    
    while (!nodi.empty())
    {
        
        arco N = nodi.top();
        nodi.pop();
        if (v[N.a]) continue;
        
        //cout<<"considero: "<<N.a<<endl;

        v[N.a] = true;
        
        for (vector<arco>::iterator it = grafo[N.a].begin(); it != grafo[N.a].end(); it++)
      //  for (int i = 1; i <= a; i++)
        {
          //  if (mat[N.a][i] != INT_MAX){
                dist[it->a] = min(dist[it->a], dist[N.a]+it->d);
                if (!v[it->a]) nodi.push(arco(it->a, dist[it->a]));
          //  }
        }
    }
    cout<<dist[a];

}
int main()
{
    cin>>a>>b;
    /*for (int i = 0; i <= a; i++)
        for (int j = 0; j <= a; j++)
            mat[i][j] = INT_MAX;
    */
    int c,d,e,size;
    bool ins;
    for (int i = 0; i < b; i++)
    {
        cin>>c>>d>>e;
       // mat[c][d] = min(mat[c][d],e);
      //  mat[d][c] = min(mat[d][c],e);
      /*  size = (int)grafo[c].size();
        ins = false;
        for (int i = 0; i < size; i++)
            if (grafo[c][i].a == d)
                if (grafo[c][i].d > e)
                {
                    grafo[c][i] = arco(d,e);
                    ins = true;
                    break;
                }
        if (!ins)*/ grafo[c].push_back(arco(d,e));
        /*
        ins = false;
        size = (int)grafo[d].size();
        ins = false;
        for (int i = 0; i < size; i++)
            if (grafo[d][i].a == d)
                if (grafo[d][i].d > e)
                {
                    grafo[d][i] = arco(c,e);
                    ins = true;
                    break;
                }
        if (!ins)*/ grafo[d].push_back(arco(c,e));
        
       // grafo[d].push_back(arco(c,e));
    }
    for (int i = 2; i <= a; i++)
        dist[i] = INT_MAX;
  
    visita();
    
    //for (int i = 0; i<= a; i++)
      //  cout<<dist[i]<<" ";
    return 0;
}

