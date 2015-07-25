
#include <set>
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo
{
    int da,a,h;
    
    nodo(int D, int A, int alt)
    {da = D;a = A; h = alt;}
    
    bool operator<(const nodo& n)const
    {
        return h<n.h;
    }
};

typedef pair<long long,int> ii;
vector<ii> cammino; // livello, numero di barili
list<nodo> grafo[1000001];
long long altTemp[1000001];
bool altezza_visitata[1000001];
int mancanti;
long long risp= 0;

void inserisci(nodo daInserire, long long risposta[])
{
    int cnt = 0;
    
    vector<ii> newVect;
    int siz = (int)cammino.size();
    int h = daInserire.h;
    long long altAtt;
    for (int i = 0; i < siz; i++)
    {
        altAtt = cammino[i].first;
        if (altAtt < h)
        {
            risp += (h-altAtt)*cammino[i].second;
            cnt+=cammino[i].second;
        }
        else newVect.push_back(ii(altAtt, cammino[i].second));
    }
    newVect.push_back(ii(h,cnt));
    risposta[daInserire.a] = risp;
    
    cammino = newVect;
}
void risolvi(int N, int M, int A[], int B[], int H[], long long risposta[])
{
	for (int i = 0; i < M; i++)
    {
        grafo[A[i]].push_back(nodo(A[i],B[i],H[i]));
        grafo[B[i]].push_back(nodo(B[i],A[i],H[i]));
    }
    
    
    set<nodo> attuali; // collegamenti  attualmente in considerazione
    mancanti = N-1;
    
    cammino.push_back(ii(0,1));

    for (list<nodo>::iterator it = grafo[1].begin(); it != grafo[1].end(); it++)
    {
        attuali.insert(*it);
        altezza_visitata[it->h] = true;
    }
    
    while (mancanti)
    {
        nodo piu_vicino = *attuali.begin(); // il prossimo a straripare
        attuali.erase(attuali.begin());
        
        if (risposta[piu_vicino.a]) continue; // esiste già risposta
        
        inserisci(piu_vicino, risposta);
        mancanti--;
        cammino.push_back(ii(0,1));

        list<nodo>::iterator fine = grafo[piu_vicino.a].end();
        for (list<nodo>::iterator it = grafo[piu_vicino.a].begin(); it != fine; it++)
            if (!altezza_visitata[it->h])
            {
                attuali.insert(*it);
                altezza_visitata[it->h] = true;
            }
        
    }
    risposta[1] = 0;
    
    
}

/*


 long long risposta[10000000];
 
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    in>>N>>M;
    
    int A[M], B[M], H[M];
    
    int i;
    for (i = 0; i < M; i++) {
        in>>A[i]>>B[i]>>H[i];
    }
    risolvi(N, M, A, B, H, risposta);
    
    for(i = 1; i <= N; i++) {
        cout<<risposta[i]<<" ";
    }
    return 0;
}
*/