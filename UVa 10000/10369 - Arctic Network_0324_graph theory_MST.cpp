/*
10369 - Arctic Network

MST...
*/

#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 510
using namespace std;

int fa[MAXN],s,p;
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
	int a,b;
	double key=0;
	p-=s;		//只需取p-s条边的MST即可
	while(!pq.empty() && p)
	{
		pnt=pq.top();	pq.pop();
		a=find(pnt.s);
		b=find(pnt.t);
		if(a!=b)
		{
			--p;		//在这里递减p.而不是在while
			fa[a]=b;
			key=key>pnt.w?key:pnt.w;
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
		cin>>s>>p;
		double dx,dy; 
		for(int i=0;i<p;i++)
		{
			fa[i]=i;
			pnt.s=i;
			scanf("%lf %lf",&point[0][i],&point[1][i]);
			for(int j=0;j<i;j++)
			{
				pnt.t=j;
				dx=point[0][i]-point[0][j];
				dy=point[1][i]-point[1][j];
				pnt.w=sqrt(dx*dx+dy*dy);
				pq.push(pnt);
			}
		}
		printf("%.2lf\n",kruskal());
	}

return 0;
}
