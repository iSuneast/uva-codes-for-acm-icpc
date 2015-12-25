/*
10034 - Freckles

MST...
*/

#include<iostream>
#include<queue>
#include<cmath>
#define MAXN 110
using namespace std;

double point[2][MAXN];
int fa[MAXN];

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

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

double kruskal()
{
	int a,b;
	double key=0;
	while(!pq.empty())
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);
		b=find(pnt.e);
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

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n;
		double dx,dy;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			pnt.s=fa[i]=i;
			scanf("%lf %lf",&point[0][i],&point[1][i]);
			for(int j=0;j<i;j++)
			{
				pnt.e=j;
				dx=point[0][i]-point[0][j];
				dy=point[1][i]-point[1][j];
				pnt.w=sqrt(dx*dx+dy*dy);
				pq.push(pnt);
			}
		}
		printf("%.2lf\n",kruskal());
		if(dataset)
			cout<<endl;
	}

return 0;
}
