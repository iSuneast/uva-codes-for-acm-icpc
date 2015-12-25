/*
11813 - Shopping

graph theory...
sssp...
dp...
求哈密顿回路...
状态dp...
图比较大,用邻接表存

对所有的超市求apsp...
然后状态dp即可...
*/

#include<iostream>
#include<queue>
#define MAXN 100010
#define CITY 13
#define INF 0x3f3f3f3f
#define INSIDE(i,j) ((i)&(1<<(j)))
using namespace std;

struct GRAPH
{
	int v,w;
	GRAPH *next;
}*edge[MAXN],data[MAXN*10];
int n,m,tot,src[CITY],cnt;
int g[CITY][CITY],hash[MAXN];

void init()
{
	for(int i=0;i<n;++i)
		edge[i]=NULL;
	tot=0;
}

void insert(int u,int v,int w)
{
	data[tot].next=edge[u];
	data[tot].v=v;	data[tot].w=w;
	edge[u]=&data[tot++];
}

int dis[MAXN];
bool inq[MAXN];

void spfa(int p,int s)
{
#define PUSH(s) {if(!inq[s])q.push(s); inq[s]=true;}
#define POP()	{inq[q.front()]=false; q.pop();}

	memset(inq,0,sizeof(inq));
	queue<int> q;
	PUSH(s);
	memset(dis,0x3f,sizeof(dis));	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		GRAPH *cur=edge[u];
		while(cur)
		{
			int v=cur->v,w=cur->w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				PUSH(v);
			}
			cur=cur->next;
		}
	}
	for(int i=0;i<=cnt;++i)		//主算法没错,竟然是刚开始图映射错了...
		g[p][i]=g[i][p]=dis[ hash[i] ];
}

int state[CITY][1<<CITY];

void dp()
{
	memset(state,0x3f,sizeof(state));
	cnt++;

	for(int i=0;i<cnt;++i)
		state[i][1<<i]=g[0][i];

	for(int i=1;i<(1<<cnt);++i)
		for(int j=0;j<cnt;++j)
			if(INSIDE(i,j))
			{
				int cur=i-(1<<j);
				for(int k=0;k<cnt;++k)
					if(!INSIDE(i,k))
						state[k][i+(1<<k)]=
						min(state[k][i+(1<<k)],state[j][i]+g[k][j]);
			}

	printf("%d\n",state[0][(1<<cnt)-1]);
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
		init();

		int u,v,w;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			insert(u,v,w);
			insert(v,u,w);
		}

		scanf("%d",&cnt);
		src[0]=0;	hash[0]=0;
		for(int i=1;i<=cnt;++i)
		{
			scanf("%d",src+i);
			hash[i]=src[i];
		}

		for(int i=0;i<=cnt;++i)
			spfa(i,src[i]);

		dp();
	}

	return 0;
}
