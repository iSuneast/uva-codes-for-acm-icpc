/*
11330 - Andy's Shoes

Ad hoc...
just exchange every illegal pair u found
the problem didn't say anything about the shoes identify
so for test case 
1
2 99 199 199 99
the correct answer is 1
*/

#include<iostream>
#define MAXN 10003
using namespace std;

int x[MAXN],y[MAXN],n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&u,&v);
			x[u]=v;
			y[v]=u;
		}

		int key=0;
		for(int i=1;i<MAXN;++i)
		{
			if(!x[i])
				continue;
			if(x[i]!=i)
			{
				++key;
				x[ y[i] ]=x[i];
				y[ x[i] ]=y[i];
				x[i]=y[i]=i;
			}
		}

		printf("%d\n",key);
	}

	return 0;
}
