int ContaOperazioni(int N,int K, int* secchi){
	long long a = 0,b=0;
    for (int i = 0; i < N; i++)
    {
        if (secchi[i] < K)
        {
            a+= K-secchi[i];
            b+= K-secchi[i];
        }
        else
        {
            b-= secchi[i]-K;
        }
    }
    
    long long ris = a;
    if (b<0) ris-=b;
	return ris;
}