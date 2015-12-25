/*
924 - Spreading The News

graph theory...
bfs...
π„À—º¥ø…...
*/

#include<iostream>
#define MAXN 2510
#define FRIEND 15
#define INF 0x7f7f7f7f
using namespace std;

int edge[MAXN][FRIEND],sz[MAXN];
int n,m,s,q[MAXN],dis[MAXN],cnt[MAXN];

void bfs()
{
	int front=0,rear=0,m=0,d=0;
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x7f,sizeof(dis));
	dis[s]=0;
	q[rear++]=s;

	while(front<rear)
	{
		s=q[front++];
		for(int i=0;i<sz[s];++i)
		{
			int u=edge[s][i];
			if(dis[u]==INF)
			{
				dis[u]=dis[s]+1;
				++cnt[dis[u]];
				q[rear++]=u;
			}
		}
	}

	for(int i=1;i<MAXN;++i)
		if(cnt[i])
		{
			if(cnt[i]>m)
			{
				m=cnt[i];
				d=i;
			}
		}
		else
			break;
	if(!m)
		puts("0");
	else
		printf("%d %d\n",m,d);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",sz+i);
		for(int j=0;j<sz[i];++j)
			scanf("%d",&edge[i][j]);
	}

	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&s);
		bfs();
	}

	return 0;
}
