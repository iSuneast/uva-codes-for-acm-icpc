/*
11200 - Sapitaur's labyrinth

graph theory...
flood-fill...
久违的种子填充法...
直接dfs果然暴栈...
*/

#include<iostream>
#include<queue>
#define MAXN 1510
using namespace std;

bool g[MAXN][MAXN],got;
char s[MAXN];
int n,m;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void filled(int x,int y,bool slant)
{
	g[x][y]=true;
	if(slant)
		g[x-1][y-1]=g[x+1][y+1]=true;
	else
		g[x-1][y+1]=g[x+1][y-1]=true;
}

void bfs(int x,int y)
{
	queue<int> q;
	q.push(x*MAXN+y);
	g[x][y]=true;
	while(!q.empty())
	{
		int cur=q.front();	q.pop();
		x=cur/MAXN;	y=cur%MAXN;

		for(int d=0;d<4;++d)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(tx && tx<=3*m && ty && ty<=3*n && !g[tx][ty])
			{
				g[tx][ty]=true;
				q.push(tx*MAXN+ty);
				if(tx==3*m)
					got=true;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=n;++j)
				if(s[j]=='\\')
					filled(i*3-1,j*3-1,true);
				else
					filled(i*3-1,j*3-1,false);
		}

		int key=0;
		for(int i=1;i<=3*n;++i)
			if(!g[1][i])
			{
				got=false;
				bfs(1,i);
				if(got)
					++key;
			}

		printf("%d\n",key);
	}

	return 0;
}
