#include <iostream>
#include <fstream>

using namespace std;

int vini[1500];
int sol[1500];

int main()
{
    ifstream in("input.txt");
	ofstream out("output.txt");
    
	int n;
	in>>n;
    
	for (int i = 0; i < n; i++)
		in>>vini[i];
    
	sol[0] = sol[1] = 1;
    
	for (int i = 2; i < n; i++)
	{
   
        for (int j = i-2; j >= 0; j--)
        {
			if (vini[j] <= vini[i] && sol[j] > sol[i])
				sol[i] = sol[j];
        }
        
        sol[i]++;
    }
	
	int maxi = 0;
	for (int i = 0; i < n; i++)
		if (sol[i] > maxi) maxi = sol[i];
    
	out<<maxi;
}