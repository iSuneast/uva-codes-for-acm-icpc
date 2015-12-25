/*
11340 - Newspaper

strings...
simple...
UVa的水题也是tricky滋生的圣地...
*/

#include<iostream>
#define MAXN 10010
using namespace std;

char s[MAXN],c,*p;
int hash[256],k,m,v;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("acm.txt","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(hash,0,sizeof(hash));
		scanf("%d",&k);
		while(k--)
		{
			scanf("%*c%c%d",&c,&v);
			hash[c+128]=v;		//字符可能是负的?
		}
		scanf("%d",&m);gets(s);
		unsigned long long key=0;		//估计是这里的问题
		while(m--)
		{
			gets(s);
			p=s;
			while(*p)
			{
				key+=hash[*p+128];
				++p;
			}
		}
		printf("%.2lf$\n",key/100.0);
	}

	return 0;
}
