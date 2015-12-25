/*
10860 - Many a Little makes a Mickle

dp...
sssp...
it's a dp problem, but we can transform it into a sssp....
if A is a substring of B from [s-e],
then we can link(s,e+1)
run sssp in the graph 
the answer is dis[ s.length ]
*/

#include<iostream>
#include<queue>
#define MAXN 10005
#define MAXE 500005
using namespace std;
const int INF=0x3f3f3f3f;

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXE];

char s[MAXN],buf[105];
int len,dis[MAXN],n,tot,l;
bool inq[MAXN];

void graph_init()
{
	memset(edge,0,sizeof(edge));
	tot=0;
}

void link(int u,int v)
{
	data[tot].v=v;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

int spfa()
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	q.push(0);	dis[0]=0;	inq[0]=true;
	while(!q.empty())
	{
		int u=q.front();	q.pop();	inq[u]=false;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]>dis[u]+1)
			{
				dis[cur->v]=dis[u]+1;
				if(!inq[cur->v])
				{
					q.push(cur->v);
					inq[cur->v]=true;
				}
			}
	}

	return dis[len];
}

void process()
{
	char *p1=s,*p;
	while(true)
	{
		p=strstr(p1,buf);
		if(!p)
			break;
		link(p-s,p-s+l);
		p1=p+1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%s%d",s,&n);
		len=strlen(s);

		graph_init();
		while(n--)
		{
			scanf("%s",buf);
			l=strlen(buf);
			process();

			for(int i=0;i<l/2;++i)
				swap(buf[i],buf[l-1-i]);

			process();
		}

		int key=spfa();
		if(key==INF)
			printf("Set %d: Not possible.\n",cas);
		else
			printf("Set %d: %d.\n",cas,key);
	}

	return 0;
}
