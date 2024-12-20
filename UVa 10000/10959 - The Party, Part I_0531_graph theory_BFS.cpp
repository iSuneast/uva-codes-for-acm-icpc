/*
10959 - The Party, Part I

graph theory...
BFS...
*/

#include<iostream>
#include<queue>
#include<vector>
#define MAXN 1010
#define INF 0x7f7f7f7f
using namespace std;

vector<int> ppl[MAXN];
int ppln,couple,dis[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&ppln,&couple);
		for(int i=0;i<ppln;++i)
			ppl[i].clear(),dis[i]=INF;
		dis[0]=0;
		int u,v;
		while(couple--)
		{
			scanf("%d%d",&u,&v);
			ppl[u].push_back(v);
			ppl[v].push_back(u);
		}
		queue<int> q;
		q.push(0);
		while(!q.empty())
		{
			u=q.front();	q.pop();
			int sz=ppl[u].size();
			for(int i=0;i<sz;++i)
			{
				v=ppl[u][i];
				if(dis[v]>dis[u]+1)
				{
					q.push(v);
					dis[v]=dis[u]+1;
				}
			}
		}
		for(int i=1;i<ppln;++i)
			printf("%d\n",dis[i]);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
