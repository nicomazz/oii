#include <stdio.h>
#include <assert.h>
#include <list>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

#define MAXM 100000

#define collegamenti first
#define collegato_a  second


list<int> grafo[MAXM];

int collegamenti[MAXM];
bitset<MAXM> eliminati;

bitset<MAXM> visitati;

int tolti = 0;
void visita(int n)
{
    if (visitati[n])return;

    queue<int> coda;
    
    coda.push(n);
    
    
    while (!coda.empty())
    {
        int att = coda.front();
        coda.pop();
        if (eliminati[att]) continue;

        
        if (collegamenti[att] < 1);
        else if (collegamenti[att] == 1)
        {
            eliminati[att] = true;
            
            tolti++;
            //  cout<<"diminuisco: "<<*(grafo[att].begin())<<endl;
            int da_diminuire = 0;
            for (list<int>::iterator it = grafo[att].begin(); it != grafo[att].end(); it++ )
                
                if (eliminati[*it] == false){ da_diminuire = *it;  break;}
            collegamenti[da_diminuire]--;
            collegamenti[att] = 0;
            
            coda.push(da_diminuire);
            visitati[da_diminuire] = false;

            //grafo[att].clear(); // togliamo tutti
        
        }
        
        else
            for (list<int>::iterator it = grafo[att].begin(); it != grafo[att].end(); it++ )
                if (!visitati[*it] && !eliminati[*it])
                    visitati[*it] = true, coda.push(*it);
    }
    return;
}
int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
    
    for (int i = 0; i < M; i++)
    {
        grafo[conoscenzeA[i]].push_back(conoscenzeB[i]);
        grafo[conoscenzeB[i]].push_back(conoscenzeA[i]);
        
        collegamenti[conoscenzeA[i]]++;
        collegamenti[conoscenzeB[i]]++;
    }
    
    for (int i = 0; i <N; i++)
    {
        visita(i);
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        // cout<<collegamenti[i]<<" ";
        if (collegamenti[i]) cnt++;
    }
    return cnt;
 
}


int conoscenzeA[MAXM], conoscenzeB[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &conoscenzeA[i], &conoscenzeB[i]));
    
    fprintf(fw, "%d\n", invita(N, M, conoscenzeA, conoscenzeB));
   // printf( "%d\n", invita(N, M, conoscenzeA, conoscenzeB));

    fclose(fr);
    fclose(fw);
    return 0;
}
