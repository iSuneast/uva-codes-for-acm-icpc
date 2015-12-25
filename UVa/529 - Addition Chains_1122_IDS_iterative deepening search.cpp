/*
529 - Addition Chains

IDS...
iterative deepening search...

we can try to find the answer using IDS
pruning (key[dep]<<(Deepen-dep))<n
because we can always got a number a
 so that 2*a>=n
so before we approximating n, the current value should
value<<(Deepen-dep)>=n, if not 
we can find valueB to match this condition
and get a better answer
*/

#include<iostream>
#define MAXN 20
using namespace std;

int key[MAXN],depth,n;

bool dfs(int dep)
{
	if(dep==depth)
		return key[dep-1]==n;
	if(key[dep-1]<<(depth-dep)<n)
		return false;
	for(int i=0;i<dep;++i)
	{
		key[dep]=key[i]+key[dep-1];
		if(dfs(dep+1))
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	key[0]=1;	key[1]=2;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(n==1)
		{
			puts("1");
			continue;
		}

		depth=2;
		while(!dfs(2))
			++depth;

		for(int i=0;i+1<depth;++i)
			printf("%d ",key[i]);
		printf("%d\n",key[depth-1]);
	}

	return 0;
}
