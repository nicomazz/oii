#include <iostream>
#include <stdio.h>
using namespace std;

int way[1<<15 +1];


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for (int a = 0; a*a<= 1<<15; a++)
        for (int b = a; a*a+b*b<=1<<15; b++)
        for (int c = b; c*c+b*b+a*a<= 1<<15; c++)
        for (int d = c; a*a+b*b+c*c+d*d <= 1<<15; d++)
            way[a*a+b*b+c*c+d*d]++;
    int n;
    cin>>n;
    while (n--)
    {
        int t; cin>>t;
        cout<<way[t]<<" ";
    }

            return 0;
}
