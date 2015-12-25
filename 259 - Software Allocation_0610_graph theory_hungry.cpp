/*
259 - Software Allocation

graph theory...
hungry...
*/

#include<iostream>
#define MAXN 50
using namespace std;

bool g[MAXN][MAXN],flag[MAXN];
char user[MAXN],buf[MAXN],match[MAXN];
int tot,ppln;

int dfs(int u)
{
	for(int v=0;v<tot;++v)
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

void hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<tot;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}

	if(key==ppln*2)
	{
		for(int i=0;i<10;++i)
			if(match[i]!=-1)
				putchar(user[ match[i] ]);
			else
				putchar('_');
		putchar('\n');
	}
	else
		puts("!");
}

void link(int s,int e,int u)
{
	while(s<e)
	{
		g[s][u]=g[u][s]=true;
		++s;
	}
}

bool input()
{
	memset(g,0,sizeof(g));
	tot=10;
	ppln=0;
	while(gets(buf) && buf[0])
	{
		int l=strlen(buf);
		int n=buf[1]-'0';
		ppln+=n;
		if(ppln<=10)
		{
			for(int i=tot;i<tot+n;++i)
				user[i]=buf[0];
			for(int j=3;j<l-1;++j)
				link(tot,tot+n,buf[j]-'0');
			tot+=n;
		}
	}
	if(ppln)
	{
		if(ppln<=10)
			hungry();
		else
			puts("!");
		return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(input())
		;

	return 0;
}
