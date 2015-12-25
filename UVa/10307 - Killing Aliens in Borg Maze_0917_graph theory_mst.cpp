/*
10307 - Killing Aliens in Borg Maze

graph theory...
mst...
use bfs to initiate the distance array between any two alien || 'S'
use prim to solve the mst
*/

#include<iostream>
#include<queue>
#include<vector>
#define MAXN 53
#define ALIEN 103
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int dis[ALIEN][ALIEN],w[ALIEN][ALIEN],newPos[MAXN][MAXN],tot,n,m,s;
char g[MAXN][MAXN];
vector<pii> pos;

bool ok(int x,int y)
{
	return 0<x && x<=n
		&& 0<y && y<=m
		&& g[x][y]!='#';
}

void bfs(pii u,int dis[MAXN])
{
	memset(w,0x3f,sizeof(w));
	queue<pii> q;
	q.push(u);	w[ u.first ][ u.second ]=0;

	while(!q.empty())
	{
		u=q.front();	q.pop();
		int x=u.first,y=u.second;
		for(int d=0;d<4;++d)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(ok(tx,ty) && w[tx][ty]==INF)
			{
				w[tx][ty]=w[x][y]+1;
				q.push( make_pair(tx,ty) );
			}
		}
	}

	for(int i=0;i<tot;++i)
		dis[i]=w[ pos[i].first ][ pos[i].second ];
}

bool flag[ALIEN];

int prim(int s)
{
	int key=0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	memset(flag,0,sizeof(flag));
	pq.push(make_pair(0,s));

	while(!pq.empty())
	{
		pii cur=pq.top();	pq.pop();

		if(flag[ cur.second ])
			continue;
		key+=cur.first;
		flag[ cur.second ]=true;

		for(int i=0;i<tot;++i)
		{
			if(!flag[i])
				pq.push( make_pair(dis[cur.second][i],i) );
		}
	}

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%*c",&m,&n);

		pos.clear();
		tot=0;
		for(int i=1;i<=n;++i)
		{
			gets(g[i]+1);
			for(int j=1;j<=m;++j)
				if(isalpha(g[i][j]))
				{
					pos.push_back(make_pair(i,j));
					if(g[i][j]=='S')
						s=tot;
					newPos[i][j]=tot++;
				}
		}

		for(int i=0;i<tot;++i)
		{
			bfs(pos[i],dis[i]);
		}

		printf("%d\n",prim(s));
	}

	return 0;
}
