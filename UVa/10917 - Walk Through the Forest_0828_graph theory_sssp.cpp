/*
10917 - Walk Through the Forest

graph theory...
dp...
this problem isn't so hard...
you should read the description carefully

*	He considers taking a path from A to B to be progress
*	if there exists a route from B to his home that
*	is shorter than any possible route from A

calc the sssp from node 2
for any edge (u,v)
if dis[v]<dis[u] then dp(u)+=dp(v)
notice that dp(2)=1
*/

#include<iostream>
#include<queue>
#define MAXN 1003
#define MAXE 1000003
using namespace std;

struct EDGE
{
	int v,w;
	EDGE *next;
}*edge[MAXN],data[MAXE];
int n,m,tot,cnt[MAXN],dis[MAXN],dis2[MAXN];
bool inq[MAXN];

void spfa(int u)
{
#define PUSH(s)	{if(!inq[s]) { inq[s]=true; q.push(s); } }
#define POP()	{ inq[ q.front() ]=false;	q.pop(); }

	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	dis[u]=0;	PUSH(u);
	while(!q.empty())
	{
		u=q.front();	POP();
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[ cur->v ]>dis[u]+cur->w)
			{
				dis[cur->v]=dis[u]+cur->w;
				PUSH(cur->v);
			}
	}
}

bool flag[MAXN];

int dp(int u)
{
	if(cnt[u]==-1)
	{
		cnt[u]=0;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			if(dis[cur->v]<dis[u])
				cnt[u]+=dp(cur->v);
		}
	}
	return cnt[u];
}

void random_data();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		memset(edge,0,sizeof(edge));
		tot=0;
		scanf("%d",&m);
		int u,v,w;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&w);
			data[tot].v=v;	data[tot].w=w;
			data[tot].next=edge[u];	edge[u]=&data[tot++];
			data[tot].v=u;	data[tot].w=w;
			data[tot].next=edge[v];	edge[v]=&data[tot++];			
		}
		spfa(2);

		memset(cnt,-1,sizeof(cnt));
		cnt[2]=1;
		printf("%d\n",dp(1));
	}

	return 0;
}

void random_data()
{
	bool g[MAXN][MAXN];
	srand((unsigned)time(NULL));
	freopen("in","w",stdout);
	int dataset=100;

	while(dataset--)
	{
		memset(g,0,sizeof(g));
		int n=rand()%6+1,m=rand()%(n*n/4+1);
		cout<<n<<" "<<m<<endl;
		int u,v,w;
		while(m--)
		{
			u=rand()%n+1;
			v=rand()%n+1;
			while(u==v || g[u][v]|| g[v][u])
			{
				u=rand()%n+1;
				v=rand()%n+1;
			}
			g[u][v]=g[v][u]=true;
			cout<<u<<" "<<v<<" "<<rand()%10+1<<endl;
		}
		cout<<endl;
	}
	cout<<0<<endl;
}
