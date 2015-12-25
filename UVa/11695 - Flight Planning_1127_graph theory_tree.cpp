/*
11695 - Flight Planning

graph theory...
tree center...

we just need to find out all the edges in the diameter of the tree
delete the edge, so the tree become of two subtree
merger these two subtree by add an edge between their center
calculate the current diameter, if it's better, update the answer
*/

#include<iostream>
#define MAXN 2530
using namespace std;
const int INF=0x3f3f3f3f;

struct DATA
{
	int u,v;
	bool flag;
}input[MAXN];

struct EDGE
{
	int v;
	EDGE *next;
}*edge[MAXN],data[MAXN<<2];
int n,tot;
bool fade[MAXN][MAXN];

void link(int &u,int &v)
{
	data[tot].v=v;
	data[tot].next=edge[u];
	edge[u]=&data[tot++];
}

typedef pair<int,int> pii;
int minH,dis1[MAXN],dis2[MAXN];
pii ori,tar;
bool flag[MAXN];

int RandomSelect()
{
	for(int i=1;i<=n;++i)
		if(!flag[i])
			return i;
}

int q[MAXN];
int bfs(int u,int *dis)
{
	memset(dis,0x3f,sizeof(int)*MAXN);
	dis[u]=0;
	int bgn=0,end=0;
	q[end++]=u;
	while(bgn<end)
	{
		u=q[bgn++];
		flag[u]=true;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]==INF && !fade[u][cur->v])
			{
				dis[cur->v]=dis[u]+1;
				q[end++]=cur->v;
			}
	}
	return q[end-1];
}

int TreeHei()
{
	int hei=0;
	for(int i=1;i<=n;++i)
		if(dis1[i]!=INF)
			hei=max(hei,dis1[i]);

	return hei;
}

int TreeRoot()
{
	int root=RandomSelect();
	root=bfs(root,dis1);
	root=bfs(root,dis1);
	bfs(root,dis2);

	int hei=TreeHei();

	int cur=INF;
	for(int i=1;i<=n;++i)
		if(dis1[i]+dis2[i]==hei && abs(dis1[i]-dis2[i])<cur)
		{
			cur=abs(dis1[i]-dis2[i]);
			root=i;
		}

		return root;
}

void init()
{
	memset(fade,0,sizeof(fade));

	int root=bfs(1,dis1);
	root=bfs(root,dis1);
	bfs(root,dis2);

	int hei=TreeHei();

	for(int i=1;i<n;++i)
		if(dis1[ input[i].u ]+dis2[ input[i].v ]+1==hei
			|| dis2[ input[i].u ]+dis1[ input[i].v ]+1==hei)
			input[i].flag=true;
}

void process()
{
	init();
	minH=INF;
	for(int i=1;i<n;++i)
	{
		if(!input[i].flag)
			continue;

		int u=input[i].u,v=input[i].v;
		fade[u][v]=fade[v][u]=true;
		memset(flag,0,sizeof(flag));

		int root1=TreeRoot();
		int root2=TreeRoot();
		fade[root1][root2]=fade[root2][root1]=false;

		link(root1,root2);
		link(root2,root1);

		int root=bfs(1,dis1);
		root=bfs(root,dis1);
		int hei=TreeHei();

		if(hei<minH)
		{
			minH=hei;
			ori=make_pair(u,v);
			tar=make_pair(root1,root2);
		}

		fade[root1][root2]=fade[root2][root1]=true;
		fade[u][v]=fade[v][u]=false;
	}

	printf("%d\n",minH);
	printf("%d %d\n",ori.first,ori.second);
	printf("%d %d\n",tar.first,tar.second);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,u,v;
	scanf("%d",&dataset);
	while(dataset--)
	{
		memset(edge,0,sizeof(edge));
		tot=0;

		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			input[i].u=u;	input[i].v=v;	input[i].flag=false;
			link(u,v);
			link(v,u);
		}

		process();
	}

	return 0;
}
