/*
11757 - Winger Trial

graph theory...
max-flow...
最大流模型...
thx very much to lct_3
令源点在上方,汇点在下方...
如果机器人可以到达边界则连接一条有向边
	源->机器人
	或者 机器人->汇
如果两个机器人间彼此可达,则连接一条无向边
但是我这么做wa了无数次...
发现题目说,最多只能被一个机器人抓住一次,
所以每个机器人只能走一次,必须吧机器人拆成两点才行
一个入点,一个出点,入点->出点流量为1
然后由最大流最小割定理得,最大流就是解
*/

#include<iostream>
#include<ctime>
#define MAXNODE 210
#define MAXEDGE 60000
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int ver,cap,flow;
	EDGE *next,*rev;
}data[MAXEDGE],*edge[MAXNODE],*curedge[MAXNODE],*revedge[MAXNODE];
int tot,src,snk,node;

struct POINT
{
	int x,y;
}pnt[MAXNODE];

int l,w,n,d;

int dist(POINT a,POINT b)
{
	int dx=a.x-b.x;
	int dy=a.y-b.y;
	return dx*dx+dy*dy;
}

int q[MAXNODE],dis[MAXNODE];
int cnt[MAXNODE];

void rev_bfs()
{
	int front=0,rear=0;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	q[rear++]=snk;
	dis[snk]=0;	cnt[0]=1;
	while(front<rear)
	{
		int u=q[front++];
		EDGE *cur=edge[u];
		while(cur!=NULL)
		{
			if(dis[cur->ver]==INF)
			{
				dis[cur->ver]=dis[u]+1;
				q[rear++]=cur->ver;
				++cnt[ dis[cur->ver] ];
			}
			cur=cur->next;
		}
	}
}

int agument()
{
	int flow=INF;
	for(int u=src;u!=snk;u=curedge[u]->ver)
		flow=min(flow,curedge[u]->cap);

	for(int u=src;u!=snk;u=curedge[u]->ver)
	{
		curedge[u]->cap-=flow;
		curedge[u]->rev->cap+=flow;
		curedge[u]->flow+=flow;
		curedge[u]->rev->flow-=flow;
	}

	return flow;
}

int isap()
{
	rev_bfs();

	int flow=0,u=src;
	memcpy(curedge,edge,sizeof(edge));
	while(dis[src]<node)
	{
		if(u==snk)
		{
			flow+=agument();
			u=src;
		}

		EDGE *cur;
		for(cur=curedge[u];cur!=NULL;cur=cur->next)
			if(cur->cap && dis[u]==dis[cur->ver]+1)
				break;

		if(cur)
		{
			curedge[u]=cur;
			revedge[cur->ver]=cur->rev;
			u=cur->ver;
		}
		else
		{
			curedge[u]=edge[u];
			int mindis=node;
			EDGE *tmp;
			for(tmp=edge[u];tmp!=NULL;tmp=tmp->next)
				if(tmp->cap)
					mindis=min(mindis,dis[tmp->ver]);
			dis[u]=mindis+1;
			if(u!=src)
				u=revedge[u]->ver;
		}
	}

	return flow;
}

void make_edge(EDGE &t,int u,int ver,int cap,EDGE &rev)
{
	t.ver=ver;	t.cap=cap;	t.flow=0;
	t.rev=&rev;
	t.next=edge[u];	edge[u]=&t;
}

void link(int u,int v,int w)
{
	make_edge(data[tot],u,v,w,data[tot+1]);
	make_edge(data[tot+1],v,u,0,data[tot]);
	tot+=2;
}

void d_link(int u,int v,int w)
{
	link(u,v,w);
	link(v,u,w);
}

void kidding()
{
	freopen("in.txt","w",stdout);

	srand((unsigned)time(NULL));
	int dataset=1000;
	while(dataset--)
	{
		int l=rand()%100+1;
		int w=rand()%100+1;
		int n=rand()%10+1;
		int d=rand()%10+1;
		cout<<l<<" "<<w<<" "<<n<<" "<<d<<endl;
		while(n--)
			cout<<rand()%l<<" "<<rand()%w<<endl;
		cout<<endl;
	}
	cout<<"0 0 0 0"<<endl;
}

void init()
{
	src=0;	snk=2*n+1;
	node=snk+1;	tot=0;
	for(int i=src;i<=snk;++i)
		edge[i]=NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
//	kidding();	return 0;
	freopen("in.txt","r",stdin);
	freopen("my_out.txt","w",stdout);
#endif

	int cas=1;
	while(scanf("%d%d%d%d",&l,&w,&n,&d)!=EOF && (l||w||n||d))
	{
		int Dis=4*d*d;
		init();

		for(int i=1;i<=n;++i)
		{
			link(i,i+n,1);
			scanf("%d%d",&pnt[i].x,&pnt[i].y);
			if(pnt[i].y+d>=w)
				link(src,i,1);
			if(pnt[i].y<=d)
				link(i+n,snk,1);
			for(int j=1;j<i;++j)
				if(dist(pnt[i],pnt[j])<=Dis)
				{
					link(j+n,i,1);
					link(i+n,j,1);
				}
		}

		printf("Case %d: %d\n",cas++,isap());
	}

	return 0;
}
