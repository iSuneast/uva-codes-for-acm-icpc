/*
10821 - Constructing BST

greedy...
data struct...
dfs...
use dfs to build the tree
every step if we can build the legal tree use node small we will take it
*
* has height of at most H
*
*/

#include<iostream>
using namespace std;

int log2(int var)
{
	int key=1,ans=0;
	for(;key<=var;key<<=1,++ans) ;
	return ans;
}

void dfs(int s,int e,int h)
{
	if(s>e || h<0)
		return ;
	int tot=e-s+1;
	for(int d=tot-1;d>=0;--d)
	{
		if(log2(d)<=h)
		{
			printf(" %d",e-d);
			dfs(s,e-d-1,h-1);
			dfs(e-d+1,e,h-1);
			return ;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1,n,h;
	while(scanf("%d%d",&n,&h)!=EOF && (n||h))
	{
		printf("Case %d:",cas++);

		if(h<log2(n))
			printf(" Impossible.");
		else
			dfs(1,n,h-1);
		putchar(10);
	}

	return 0;
}
