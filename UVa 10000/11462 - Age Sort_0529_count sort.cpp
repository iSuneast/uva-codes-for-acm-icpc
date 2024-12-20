/*
11462 - Age Sort

count sort...
计数排序...
*/

#include<iostream>
#define MAXN 100
using namespace std;

int key[MAXN+1];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,t;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(key,0,sizeof(key));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&t);
			key[t]++;
		}
		bool first=true;
		for(int i=1;i<=MAXN;++i)
			if(key[i])
				while(key[i]--)
				{
					if(!first)
						putchar(' ');
					first=false;
					printf("%d",i);
				}
		putchar('\n');
	}

	return 0;
}
