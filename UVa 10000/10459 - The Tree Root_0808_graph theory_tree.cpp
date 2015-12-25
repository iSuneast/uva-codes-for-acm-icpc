/*
10459 - The Tree Root

graph theory...
diameter of tree...
求点u集合,使得以u为树根的树高度最大(小)...
从任意点开始bfs,找到一个离根最远的点(这点必属于树直径的端点)
从这个点开始,bfs,将找到的离他最远的点全部加入worst集合,保存dis1
从worst集合的点开始bfs,将dis最大的点标记为worst集合,不要对这些点bfs,保存dis2

易知,使树高最小的点必为树的直径的中点...
所以枚举u,使得u同时是dis1，dis2的中点(奇偶情况不同)
*/

#include<iostream>
#include<vector>
#define MAXN 5003
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN<<1];
int tot;

int dis[MAXN],dis2[MAXN],n;

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void graph_init()
{
	tot=0;
	memset(edge,0,sizeof(edge));
}

int q[MAXN],key[MAXN],_max;

void bfs(int u,bool does)
{
#define PUSH(s)	{q[rear++]=s;}

	int front=0,rear=0;
	memset(dis,0x3f,sizeof(dis));
	PUSH(u);	dis[u]=0;

	while(front<rear)
	{
		u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]==INF)
			{
				dis[cur->v]=dis[u]+1;
				if(does && dis[cur->v]==_max)
					key[cur->v]=-1;
				PUSH(cur->v);
			}
	}
}

int get_max()
{
	int _max=0;
	for(int i=1;i<=n;++i)
		_max=max(_max,dis[i]);
	return _max;
}

void process()
{
	vector<int> worst;
	memset(key,0,sizeof(key));

	bfs(1,false);
	_max=get_max();

	for(int i=1;i<=n;++i)
		if(_max==dis[i])
		{
			worst.push_back(i);
			break;
		}

		bfs(worst[0],false);
		memcpy(dis2,dis,sizeof(dis));
		_max=get_max();

		worst.clear();
		for(int i=1;i<=n;++i)
			if(dis[i]==_max)
				worst.push_back(i);

		int a,b;
		if(_max&1)
			a=_max/2,b=a+1;
		else
			a=b=_max/2;

		bool first=true;
		int sz=worst.size();
		for(int i=0;i<sz;++i)
		{
			bfs(worst[i],true);
			if(first)
			{
				for(int i=1;i<=n;++i)
					if((dis[i]==a || dis[i]==b) && (dis2[i]==a || dis2[i]==b))
						key[i]=1;
			}
			first=false;
			key[ worst[i] ]=-1;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		int cnt,v;
		graph_init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&cnt);
			while(cnt--)
			{
				scanf("%d",&v);
				link(i,v);
			}
		}

		process();

		printf("Best Roots  :");
		for(int i=1;i<=n;++i)
			if(key[i]>0)
				printf(" %d",i);
		putchar(10);

		printf("Worst Roots :");
		for(int i=1;i<=n;++i)
			if(key[i]<0)
				printf(" %d",i);
		putchar(10);
	}

	return 0;
}
