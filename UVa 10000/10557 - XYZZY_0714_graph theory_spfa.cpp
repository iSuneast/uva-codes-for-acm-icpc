/*
10557 - XYZZY

graph theory...
��㷨...
�ѵ�������(һ�����,һ������),��Ȩ�ͱ���˱�Ȩ

�Ա�Ȩȡ��,spfa�и�Ȩ��·
���һ�����ڸ�Ȩ��·��,��dfs�����,���ܷ񵽴��յ�,���ԵĻ���"win"
	�����ԵĻ�,��ֱ�ӰѴ����������ı�ȫ��ɾ��,���������õ�,�����ɳڻᵼ����ѭ��
���spfaû�еõ���,���ֻ��Ҫ�ж�һ���յ��ʱ���ɳڹ�,���ɳڹ���"win"


��������������,���Բ������е�dis[v]>dis[u]+g[u][v]�������ɳڵ�
��Ҫ�ж��ɳں�������Ƿ����,�����оͲ�Ҫ�ɳ���...
*/

#include<iostream>
#include<queue>
#define PUSH(n) {q.push(n);inq[n]=true;}
#define POP() {inq[ q.front() ]=false;	q.pop();}
#define BOUND 100
#define MAXN 210
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

int next[MAXN][MAXN],g[MAXN][MAXN],sz[MAXN];
int n;

void link(int u,int v,int w)
{
	next[ u ][ sz[u]++ ]=v;
	g[u][v]=-w;		//ȡ��
}

bool flag[MAXN];

void dfs(int u)
{
	flag[u]=true;
	for(int i=0;i<sz[u];++i)
	{
		int v=next[u][i];
		if(!flag[v])
			dfs(v);
	}
}

bool chk(int u)
{
	memset(flag,0,sizeof(flag));
	dfs(u);
	return flag[n];
}

int relax[MAXN],dis[MAXN];
bool inq[MAXN];

bool spfa()
{
	memset(inq,0,sizeof(inq));
	memset(relax,0,sizeof(relax));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	PUSH(1);	dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(int i=0;i<sz[u];++i)
		{
			int v=next[u][i];
			if(dis[v]>dis[u]+g[u][v] && dis[u]+g[u][v]<BOUND)
			{
				dis[v]=dis[u]+g[u][v];
				if(++relax[v]>=n)
				{
					if(chk(v))
						return true;
					sz[v]=0;
				}
				if(!inq[v])
					q.push(v);
				inq[v]=true;
			}
		}
	}
	return dis[n]!=INF;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		int u,v,w,t;
		memset(sz,0,sizeof(sz));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&w);
			link(i,i+n,w);
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&u);
				link(i+n,u,0);
			}
		}

		if( spfa() )
			puts("winnable");
		else
			puts("hopeless");
	}

	return 0;
}
