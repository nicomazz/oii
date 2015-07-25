
#include <iostream>
#include <fstream>

using namespace std;

typedef long long  ll;


int main()
{
    
    ios_base::sync_with_stdio(false);
    
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    ll n;  in>>n;
    
    ll n1,n2,sum = 0,maxn = -1;
    for (ll i = 0; i < n; i++)
    {
        in>>n1>>n2;
	sum = n1+n2;
	if (sum%2 == 0 && maxn < sum) maxn = sum;
    }
    
    out<<maxn;
    
    return 0;
}

