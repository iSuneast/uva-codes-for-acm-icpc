/*
273 - Jack Straws

graph theory...
apsp...
求两点之间是否有一条路径...
判断线段是否相交,建好图
用floyd求一下apsp即可
*/

#include<iostream>
#define MAXN 15
#define EPS 1e-9
using namespace std;

struct TPoint { int x, y; };

int cross(const TPoint & a, const TPoint & b, const TPoint & c)
{ return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

bool seg_inter(TPoint & a, TPoint & b, TPoint & c, TPoint & d)
{
return
max(a.x, b.x) >= min(c.x, d.x) && max(c.x, d.x) >= min(a.x, b.x) &&
max(a.y, b.y) >= min(c.y, d.y) && max(c.y, d.y) >= min(a.y, b.y) &&
cross(a, b, c) * cross(a, b, d) <= EPS &&
cross(c, d, a) * cross(c, d, b) <= EPS;
}

int n;
bool g[MAXN][MAXN];
pair<TPoint,TPoint> ptt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,i,j,k,u,v;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		for(i=1;i<=n;++i)
		{
			g[i][i]=true;
			scanf("%d%d%d%d",&ptt[i].first.x,&ptt[i].first.y,
				&ptt[i].second.x,&ptt[i].second.y);
			for(j=1;j<i;++j)
				g[i][j]=g[j][i]
				=seg_inter(ptt[i].first,ptt[i].second,ptt[j].first,ptt[j].second);
		}

		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					if(g[i][k] && g[k][j])
						g[i][j]=true;

		while(scanf("%d%d",&u,&v)!=EOF && (u||v))
			puts(g[u][v]?"CONNECTED":"NOT CONNECTED");

		if(dataset)
			putchar(10);
	}

	return 0;
}
