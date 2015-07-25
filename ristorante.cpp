#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int costi[100001];
int N,D,M;

int main()
{
    ifstream in("input.txt");
	ofstream out("output.txt");
    
	in>>N>>D;
    
    for (int i = 0; i < N; i++)
        in>>costi[i];
    
    in>>M;

    long long sum = 0;
    
    if (M < N)
    {
        sort(costi, costi+N);
        for (int i = 0; i < M; i++)
            sum+=costi[i];
    }
    else
    {
        for (int i = 0; i<N; i++)
            sum+=costi[i];
        sum-= (M-N)*D;
    }
    out<<sum;
    return 0;
    
}