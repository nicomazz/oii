#include <stdio.h>
#include <assert.h>
#include <list>
#include <stack>

#define foreach(i,c) for (typeof(c.begin()) it = c.begin();it != c.end(); it++)

#define MAXM 100001

using namespace std;

bool visitate[MAXM];
list<int> grafo[MAXM];

int componenti;
void visita(int nodo)
{
    if (visitate[nodo]) return;
    else componenti++;

    stack<int> s;

    s.push(nodo);
    visitate[nodo] = true;

    while (!s.empty())
    {
        int att = s.top();
        s.pop();
        for (list<int>::iterator it = grafo[att].begin();it != grafo[att].end(); it++)

        {
            if (!visitate[*it])
            {
                s.push(*it);
                visitate[*it] = true;

            }
        }
    }

}
int costruisci(int N, int M, int da[], int a[]) {

    //costruzione grafo
    for (int i = 0; i < M; i++)
    {
        grafo[a[i]].push_back(da[i]);
        grafo[da[i]].push_back(a[i]);
    }

    if (M == 0) return N-1;


    for (int i = 0 ; i < N; i++)
        visita(i);

    return componenti-1;

    /*int PontiDaFare = 0;
    for (int i = 0; i < N; i++)
        if (visitate[i] == false) PontiDaFare++;
*/

   // return PontiDaFare;
}


int da[MAXM], a[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &da[i], &a[i]));

    fprintf(fw, "%d\n", costruisci(N, M, da, a));
    fclose(fr);
    fclose(fw);
    return 0;
}
