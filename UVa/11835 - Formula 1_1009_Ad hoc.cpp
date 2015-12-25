/*
11835 - Formula 1

Ad hoc...
just simulation...
No trick...
*/

#include<iostream>
#define MAXN 103
using namespace std;
int data[MAXN][MAXN];
int g,p,s,k,scr[MAXN],f[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&g,&p)!=EOF && (g||p))
	{
		for(int i=1;i<=g;++i)
		{
			for(int j=1;j<=p;++j)
				scanf("%d",&data[i][j]);
		}

		scanf("%d",&s);
		while(s--)
		{
			scanf("%d",&k);
			memset(f,0,sizeof(f));
			memset(scr,0,sizeof(scr));
			for(int i=1;i<=k;++i)
			{
				scanf("%d",&scr[i]);
			}

			for(int i=1;i<=g;++i)
			{
				for(int j=1;j<=p;++j)
				{
					f[j]+=scr[ data[i][j] ];
				}
			}

			int key=0;
			for(int i=1;i<=p;++i)
				key=max(key,f[i]);

			bool first=true;
			for(int i=1;i<=p;++i)
			{
				if(f[i]==key)
				{
					if(!first)
						putchar(' ');
					first=false;
					printf("%d",i);
				}
			}
			putchar(10);
		}
	}

	return 0;
}
