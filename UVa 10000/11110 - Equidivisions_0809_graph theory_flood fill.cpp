/*
11110 - Equidivisions

graph theory...
flood fill...
�������...
��Ŀ����,ֻ��˵���ݱȽ�bt����...
��Ŀû˵һ����n������...
����Ҫ���ַ�������...
Ȼ����Ǽ򵥵�dfs��һ����ͨ����ͬ���ָ����Ϳ�����..
*/

#include<iostream>
#define MAXN 103
using namespace std;

int n,g[MAXN][MAXN],fa[MAXN],cnt;
char buf[MAXN*MAXN];

void input()
{
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			g[i][j]=1;
	gets(buf);

	for(int i=2;i<=n;++i)
	{
		gets(buf);

		int u,v;
		char *token=strtok(buf," ");
		while(token)
		{
			sscanf(token,"%d",&u);
			token=strtok(NULL," ");
			if(!token)
				break;
			sscanf(token,"%d",&v);
			g[u][v]=i;
			token=strtok(NULL," ");
		}
	}
}

void dfs(int x,int y,int v)
{
	if(g[x][y]!=v)
		return ;
	++cnt;
	g[x][y]=0;
	dfs(x+1,y,v);	dfs(x,y+1,v);
	dfs(x-1,y,v);	dfs(x,y-1,v);
}

bool chk()
{
	int key=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(g[i][j])
			{
				cnt=0;
				dfs(i,j,g[i][j]);
				if(cnt!=n)
					return false;
				++key;
			}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		input();
		puts(chk()?"good":"wrong");
	}

	return 0;
}
