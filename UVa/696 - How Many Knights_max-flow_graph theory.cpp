/*
696 - How Many Knights

graph theory...
max-flow...

经典的二分图匹配模型
把每头马的位置(x,y)按x+y的奇偶弄成二分图两边的点
{不明白为什么这样的话,自己画出来就知道了}

由于图的点很多N*M,而边很少,所以可要用连接表存图,或者直接用网络流来求
可以放置马的个数是max( n*m-最大匹配, 最大匹配 )
{该结论同最小路径覆盖}

打表,找规律
规律自己找吧~说出来就没意思了
很简单的...

happy coding~
*/

#include<iostream>
#define MAXNODE 250003
#define MAXEDGE 3000000
using namespace std;
const int INF=0x3f3f3f3f;

int n,m;

struct MAX_FLOW
{
	struct EDGE
	{
		int v,cap;
		EDGE *rev,*next;
	}*edge[MAXNODE],data[MAXEDGE],*cur_edge[MAXNODE],*rev_edge[MAXNODE];
	int tot,node,src,snk;

	void graph_init()
	{
		src=0,snk=n*m+1,node=snk+1;
		tot=0;
		memset(edge,0,sizeof(edge));
	}

	void make_edge(EDGE *cur,int u,int v,int cap,EDGE *rev)
	{
		cur->v=v;	cur->cap=cap;
		cur->next=edge[u];	edge[u]=cur;	cur->rev=rev;
	}

	void link(int u,int v,int cap)
	{
		make_edge(&data[tot],u,v,cap,&data[tot+1]);
		make_edge(&data[tot+1],v,u,0,&data[tot]);
		tot+=2;
	}

	int q[MAXNODE],dis[MAXNODE],cnt[MAXNODE];

	void rev_bfs()
	{
#define PUSH(s) {q[rear++]=s;}
		int u=snk,front=0,rear=0;
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		PUSH(u);	dis[u]=0;	cnt[0]=1;
		while(front<rear)
		{
			u=q[front++];
			for(EDGE *cur=edge[u];cur;cur=cur->next)
				if(dis[cur->v]==INF)
				{
					dis[cur->v]=dis[u]+1;
					++cnt[ dis[cur->v] ];
					PUSH(cur->v);
				}
		}
	}

	int augment()
	{
		int flow=INF,u;

		for(u=src;u!=snk;u=cur_edge[u]->v)
			flow=min(flow,cur_edge[u]->cap);

		for(u=src;u!=snk;u=cur_edge[u]->v)
		{
			cur_edge[u]->cap-=flow;
			cur_edge[u]->rev->cap+=flow;
		}

		return flow;
	}

	int isap()
	{
		int flow=0,u=src;
		rev_bfs();
		memcpy(cur_edge,edge,sizeof(edge));

		while(dis[src]<node)
		{
			if(u==snk)
			{
				flow+=augment();
				u=src;
			}

			EDGE *cur=cur_edge[u];		//当前弧优化
			for(;cur;cur=cur->next)
				if(cur->cap && dis[u]==dis[cur->v]+1)
					break;

			if(cur)
			{
				cur_edge[u]=cur;
				rev_edge[cur->v]=cur->rev;
				u=cur->v;
			}
			else
			{
				if(!(--cnt[dis[u]]))		//GAP优化
					break;
				cur_edge[u]=edge[u];
				int dist=node;
				for(cur=edge[u];cur;cur=cur->next)
					if(cur->cap)
						dist=min(dist,dis[cur->v]);
				dis[u]=dist+1;
				++cnt[dis[u]];
				if(u!=src)
					u=rev_edge[u]->v;
			}
		}

		return flow;
	}
}final;

int h(int r,int c)
{
	return (r-1)*m+c;
}

const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,2,-2,1,-1};

void build()
{
	final.graph_init();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if((i+j)&1)
			{
				final.link(h(i,j), final.snk, 1);
				continue;
			}
			final.link(final.src, h(i,j), 1);
			for(int d=0;d<8;++d)
			{
				int tr=i+dx[d];
				int tc=j+dy[d];
				if(0<tr && tr<=n && 0<tc && tc<=m)
				{
					final.link(h(i,j), h(tr,tc), 1);
				}
			}
		}
	}

	int max_flow=final.isap();
	int key=max(max_flow, n*m-max_flow);
	printf("%d knights may be placed on a %d row %d column board.\n",key,n,m);
}

void print_table()
{
	for(int i=1;i<=100;++i)
	{
		for(int j=i;j<=100;++j)
		{
			n=i;
			m=j;
			build();
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int r,c,key;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		r=n,c=m;
		if(r>c)
			swap(r,c);

		if(r==1)
			key=c;
		else if(r==2)
		{
			if(c%4==1)
				key=c+1;
			else if(c%4)
				key=(c/4+1)*4;
			else
				key=c;
		}
		else
			key=(r*c+1)/2;

		printf("%d knights may be placed on a %d row %d column board.\n",key,n,m);
	}

	return 0;
}
