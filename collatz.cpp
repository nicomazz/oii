#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>


#define REP(i,d,a) for (int i = (d); i < (a); i++)
#define FOREACH(i,C) for ( typeof( C.begin()) i = C.begin(); i != C.end(); i++)

using namespace std;

int volte;

void conta(int n)
{
    volte++;
    if (n == 1) return;
    if ( n % 2 == 0) conta(n/2);
    else if  (n%2) conta (n*3+1);


}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in>>N;

    conta(N);
    out<<volte;


    out.close();

    return 0;
}
