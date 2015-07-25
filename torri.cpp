#include <iostream>
#include <fstream>


using namespace std;
typedef pair<int,int> pi;

#define MAXN 1010

pi torri[MAXN];
int dp[MAXN];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    scanf("%d",&N);

    int somma_costi = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &torri[i].first,&torri[i].second);
        somma_costi+= torri[i].second;
        dp[i] = torri[i].second;
    }

    for (int i = 0; i < N; i++)
        for (int j = i-1; j >=0; j--)
            if (torri[j].first > torri[i].first)
                dp[i] = max(dp[i], torri[i].second+dp[j]);

    int massimo = 0;
    for (int i = 0; i < N; i++)
        massimo = max(massimo,dp[i]);

        //cerr<<somma_costi-massimo;
    cout<<somma_costi-massimo;

    return 0;
}
