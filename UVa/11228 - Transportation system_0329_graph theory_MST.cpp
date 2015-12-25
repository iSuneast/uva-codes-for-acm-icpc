/*
11228 - Transportation system.

MST...
*/

#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 1010
using namespace std;

int n,sets,fa[MAXN];
double point[2][MAXN],roads,rails,r;

struct graph
{
	int s,e;
	double w;
}pnt;

struct cmp
{
	bool operator()(graph a,graph b)
	{
		return a.w>b.w;
	}
};

priority_queue<graph,vector<graph>,cmp> pq;
priority_queue<graph,vector<graph>,cmp> pq_rail;

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

void kruskal()
{
	int i,a,b;
	roads=rails=0;
	sets=1;
	for(i=0;i<n;++i)
		fa[i]=i;
	while(!pq.empty())
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);	b=find(pnt.e);
		if(a!=b)
		{
			fa[a]=b;
			roads+=pnt.w;
		}
	}
	while(!pq_rail.empty())
	{
		pnt=pq_rail.top();	pq_rail.pop();
		a=find(pnt.s);	b=find(pnt.e);
		if(a!=b)
		{
			fa[a]=b;
			rails+=pnt.w;
			++sets;
		}
	}
}

double neared(double var)		//在这里题目有个陷阱。还好比较认真
{
	if(var-floor(var)>ceil(var)-var)
		return ceil(var);
	else
		return floor(var);

}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>n>>r;
		int i,j;
		double dx,dy;
		for(i=0;i<n;++i)
		{
			pnt.s=i;
			scanf("%lf %lf",&point[0][i],&point[1][i]);
			for(j=0;j<i;++j)
			{
				pnt.e=j;
				dx=point[0][i]-point[0][j];
				dy=point[1][i]-point[1][j];
				pnt.w=sqrt(dx*dx+dy*dy);
				if(pnt.w<=r)
					pq.push(pnt);
				else
					pq_rail.push(pnt);
			}
		}
		kruskal();
		cout<<"Case #"<<cas<<": "<<sets<<" "<<neared(roads)<<" "<<neared(rails)<<endl;
	}

	return 0;
}
