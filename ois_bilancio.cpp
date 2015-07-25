#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include "math.h"

#define MAXN 1000001

using namespace std;

inline void scanInt(int& x)
{
    char c = getchar_unlocked();
    x = 0;
    for(; (c<48)||(c>57);c = getchar_unlocked()); // finchè non trova un numero
    for(; (c>47)&&(c<58);c = getchar_unlocked()) x = (int)((((x)<<1) + ((x)<<3)) + c - 48);
}




int N;
int U[MAXN], C[MAXN];
bool tolti[MAXN+1];
vector<int> rmqV;

int generaRMQ(int nodo, int da, int a)
{
    if (da == a)
        return rmqV[nodo] = da;
    
    int sx = generaRMQ(nodo*2   , da          , (da+a)/2);
    int dx = generaRMQ(nodo*2+1 ,(da+a)/2 +1  , a);
    
    if (U[sx] == U[dx]) return rmqV[nodo] = min(sx,dx);
    return rmqV[nodo] = U[sx] < U[dx] ? sx:dx;
}
int query(int nodo,int l, int h, int da, int a)
{
    if (da > h || a < l) return -1; // non interseca
    if (l >= da && h <= a) return rmqV[nodo];
    
    int sx = query(nodo*2  , l, (l+h)/2, da, a);
    int dx = query(nodo*2+1, (l+h)/2+1, h, da, a);
    
    if (sx == -1) return dx;
    if (dx == -1) return sx;
    
    if (U[sx] == U[dx]) return min(sx,dx);

    return (U[sx] < U[dx]? sx:dx);
}
struct code
{
    int cifra,pos;
    
    code(int c,int p){cifra = c; pos = p;}
    code(){}
    bool operator<(const code &b)const
    {
        if (cifra == b.cifra) return pos > b.pos;
        return cifra < b.cifra;
    }
};
int minimoDaA(int da,int a)
{
     return query(1, 0, N-1, da, a);
}
priority_queue<code> maggiori;
void bianchetta(int N, int K, int U[], int C[]) {
    int ind= 0,start = 0, kRim = K, fino, i, indC = 0;
    
    if (K == 1){
        for ( i = 0; i < N; i++) maggiori.push(code(U[i],i));
        tolti[maggiori.top().pos] = true;
        ind = 0;
        for (i = 0; i < N; i++)if (tolti[i] == false)C[ind++] = U[i];
    }
    else
    {
        for (int t = 0; t < K; t++)
        {
            fino = start+kRim;
            ind =   minimoDaA(start, fino);
            
            C[indC++] = U[ind];
            
            kRim -= ind-start;
            start= ind+1;
        }
        
        if (ind != N)
            for (i = ind+1; i < N; i++)
                C[indC++] = U[i];
    }
     //  for (int i = 0; i < N-K; i++)
   // cout<<C[i]<<" ";
    
}



int main() {
        int  K, i;
    
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    scanInt(N);scanInt(K);
    for(i=0; i<N; i++)
        scanInt(U[i]);

    
    int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    rmqV.resize(length);
    generaRMQ(1,0,N-1);
 
   bianchetta(N, K, U, C);
    for(i=0; i<N-K; i++)
        printf("%d ", C[i]);
    printf( "\n" );
 
    return 0;
}
