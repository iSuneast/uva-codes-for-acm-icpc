/*
10724 - Road Construction

graph theory..
floyd_warshal...
����AC��...
��Ŀ��ʵ���Ѱ�...
�ؼ��Ƕ�floyd�㷨�����̶�...
����Ѿ���floyd��������·...
�ּ���һ���߽�ȥ��...
ͼ�����·�ᷢ���ı�...
���ǲ�����Ҫ���µ���floyd����һ�����·
����g[i][j]=min(g[i][j],g[i][u]+dis[u][v]+g[v][j],g[i][v]+dis[v][u]+g[u][j])
����g[i][j]Ϊ�Ѿ���õ����·
u,vΪ�¼���ı�...ֻ����º�u,v���ӵı߼���
���Ӷ�ΪO(n^2)..
*/

#include<iostream>
#include<cmath>
#define MAXN 54
#define eps 1e-9
using namespace std;

int n,m;
bool flag[MAXN][MAXN];
double g[MAXN][MAXN],pnt[2][MAXN],dis[MAXN][MAXN];

void floyd_warshall()
{
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		int i,j,s,e;
		double dx,dy;
		memset(g,0x7f,sizeof(g));
		for(i=1;i<=n;++i)
		{
			g[i][i]=dis[i][i]=0;
			cin>>pnt[0][i]>>pnt[1][i];
			for(j=1;j<i;++j)
			{
				dx=pnt[0][i]-pnt[0][j];
				dy=pnt[1][i]-pnt[1][j];
				dis[i][j]=dis[j][i]=sqrt(dx*dx+dy*dy);
			}
		}
		memset(flag,0,sizeof(flag));
		for(i=0;i<m;++i)
		{
			cin>>s>>e;
			flag[s][e]=flag[e][s]=1;
			g[s][e]=g[e][s]=dis[s][e];
		}
		floyd_warshall();
		double cost=0;
		s=e=0;
		for(int u=1;u<=n;++u)
			for(int v=1;v<u;++v)
				if(!flag[u][v])
				{
					double t=0;
					for(i=1;i<=n;++i)
						for(j=1;j<i;++j)
							t+=g[i][j]-min(g[i][j],min(g[i][u]+dis[u][v]+g[v][j],g[i][v]+dis[v][u]+g[u][j]));
					if(t>cost)
					{
						cost=t;
						s=v;	e=u;
					}
					else if(t==cost)
					{
						if(dis[u][v]<dis[s][e])
							s=v,e=u;
						else if(dis[u][v]==dis[s][e])
						{
							if(v<s)
								s=v,e=u;
							else if(v==s && u<e)
									e=u;
						}
					}
				}
		if(s==0 || cost<=1.0)
			cout<<"No road required"<<endl;
		else
			cout<<s<<' '<<e<<endl;
	}

	return 0;
}
