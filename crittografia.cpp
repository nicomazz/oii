#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int N,L;
char pass[200001];



int main()
{
    ifstream in("input.txt");
	ofstream out("output.txt");

    string str;
    
	in>>N>>L>>str;
    
    for (int i = 0; i < L; i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if (pass[str[i]-'0'] == 0 && ('0' > str[L-i-1] || str[L-i-1] > '9'))
                pass[str[i]-'0'] = str[L-i-1];
            else if (pass[str[i]-'0'] != str[L-i-1])
            {out<<"impossibile";return 0;}
        }
    }
    
    for (int i = 0; i < N;i++)
        if (pass[i] == 0)
        {
           out<<"impossibile";
            return 0;
        }
    for(int i = 0; i < N; i++)
        out<<pass[i];
    
    return 0;
    
}