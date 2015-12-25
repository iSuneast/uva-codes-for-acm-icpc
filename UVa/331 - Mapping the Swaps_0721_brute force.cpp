/*
331 - Mapping the Swaps

brute force...
这题的规模实在是太小太小了....
害得我都不知道怎么暴力了...

直接枚举交换的数对
回溯即可..
*/

#include<iostream>
#define MAXN 8
#define INF 0x3f3f3f3f
using namespace std;

int cnt,d;
int n,var[MAXN];

void dfs(int dep)
{
	bool done=false;
	for(int i=1;i<n;++i)
		if(var[i]<var[i-1])
		{
			swap(var[i],var[i-1]);
			dfs(dep+1);
			swap(var[i],var[i-1]);
			done=true;
		}
	if(!done && dep)
	{
		if(dep<d)
		{
			d=dep;
			cnt=1;
		}
		else if(dep==d)
			++cnt;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);
		d=INF;	cnt=0;
		dfs(0);
		printf("There are %d swap maps for input data set %d.\n",cnt,cas++);
	}

	return 0;
}
