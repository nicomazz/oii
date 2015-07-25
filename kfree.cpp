#include <set>

bool presenti[100001];

int Trova(int N, int K, int* insieme) 
{
    
if (K == 1) return 0;
	int nMax = 0;
	for (int i = 0; i < N; i++) 
	{
		presenti[insieme[i]] = true;
		if (insieme[i] > nMax) nMax = insieme[i];
	}
	int Ninsieme = 0; // n massimi

	int div, molt;
	for (int i = 0; i < N; i++)
	{	
		if (!presenti[insieme[i]])  continue;
		int att = 1;
		presenti[insieme[i]]= false;
		int div,molt;
		div =  insieme[i];
		molt = insieme[i]*K;

		while (div % K == 0)
		{
			div /= K;
			if (presenti[div]){ att++; presenti[div] = false;}
			else break;
		}
		while (molt < 100001 &&  presenti[molt])
		{
			presenti[molt] = false;
			att++;
			molt *= K;
			if (molt > nMax) break;
		}
		if (att % 2) Ninsieme+= (att+1)/2;
		else Ninsieme += att/2;
	}
	return Ninsieme;

}
