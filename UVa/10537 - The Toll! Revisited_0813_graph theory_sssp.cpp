/*
10537 - The Toll! Revisited

graph theory...
sssp..
从终点开始求sssp...
u->v的边权为ceil(dis[u]*20/19.0)
dis要开成long long并且小心计算过程的溢出...
输出方案要求字典序最小...
dfs找最小的符合条件的点即可
*/

#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 128
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

struct EDGE
{
	char v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];
int n,tot,d,snk;

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

long long dis[MAXN];
bool inq[MAXN];

void spfa(int src)
{
#define PUSH(s)	{if(!inq[s]) {q.push(s)	;inq[s]=true;}}
#define POP()	{inq[q.front()]=false;	q.pop();}

	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(src);	dis[src]=d;
	while(!q.empty())
	{
		int u=q.front();	POP();
		long long t;
		if(isupper(u))
			t=(long long)ceil(dis[u]*20/19.0);
		else
			t=dis[u]+1;

		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]>t)
			{
				dis[cur->v]=t;
				PUSH(cur->v);
			}
	}
}

void dfs(int u)
{
	if(u==snk)
		return ;
	printf("%c-",u);
	int v=128;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(isupper(cur->v))
		{
			if(dis[u]-((long long)ceil(dis[u]/20.0))==dis[cur->v])
				v=min(v,cur->v);
		}
		else if(dis[cur->v]+1==dis[u])
			v=min(v,cur->v);
	if(v!=128)
		dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	char u[3],v[3];
	while(scanf("%d",&n)!=EOF && n>=0)
	{
		graph_init();
		for(int i=0;i<n;++i)
		{
			scanf("%s%s",u,v);
			link(u[0],v[0]);
			link(v[0],u[0]);
		}
		scanf("%d%s%s",&d,u,v);
		spfa(v[0]);
		printf("Case %d:\n",cas++);
		printf("%lld\n",dis[u[0]]);
		snk=v[0];	dfs(u[0]);
		printf("%c\n",v[0]);
	}

	return 0;
}
