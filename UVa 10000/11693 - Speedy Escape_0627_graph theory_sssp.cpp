/*
11693 - Speedy Escape

graph theory...
sssp...
晕,搞了半天竟然是数据有问题...
崩溃了...

先把警察所在的点从图中删除(可以特判)..
然后以小偷为起点对图进行一次遍历
如果可以到达escape的话有解

然后,先算出警察在图的sssp
再二分小偷的速度,判断是否可以到达escape点
可以的话,降低二分上界...
知道找到一个合适的速度即可...
*/

#include<iostream>
#include<queue>
#define MAXN 110
#define INF 0x7f7f7f7f
#define POLICE 160.
#define eps 1e-9
using namespace std;

double g[MAXN][MAXN],w;
double dis_b[MAXN],dis_p[MAXN];
bool inq[MAXN],escape[MAXN];
int n,m,e,src,snk;
int u,v;

void spfa()
{
	int s=snk;
	for(int i=1;i<=n;++i)	dis_p[i]=INF;
	dis_p[s]=0;

	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(s);	inq[s]=true;

	while(!q.empty())
	{
		s=q.front();	q.pop();	inq[s]=false;
		for(int i=1;i<=n;++i)
			if(g[s][i]!=INF && dis_p[i]>dis_p[s]+g[s][i])
			{
				dis_p[i]=dis_p[s]+g[s][i];
				if(!inq[i])
					q.push(i);
				inq[i]=true;
			}
	}
}

bool spfa(double speed)
{
	int s=src;
	for(int i=1;i<=n;++i)	dis_b[i]=INF;
	dis_b[s]=0;
	if(escape[s])
		return true;
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(s);	inq[s]=true;

	while(!q.empty())
	{
		s=q.front();	q.pop();	inq[s]=false;
		for(int i=1;i<=n;++i)
			if(g[s][i]!=INF && dis_b[i]>dis_b[s]+g[s][i])
			{
				double t=dis_b[s]+g[s][i];
				if(t*POLICE<dis_p[i]*speed)
				{
					dis_b[i]=t;
					if(escape[i])
						return true;
					if(!inq[i])
						q.push(i);
					inq[i]=true;
				}
			}
	}

	return false;
}

void b_located()
{
	spfa();
	double l=0,r=INF,m;
	while(l+eps<r)
	{
		m=(l+r)/2.;
		if(spfa(m) )
			r=m;
		else
			l=m+eps;
	}
	printf("%.7lf\n",m);
}

bool chk()
{
	queue<int> q;
	memset(inq,0,sizeof(inq));
	int s=src;
	q.push(s);	inq[s]=true;
	while(!q.empty())
	{
		s=q.front();	q.pop();
		for(int i=1;i<=n;++i)
			if(i!=snk && g[s][i]!=INF && !inq[i])
			{
				if(escape[i])
					return true;
				if(!inq[i])
					q.push(i);
				inq[i]=true;
			}
	}
	return false;
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
		scanf("%d%d%d",&n,&m,&e);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=INF;

		while(m--)
		{
			scanf("%d%d%lf",&u,&v,&w);
			g[u][v]=g[v][u]=w;		//这里...不是min(w,g[u][v])
		}
		memset(escape,0,sizeof(escape));
		for(int i=0;i<e;++i)
		{
			scanf("%d",&u);
			escape[u]=true;
		}
		scanf("%d%d",&src,&snk);

		if(!chk())
			puts("IMPOSSIBLE");
		else
			b_located();
	}

	return 0;
}
