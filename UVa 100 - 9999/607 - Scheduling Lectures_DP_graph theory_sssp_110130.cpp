/*
607 - Scheduling Lectures

graph theory....
其实这种题应该是DP题的~
不过也可以用最短路ac就是...
从i开始,到j,如果和<=l,那么就连一条边(i,j+1)
权值计算就是按题目给的公式即可~

然后跑一遍sssp就可以了~

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 1003
using namespace std;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXN*100];
int tot;

void link(int u,int v,int w)
{
	data[tot].v=v;
	data[tot].w=w;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

int n,l,c,t[MAXN];

int cost(int a,int b)
{
	if(a==b)
		return 0;
	else if(b-a<=10)
		return -c;
	else
		return (b-a-10)*(b-a-10);
}

int cnt[MAXN],dis[MAXN];
bool inq[MAXN];

void spfa()
{
	memset(cnt,0x3f,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));

	dis[0]=cnt[0]=0;
	queue<int> q;
	q.push(0);	inq[0]=true;
	while(!q.empty())
	{
		int u=q.front();	q.pop();	inq[u]=true;
		for(EDGE *cur=edge[u];cur; cur=cur->next)
		{
			int v=cur->v;
			if(cnt[v]>cnt[u]+1)
			{
				cnt[v]=cnt[u]+1;
				dis[v]=dis[u]+cur->w;
				if(!inq[v])
				{
					inq[v]=true;
					q.push(v);
				}
			}
			else if(cnt[v]==cnt[u]+1)
			{
				dis[v]=min( dis[v], dis[u]+cur->w );
				if(!inq[v])
				{
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(cas!=1)
			putchar(10);

		scanf("%d%d",&l,&c);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&t[i]);
		}

		tot=0;
		memset(edge,0,sizeof(edge));

		for(int i=0;i<n;++i)
		{
			for(int s=0,p=i; p<n; ++p)
			{
				if(s+t[p]>l)
					break;
				s+=t[p];
				link(i,p+1,cost(s,l));
			}
		}

		spfa();
		printf("Case %d:\n",cas++);
		printf("Minimum number of lectures: %d\n",cnt[n]);
		printf("Total dissatisfaction index: %d\n",dis[n]);
	}

	return 0;
}
