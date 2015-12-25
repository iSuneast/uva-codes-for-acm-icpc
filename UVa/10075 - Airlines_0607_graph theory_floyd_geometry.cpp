/*
10075 - Airlines

graph theory...
floyd-warshall...
geometry...
计算球面两点距离...贴模板...
本题主要是注意一点
"Round the geographical distance between every pair of cities to the nearest integer."
然后跑一下floyd就可以了...
*/

#include<iostream>
#include<cmath>
#include<string>
#include<map>
#define MAXN 110
#define INF 0x7f7f7f7f
#define pi 3.141592653589793
#define R 6378.0
using namespace std;

double angle(double lng1,double lat1,double lng2,double lat2)
{
	double dlng=(lng1-lng2)*pi/180.0;
	lat1*=pi/180.0,lat2*=pi/180.0;
	return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2));
}

int sphere_dist(double r,double lng1,double lat1,double lng2,double lat2)
{
	double dis=r*angle(lng1,lat1,lng2,lat2);
	int up=ceil(dis),down=floor(dis);
	if(up-dis>dis-down)
		return down;
	else
		return up;
}

int g[MAXN][MAXN];
double city[MAXN][2];
int n,m,q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(cin>>n>>m>>q && (n||m||q))
	{
		if(cas!=1)
			putchar('\n');

		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				g[i][j]=INF;

		map<string,int> msi;
		string name,name2;
		for(int i=0;i<n;++i)
		{
			cin>>name>>city[i][0]>>city[i][1];
			msi[name]=i;
		}
		int u,v;
		for(int i=0;i<m;++i)
		{
			cin>>name>>name2;
			u=msi[name];
			v=msi[name2];
			g[u][v]=min(g[u][v],sphere_dist(R,city[u][1],city[u][0],city[v][1],city[v][0]));
		}

		for(int k=0;k<n;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					if(g[i][k]!=INF && g[k][j]!=INF)
						g[i][j]=min(g[i][k]+g[k][j],g[i][j]);

		printf("Case #%d\n",cas++);
		while(q--)
		{
			cin>>name>>name2;
			u=msi[name];
			v=msi[name2];
			if(g[u][v]!=INF)
				cout<<g[u][v]<<" km"<<endl;
			else
				cout<<"no route exists"<<endl;
		}
	}

	return 0;
}
