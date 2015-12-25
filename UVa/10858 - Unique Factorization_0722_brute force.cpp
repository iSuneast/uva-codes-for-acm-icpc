/*
10858 - Unique Factorization

brute force...
暴力枚举所有因子,递归求解即可
由于因子是从小到大枚举
所以最后得到的序列一定保证字典序递增
*/

#include<iostream>
#define MAXN 23
using namespace std;

int n,tot,key[MAXN];

struct ANS
{
	int key[MAXN],sz;
}ans[10000];

void dfs(int n,int cur,int dep)
{
	if(n<=1)
		return ;

	for(int i=cur;i*i<=n;++i)
		if(n%i==0)
		{
			key[dep]=i;
			dfs(n/i,i,dep+1);
		}

	if(dep>=1)
	{
		key[dep]=n;
		ans[tot].sz=dep+1;
		for(int i=0;i<ans[tot].sz;++i)
			ans[tot].key[i]=key[i];
		++tot;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		tot=0;
		dfs(n,2,0);
		printf("%d\n",tot);
		for(int i=0;i<tot;++i)
		{
			printf("%d",ans[i].key[0]);
			for(int j=1;j<ans[i].sz;++j)
				printf(" %d",ans[i].key[j]);
			putchar('\n');
		}
	}

	return 0;
}
