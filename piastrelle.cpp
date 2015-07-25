#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int piastrelle[] = {1,2};


int n;

int messe[26];
int gMesse;

ofstream out("output.txt");

void print()
{
    for (int i = 0; i < gMesse; i++)
        if (messe[i] == 1) out<<"[O]";
        else out<<"[OOOO]";
    
    out<<endl;
}
bool solve(int N)
{
    int sum = 0;
    for (int i = 0; i < gMesse; i++) sum+=messe[i];
    
    if (sum == n) {print(); return false;}
    
    if (sum > n) return false ;
    
    for (int i = 0; i < 2; i++)
    {
        messe[gMesse] = piastrelle[i];
        gMesse++;
        
        if (!solve(N+piastrelle[i]))
        {
            gMesse--;
            return true;
        }
        
        gMesse--;
    }
    return true;
}

int main()
{
    ifstream in("input.txt");
    

	in>>n;
    
    solve(0);
    

}