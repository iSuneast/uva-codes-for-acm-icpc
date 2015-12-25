/*
11418 - Clever Naming Patterns

graph theory...
hungry...
二分图最大匹配...
*/

#include<iostream>
#include<string>
#define MAXN 33
using namespace std;

int n,m;
string dic[MAXN][MAXN],s;
bool g[MAXN][MAXN];
int match[MAXN];
bool flag[MAXN];

int dfs(int u)
{
	for(int v=0;v<n;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			int t=match[v];
			match[v]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[v]=t;
		}
	return 0;
}

int hungry()
{
	memset(match,-1,sizeof(match));
	int key=0;
	for(int i=0;i<n;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key;
}

void output(string key)
{
	int l=key.length();
	putchar(toupper(key[0]));
	for(int i=1;i<l;++i)
		putchar(tolower(key[i]));
	putchar(10);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		m=0;
		int sz;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&sz);
			while(sz--)
			{
				cin>>s;
				int u=toupper(s[0])-'A';
				dic[i][u]=s;
				g[i][u]=true;
			}
		}

		printf("Case #%d:\n",cas);
		hungry();
		for(int i=0;i<n;++i)
			output(dic[ match[i] ][i]);
	}

	return 0;
}
