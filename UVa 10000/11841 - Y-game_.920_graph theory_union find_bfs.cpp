/*
11841 - Y-game

graph theory...
union find set...
*
* A point (x; y; z) in a n-grid is said to lay on the x
* side (resp., y side, z side) if and only if x = 0(resp., y = 0,z = 0).
*
it means that if x=0(no matter what y,z is.) it's a x-grid
just bfs and union find
*/

#include<iostream>
#include<algorithm>
#define MAXN 5000
using namespace std;

const int dx[]={0,0,	1,-1,	1,-1};
const int dy[]={-1,1,	0,0,	-1,1};
const int dz[]={1,-1,	-1,1,	0,0};

struct POINT
{
	int x,y,z;
	bool operator<(const POINT &t)const
	{
		if(x==t.x)
		{
			if(y==t.y)
				return z<t.z;
			return y<t.y;
		}
		return x<t.x;
	}
}pnt[MAXN];
bool x,y,z,flag[3][MAXN];
int n,m,fa[MAXN];

bool cmp(POINT a,POINT b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z;
}

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

bool ok()
{
	POINT t;
	for(int i=0;i<m;++i)
	{
		int degree=0;
		for(int d=0;d<6;++d)
		{
			t.x=pnt[i].x+dx[d];
			t.y=pnt[i].y+dy[d];
			t.z=pnt[i].z+dz[d];
			int p=lower_bound(pnt,pnt+m,t)-pnt;
			if(cmp(pnt[p],t))
			{				
				int a=find(p),b=find(i);
				if(a!=b)
				{
					fa[b]=a;
					flag[0][a]+=flag[0][b];
					flag[1][a]+=flag[1][b];
					flag[2][a]+=flag[2][b];
				}
			}
		}
	}

	for(int i=0;i<m;++i)
	{
		if(flag[0][i] && flag[1][i] && flag[2][i])
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&pnt[i].x,&pnt[i].y,&pnt[i].z);
			fa[i]=i;
			for(int k=0;k<3;++k)
				flag[k][i]=false;
		}

		sort(pnt,pnt+m);

		for(int i=0;i<m;++i)
		{
			int cnt=0;
			if(!pnt[i].x)	++cnt;
			if(!pnt[i].y)	++cnt;
			if(!pnt[i].z)	++cnt;

			flag[0][i]=(pnt[i].x==0);
			flag[1][i]=(pnt[i].y==0);
			flag[2][i]=(pnt[i].z==0);
		}

		puts(ok()?"Benny":"Willy");
	}

	return 0;
}
