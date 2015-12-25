/*
11338 - Minefield

稀疏图.
Dijkstra...
*/

#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#define MAXN 10010
#define INF 1e9
#define MAXDIS 1.5
using namespace std;
typedef pair<double,int> pdi;

int n,flag[MAXN];
double w,const_dis,h,pnt[2][MAXN],dis[MAXN];
priority_queue<pdi,vector<pdi>,greater<pdi> > pq;

void dijkstra(vector<pdi> vec[MAXN])
{
	int i,sz,u,v;
	double d;
	for(i=1;i<n;++i)
		dis[i]=INF;
	memset(flag,0,sizeof(flag));
	pdi cur;
	pq.push(make_pair(dis[0]=0,0));
	while(!pq.empty())
	{
		cur=pq.top();	pq.pop();
		u=cur.second;
		if(flag[u])
			continue;
		else
			flag[u]=1;
		d=cur.first;
		sz=vec[u].size();
		for(i=0;i<sz;++i)
		{
			v=vec[u][i].second;
			if(d+vec[u][i].first<=const_dis)
				pq.push(make_pair(dis[v]=d+vec[u][i].first,v));
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	string buf;
	while(cin>>buf && buf!="*")
	{
		w=pnt[0][1]=atoi(buf.c_str());
		cin>>h;
		pnt[1][1]=h;
		cin>>n;
		vector<pdi> v[MAXN];
		double dx,dy,d;
		pnt[0][0]=pnt[1][0]=0;
		d=sqrt(w*w+h*h);
		if(d<=MAXDIS)
		{
			v[0].push_back(make_pair(d,1));
			v[1].push_back(make_pair(d,0));
		}
		for(int i=2;i<n+2;++i)
		{
			scanf("%lf %lf",&pnt[0][i],&pnt[1][i]);
			for(int j=0;j<i;++j)
			{
				dx=pnt[0][i]-pnt[0][j];
				dy=pnt[1][i]-pnt[1][j];
				d=sqrt(dx*dx+dy*dy);
				if(d>MAXDIS)	//必须在这里剪掉无用路径
					continue;
				v[i].push_back(make_pair(d,j));
				v[j].push_back(make_pair(d,i));
			}
		}
		cin>>const_dis;
		dijkstra(v);
		if(dis[1]==INF || dis[1]>const_dis)
			cout<<"Boom!"<<endl;
		else
			cout<<"I am lucky!"<<endl;
	}

	return 0;
}
