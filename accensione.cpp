void Accendi(int N, int acceso[], int pulsante[])
{
    int tmp;
    for ( int i = N; i>0; i--)
	{
        tmp = acceso[i];
		for (int j = i*2; j <= N; j+=i) {
            if (pulsante[j])
                tmp^=1; // complementa
        }
        if (!tmp)
            pulsante[i] = 1;
	}
}
