/*
10851 - 2D Hieroglyphs decoder

Ad hoc...
just a ASCII binary code
use bit to recover it
*/

#include<iostream>
#define MAXN 86
using namespace std;

char g[13][MAXN],key[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(key,0,sizeof(key));
		for(int i=0;i<10;++i)
		{
			scanf("%s",g[i]);
			for(int j=1;g[i][j+1];++j)
			{
				if(g[i][j]=='\\')
					key[j-1]+=1<<(i-1);
			}
		}
		puts(key);
	}

	return 0;
}
