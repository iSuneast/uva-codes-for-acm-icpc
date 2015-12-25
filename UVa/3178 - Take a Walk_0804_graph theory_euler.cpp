/*
3178 - Take a Walk

graph theory...
euler...
判断图是否存在欧拉回路欧拉通路...
先判连通...
输入比较麻烦....
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 128
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

bool g[MAXN][MAXN],flag[MAXN],vis[MAXN];
char c,buf[MAXN*MAXN];
int d[MAXN];

bool input()
{
	while((c=getchar()) && c!='{' && c!=EOF) ;

	memset(flag,0,sizeof(flag));
	while((c=getchar()) && c!='}' && c!=EOF)
		if(isalpha(c))
			flag[c]=true;

	while((c=getchar()) && c!='{' && c!=EOF) ;

	memset(g,0,sizeof(g));
	memset(d,0,sizeof(d));

	while((c=getchar()) && c!='}' && c!=EOF)
		if(isalpha(c))
		{
			char t=c;
			while((c=getchar()) && !isalpha(c) && c!=EOF) ;
			g[t][c]=g[c][t]=true;
			++d[t],++d[c];
		}

		return c!=EOF;
}

void dfs(int u)
{
	vis[u]=true;
	for(int i=0;i<MAXN;++i)
		if(g[u][i] && !vis[i])
			dfs(i);
}

void chk()
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<MAXN;++i)
		if(flag[i])
		{
			dfs(i);
			for(int j=i;j<MAXN;++j)
				if(flag[j] && !vis[j])
				{
					puts("No No");
					return ;
				}
		}

		int odd=0;
		for(int i=0;i<MAXN;++i)
			if(d[i]&1)
				++odd;

		if(!odd)
			puts("No Yes");
		else if(odd==2)
			puts("Yes No");
		else
			puts("No No");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(input())
		chk();

	return 0;
}
