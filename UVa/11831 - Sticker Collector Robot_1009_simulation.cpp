/*
11831 - Sticker Collector Robot

simulation...
just do as the problem description..
*/

#include<iostream>
#define MAXN 103
using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m,s,dir,x,y;
char str[50003],g[MAXN][MAXN],h[128];

bool chk(int x,int y)
{
	return 0<x && x<=n && 0<y && y<=m &&
		g[x][y]!='#';
}

void simulation()
{
	int key=0;
	for(int i=0;str[i];++i)
	{
		if(str[i]=='F')
		{
			if(chk(x+dx[dir],y+dy[dir]))
			{
				x+=dx[dir];
				y+=dy[dir];
				if(g[x][y]=='*')
				{
					++key;
					g[x][y]='.';
				}
			}
		}
		else if(str[i]=='D')
			dir=(dir+1)%4;
		else
			dir=(dir+3)%4;
	}

	printf("%d\n",key);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	h['N']=0;	h['S']=2;	h['L']=1;	h['O']=3;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF && (n||m||s))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=m;++j)
				if(isalpha(g[i][j]))
				{
					x=i;
					y=j;
					dir=h[ g[i][j] ];
					g[i][j]='.';
				}
		}
		scanf("%s",str);
		simulation();
	}

	return 0;
}
