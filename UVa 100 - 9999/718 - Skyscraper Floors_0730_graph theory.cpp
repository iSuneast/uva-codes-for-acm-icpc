/*
718 - Skyscraper Floors

graph theory...
对于不同的(x,y)判断是否存在k,使得y+kx相等
如果相等则,连接一条边
y1+k1*x1=y2+k2*x2	(y1>y2)
则	k2=(y1+k1*x1-y2)/x2
判断k2是否是整数
不是的话++k1继续判断
因为%x2的取值为[0,x2),如果发现某次的取模又落在同一个位置,
则可以判定方程无解

最后判一下从源点可否到达终点即可
*/

#include<iostream>
#include<set>
#define MAXN 105
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN*2];
int tot,src,snk;

struct DATA{int x,y;}var[MAXN];
int f,e,a,b;

void graph_init()
{
	src=0;snk=e+1;
	tot=0;
	memset(edge,0,sizeof(edge));
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void d_link(int u,int v)
{
	link(u,v);
	link(v,u);
}

bool chk(DATA &a,DATA &b)
{
	int k=(b.y-a.y)/a.x,t=a.y+k*a.x-b.y;
	set<int> s;
	while(t<f)
	{
		if(s.find(t%b.x)!=s.end())
			break;
		s.insert(t%b.x);
		if(t%b.x==0)
			return true;
		t+=a.x;
	}
	return false;
}

bool flag[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(EDGE *cur=edge[u];cur;cur=cur->next)
		if(!flag[ cur->v ])
			dfs(cur->v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,i,j,k;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d%d",&f,&e,&a,&b);
		graph_init();
		for(i=1;i<=e;++i)
		{
			scanf("%d%d",&var[i].x,&var[i].y);
			if(a>=var[i].y && (a-var[i].y)%var[i].x==0)
				d_link(src,i);
			if(b>=var[i].y && (b-var[i].y)%var[i].x==0)
				d_link(snk,i);

			for(j=1;j<i;++j)
			{
				bool done=false;
				if(var[i].y>var[j].y)
					done=chk(var[j],var[i]);
				else if(var[i].y<var[j].y)
					done=chk(var[i],var[j]);
				else
					done=true;
				if(done)
					d_link(i,j);
			}
		}

		memset(flag,0,sizeof(flag));
		dfs(src);
		puts(flag[snk]?"It is possible to move the furniture."
		:"The furniture cannot be moved.");
	}

	return 0;
}
