/*
10912 - Simple Minded Hashing

brute force...
just brute force general every possible combination
and keep ++ our answer array
*/

#include<iostream>
using namespace std;

int key[30][355];

void dfs(int l,int s,int cur)
{
	++key[l][s];
	for(int i=cur;i<=26;++i)
		dfs(l+1,s+i,i+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(key,0,sizeof(key));
	dfs(0,0,1);
	int cas=1,l,s;
	while(scanf("%d%d",&l,&s)!=EOF && (l||s))
	{
		if(l>26 || (1+l)*l/2>s || s>351)
			printf("Case %d: %d\n",cas++,0);
		else
			printf("Case %d: %d\n",cas++,key[l][s]);
	}

	return 0;
}
