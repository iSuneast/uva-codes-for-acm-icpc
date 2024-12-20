/*
628 - Passwords

recursion...
直接递归求解即可
*/

#include<iostream>
#define MAXN 110
#define MAXLEN 260
using namespace std;

int n,m,l,pos;
char dic[MAXN][MAXLEN],rule[MAXLEN],ans[MAXLEN];

void dfs(int cur)
{
	if(cur==l)
	{
		for(int i=0;i<l;++i)
			if(isdigit(rule[i]))
				printf("%d",ans[i]);
			else
				printf("%s",dic[pos]);
		putchar('\n');
		return ;
	}
	for(int i=cur;i<l;++i)
		if(isdigit(rule[i]))
		{
			for(int j=0;j<10;++j)
			{
				ans[i]=j;
				dfs(i+1);
			}
			return ;
		}
	dfs(l);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		puts("--");
		for(int i=0;i<n;++i)
			scanf("%s",dic[i]);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",rule);
			l=strlen(rule);
			for(pos=0;pos<n;++pos)
				dfs(0);
		}
	}

	return 0;
}
