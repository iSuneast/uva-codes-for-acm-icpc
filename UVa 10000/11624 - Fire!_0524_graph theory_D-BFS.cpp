/*
11624 - Fire!

graph theory
D-BFS...
不知道算不算双向BFS...
反正是要有两个BFS同时进行...
而且每次是扩展整层BFS树,不仅仅是一个叶子节点
*/

#include<iostream>
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;

char g[MAXN][MAXN];
int r,c,jx,jy,fx,fy,dis[MAXN][MAXN];
pii jq[MAXN*MAXN],fq[MAXN*MAXN];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int hash(int x,int y)
{
	return x*MAXN+y;
}

int bound()
{
	int key=INF;
	for(int i=1;i<=c;++i)
	{
		if(dis[1][i]!=-1)
			key=min(key,dis[1][i]+1);
		if(dis[r][i]!=-1)
			key=min(key,dis[r][i]+1);
	}
	for(int i=1;i<=r;++i)
	{
		if(dis[i][1]!=-1)
			key=min(key,dis[i][1]+1);
		if(dis[i][c]!=-1)
			key=min(key,dis[i][c]+1);
	}
	return key;
}

int bfs()
{
	memset(dis,-1,sizeof(dis));
	int jfront=0,jrear=0,ffront=0,frear=0,dep=0;

	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
		{
			if(g[i][j]=='J')
			{
				dis[i][j]=0;
				jq[jrear++]=make_pair(hash(i,j),dep);
			}
			else if(g[i][j]=='F')	//可能有多个地方同时着火了...
				fq[frear++]=make_pair(hash(i,j),dep);
		}

	while(true)
	{
		bool bk=true;
		while(jfront<jrear)
		{
			pii cur=jq[jfront++];
			if(cur.second!=dep)
			{
				--jfront;
				break;
			}
			jx=cur.first/MAXN,jy=cur.first%MAXN;
			if(g[jx][jy]=='#')
			{
				dis[jx][jy]=-1;
				continue;
			}
			for(int d=0;d<4;++d)
			{
				int tx=jx+dx[d];
				int ty=jy+dy[d];
				if(g[tx][ty]=='.' && dis[tx][ty]==-1)
				{
					dis[tx][ty]=dis[jx][jy]+1;
					jq[jrear++]=make_pair(hash(tx,ty),dep+1);
					bk=false;
				}
			}
		}
		while(ffront<frear)
		{
			pii cur=fq[ffront++];
			if(cur.second!=dep)
			{
				--ffront;
				break;
			}
			fx=cur.first/MAXN,fy=cur.first%MAXN;
			for(int d=0;d<4;++d)
			{
				int tx=fx+dx[d];
				int ty=fy+dy[d];
				if(g[tx][ty]!='#' && g[tx][ty])
				{
					g[tx][ty]='#';
					fq[frear++]=make_pair(hash(tx,ty),dep+1);
				}
			}
		}
		dep++;
		if(bk)
			return bound();
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
		memset(g,0,sizeof(g));
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;++i)
			scanf("%s",g[i]+1);
		int key=bfs();
		if(key==INF)
			puts("IMPOSSIBLE");
		else
			printf("%d\n",key);
	}

	return 0;
}
