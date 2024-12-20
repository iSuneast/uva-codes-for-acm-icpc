/*
155 - All Squares

math..
递归定义的东西...
于是用dfs就可以了...
*/

#include<iostream>
using namespace std;

short key,px,py;

void dfs(int x,int y,int k)
{
	if(!k)
		return ;
	if(x-k<=px && px<=x+k && y-k<=py && py<=y+k)
		++key;
	dfs(x-k,y-k,k>>1);
	dfs(x+k,y-k,k>>1);
	dfs(x-k,y+k,k>>1);
	dfs(x+k,y+k,k>>1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int k;
	while(scanf("%d%d%d",&k,&px,&py)!=EOF && (k||px||py))
	{
		key=0;
		dfs(1024,1024,k);
		printf("%3d\n",key);
	}

	return 0;
}
