/*
10397 - Connect the Campus

MST...
*/

#include<iostream>
#include<queue>
#include<cmath>
#define MAXN 760
using namespace std;

int n,m,fa[MAXN];
double point[2][MAXN];

struct graph
{
	int s,t;
	double w;
}pnt;

struct cmp
{
	bool operator()(graph a,graph b)
	{
		return a.w>b.w;
	}
};

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

priority_queue<graph,vector<graph>,cmp> pq;

double kruskal()
{
	double key=0;
	int a,b;
	while(!pq.empty())
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);
		b=find(pnt.t);
		if(a!=b)
		{
			fa[a]=b;
			key+=pnt.w;
		}
	}
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>n)
	{
		int i,j,a,b;
		double dx,dy;
		for(i=1;i<=n;i++)
		{
			fa[i]=i;
			pnt.s=i;
			scanf("%lf %lf",&point[0][i],&point[1][i]);
			for(j=1;j<i;j++)
			{
				pnt.t=j;
				dx=point[0][i]-point[0][j];
				dy=point[1][i]-point[1][j];
				pnt.w=sqrt(dx*dx+dy*dy);
				pq.push(pnt);
			}
		}
		cin>>m;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&pnt.s,&pnt.t);
			a=find(pnt.s);
			b=find(pnt.t);
			if(a!=b)
				fa[a]=b;
		}
		printf("%.2lf\n",kruskal());
	}

return 0;
}
