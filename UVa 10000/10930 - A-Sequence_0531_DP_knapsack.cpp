/*
10930 - A-Sequence

DP...
knapsack...

序列首先要满足1<=a1<a2<...<an<=1000
然后对前n项和背包即可.
*/

#include<iostream>
#define MAXN 35
#define BOUND 1000
using namespace std;

int var[MAXN],n,hash[BOUND+3];

bool chk()
{
	memset(hash,0,sizeof(hash));
	hash[0]=1;
	for(int i=0;i<n;++i)
		if(!(!i && var[i]>=1 || i && var[i]>var[i-1]))
			return false;
	if(var[n-1]>BOUND)
		return false;
	for(int i=0;i<n;++i)
	{
		if(hash[ var[i] ])
			return false;
		for(int j=BOUND;j>=0;--j)
			if(hash[j] && j+var[i]<=BOUND)
				hash[j+var[i]]=true;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d:",cas++);
		for(int i=0;i<n;++i)
		{
			scanf("%d",var+i);
			printf(" %d",var[i]);
		}
		putchar('\n');
		if(chk())
			puts("This is an A-sequence.");
		else
			puts("This is not an A-sequence.");
	}

	return 0;
}
