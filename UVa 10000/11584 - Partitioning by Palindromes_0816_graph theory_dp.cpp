/*
11584 - Partitioning by Palindromes

graph theory...
dp...
转化为最短路模型...
如果s[u-v]是一个回文串,则链接一条u->v+1的边
需要O(n^2)的预处理..
最后dis[len]就是答案了..
*/

#include<iostream>
#define MAXN 1003
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN*MAXN];
char str[MAXN];
int len,tot,dis[MAXN];
bool inq[MAXN];

int spfa()
{
#define PUSH(s)	{if(!inq[s]){q.push(s);	inq[s]=true;}}
#define POP()	{inq[q.front()]=false;	q.pop();}

	queue<int> q;
	PUSH(0);
	memset(dis,0x3f,sizeof(dis));	dis[0]=0;
	while(!q.empty())
	{
		int u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			int v=cur->v+1;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				PUSH(v);
			}
		}
	}

	return dis[len];
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];	edge[u]=&data[tot++];
}

void isPalindromes()
{
	len=strlen(str);
	for(int i=0;i<len;++i)
	{
		link(i,i);
		int l=i-1,r=i+1;
		while(l>=0 && r<len && str[l]==str[r])
			link(l--,r++);
		l=i,r=i+1;
		while(l>=0 && r<len && str[l]==str[r])
			link(l--,r++);
	}
}

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",str);

		graph_init();
		isPalindromes();
		printf("%d\n",spfa());
	}

	return 0;
}
