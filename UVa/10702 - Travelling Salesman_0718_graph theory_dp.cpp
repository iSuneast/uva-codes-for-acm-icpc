/*
10702 - Travelling Salesman

graph theory...
直接bfs搜索就可以了...
dis[i][dep+1]=dis[u][dep]+g[u][i]
即每次经过dep条路到达u点后又经过一条g[u][i]
	到达i点,共经过dep+1条路
*/

#include<iostream>
#include<queue>
#define CITY 103
#define TEMP 1010
using namespace std;
typedef pair<int,int> pii;

int g[CITY][CITY],dis[CITY][TEMP];
int c,s,e,t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d%d%d",&c,&s,&e,&t)!=EOF && (c||s||e||t))
	{
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=c;++i)
			for(int j=1;j<=c;++j)
				scanf("%d",&g[i][j]);

		dis[s][0]=0;
		queue<pii> q;
		q.push(make_pair(s,0));
		while(!q.empty())
		{
			pii cur=q.front();	q.pop();
			int u=cur.first,dep=cur.second;
			if(dep>t)
				break;
			for(int i=1;i<=c;++i)
				if(i!=u && dis[i][dep+1]<dis[u][dep]+g[u][i])
				{
					dis[i][dep+1]=dis[u][dep]+g[u][i];
					q.push( make_pair(i,dep+1) );
				}
		}

		int key=0,u;
		while(e--)
		{
			scanf("%d",&u);
			key=max(key,dis[u][t]);
		}
		printf("%d\n",key);
	}


	return 0;
}
