/*
10147 - Highways

MST...
*/

#include<iostream>
#include<cmath>
#include<queue>
#define MAXN 760
using namespace std;

typedef pair<int,int> pii;
int n,fa[MAXN];
double x[MAXN],y[MAXN];

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

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int m,a,b,i,j;
		cin>>n;
		double dx,dy;
		priority_queue<graph,vector<graph>,cmp> pq;
		for(i=1;i<=n;++i)
		{
			fa[i]=pnt.s=i;
			scanf("%lf %lf",x+i,y+i);
			for(j=1;j<i;++j)
			{
				pnt.e=j;
				dx=x[i]-x[j];
				dy=y[i]-y[j];
				pnt.w=sqrt(dx*dx+dy*dy);
				pq.push(pnt);
			}
		}

		cin>>m;
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&a,&b);
			a=find(a);
			b=find(b);
			if(a!=b)
				fa[a]=b;
		}

		vector<pii> vi;
		while(!pq.empty())
		{
			pnt=pq.top();	pq.pop();
			a=find(pnt.s);
			b=find(pnt.e);
			if(a!=b)
			{
				fa[a]=b;
				vi.push_back(make_pair(pnt.e,pnt.s));
			}
		}
		i=vi.size();
		if(!i)
			cout<<"No new highways need"<<endl;
		else for(j=0;j<i;++j)
			cout<<vi[j].first<<' '<<vi[j].second<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}
