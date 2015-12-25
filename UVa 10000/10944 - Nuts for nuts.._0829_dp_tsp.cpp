/*
10944 - Nuts for nuts..

dp..
tsp...
1.There will be at most 15 places where there are nuts
2.starting from "L", gather all the nuts, and back to "L".
so it's just a hamilton tsp problem...
use bfs to pre_get the dis between any pair of nodes
then bitmask dp will do.
*/

#include<iostream>
#include<queue>
#define MAXN 23
#define NUT 17
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;

int dp[NUT][1<<NUT],dis[NUT][NUT],d[MAXN][MAXN],x,y,sz;
char g[MAXN][MAXN];
vector<pii> node;

int hamilton()
{
#define INSIDE(a,b) (a&(1<<b))
#define MERGE(a,b) (a+(1<<b))

	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<sz;++i)
		dp[i][1<<i]=dis[0][i];

	for(int i=1;i<(1<<sz);++i)
		for(int j=0;j<sz;++j)
			if(INSIDE(i,j))
				for(int k=0;k<sz;++k)
					if(!INSIDE(i,k))
						dp[k][MERGE(i,k)]=
						min(dp[k][MERGE(i,k)],dp[j][i]+dis[j][k]);

	return dp[0][(1<<sz)-1];
}

const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

void bfs(pii cur)
{
	queue<pii> q;
	q.push(cur);
	memset(d,0x3f,sizeof(d));
	d[ cur.first ][ cur.second ]=0;
	while(!q.empty())
	{
		cur=q.front();	q.pop();
		for(int i=0;i<8;++i)
		{
			int tx=cur.first+dx[i];
			int ty=cur.second+dy[i];
			if(g[tx][ty] && d[tx][ty]==INF)
			{
				d[tx][ty]=d[cur.first][cur.second]+1;
				q.push( make_pair(tx,ty) );
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&x,&y)!=EOF)
	{
		memset(g,0,sizeof(g));
		node.clear();
		for(int i=1;i<=x;++i)
		{
			scanf("%s",g[i]+1);
			for(int j=1;j<=y;++j)
				if(g[i][j]!='.')
					node.push_back( make_pair(i,j) );
		}

		memset(dis,0x3f,sizeof(dis));
		sz=node.size();
		for(int i=0;i<sz;++i)
		{
			bfs(node[i]);
			for(int j=0;j<sz;++j)
				dis[i][j]=d[ node[j].first ][ node[j].second ];
		}

		printf("%d\n",hamilton());
	}

	return 0;
}
