/*
929 - Number Maze

Dijkstra...
priority_queue...
*/

#include<iostream>
#include<queue>
#define MAXN 1000
#define INF 1e8
using namespace std;

typedef pair<int,int> pii;
int w[MAXN][MAXN],d[MAXN][MAXN],flag[MAXN*MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int m,n,i,j,cur,x,y;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				d[i][j]=INF;
				scanf("%d",&w[i][j]);
			}
		d[0][0]=w[0][0];
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		memset(flag,0,sizeof(flag));
		cur=x=y=0;
		pq.push(make_pair(d[x][y],cur));
		while(!pq.empty())		//四个方向对应四种情况.
		{
			pii u=pq.top();	pq.pop();	//u.first用于pq的排序依据.
			if(flag[u.second])
				continue;
			flag[u.second]=1;

			cur=u.second;
			x=cur/m;	y=cur%m;
			if(x && d[x-1][y]>d[x][y]+w[x-1][y])
			{
				d[x-1][y]=d[x][y]+w[x-1][y];
				cur=(x-1)*m+y;
				pq.push(make_pair(d[x-1][y],cur));
			}
			if(y && d[x][y-1]>d[x][y]+w[x][y-1])
			{
				d[x][y-1]=d[x][y]+w[x][y-1];
				cur=x*m+y-1;
				pq.push(make_pair(d[x][y-1],cur));
			}
			if(x+1<n && d[x+1][y]>d[x][y]+w[x+1][y])
			{
				d[x+1][y]=d[x][y]+w[x+1][y];
				cur=(x+1)*m+y;
				pq.push(make_pair(d[x+1][y],cur));
			}
			if(y+1<m && d[x][y+1]>d[x][y]+w[x][y+1])
			{
				d[x][y+1]=d[x][y]+w[x][y+1];
				cur=x*m+y+1;
				pq.push(make_pair(d[x][y+1],cur));
			}
		}
		cout<<d[n-1][m-1]<<endl;
	}

return 0;
}
