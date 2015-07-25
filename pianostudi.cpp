#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

#define MAXN 100001
#define MAXG 10000001

using namespace std;

typedef pair<int,int> pii; //fino a, massimo
typedef unsigned long long ull;

ull dp[MAXG];
ull maggiore[MAXG];

struct credito
{
    int iniz, fine, soldi;
    credito(int _iniz, int _fine, int _soldi){ iniz = _iniz; fine = _fine; soldi =_soldi;}

    bool operator< (const credito & b)const
    {
        return fine < b.fine;
    }
};
vector<credito> v;


int pianifica(int N, int da[], int a[], int crediti[]) {

    for (int i = 0; i < N; i++)
       v.push_back( credito(da[i],a[i],crediti[i]));

   sort(v.begin(), v.end());

   for (int i = 0; i < N; i++)
   {
       ull massimo = 0;
       int da = v[i].iniz-1;
       while (maggiore[da] == 0 && da > 0) da--;
       massimo = maggiore[da];

       for (int j = da; j <= v[i].iniz-1; j++)
           massimo =  max( massimo, dp[j]);

        maggiore[v[i].iniz-1] = massimo;


        dp[v[i].fine] = max(dp[v[i].fine], massimo+v[i].soldi);
   }

    ull massimo = 0;
   // for (int i = 0; i < 11; i++)
    // cout<<dp[i]<<" ";


    for (int i = 0; i < MAXG; i++)
    {
        massimo = max(massimo,dp[i]);
    }
    return massimo;
}


int da[MAXN], a[MAXN], crediti[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &crediti[i]));

    fprintf(fw, "%d\n", pianifica(N, da, a, crediti));
    fclose(fr);
    fclose(fw);
    return 0;
}
