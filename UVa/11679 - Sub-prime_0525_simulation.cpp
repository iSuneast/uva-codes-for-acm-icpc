/*
11679 - Sub-prime

simulation...
直接模拟即可...
不要想得太复杂...
*/

#include<iostream>
#define MAXN 25
using namespace std;

int bank[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int b,n;
	while(scanf("%d%d",&b,&n)!=EOF && (b||n))
	{
		int d,c,v;
		for(int i=1;i<=b;++i)
			scanf("%d",bank+i);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&d,&c,&v);
			bank[d]-=v;
			bank[c]+=v;
		}
		bool chk=true;
		for(int i=1;i<=b && chk;++i)
			if(bank[i]<0)
				chk=false;
		if(chk)
			puts("S");
		else
			puts("N");
	}

	return 0;
}
