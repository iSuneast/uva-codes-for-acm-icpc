/*
11747 - Heavy Cycle Edges

graph theory...
MST...
*/

#include<iostream>
#include<algorithm>
#define MAXN 25010
#define MAXNODE 1010
using namespace std;

struct graph
{
	int s,e,w;
}edge[MAXN];

int nodes,edges,fa[MAXNODE],idx[MAXN],key[MAXN];

int cmp(const int a,const int b)
{
	return edge[a].w<edge[b].w;
}

int find(int p)
{
	return p==fa[p]?p:p=find(fa[p]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&nodes,&edges)!=EOF && (nodes || edges))
	{
		for(int i=0;i<nodes;++i)
			fa[i]=i;
		for(int i=0;i<edges;++i)
		{
			scanf("%d%d%d",&edge[i].s,&edge[i].e,&edge[i].w);
			idx[i]=i;
		}
		sort(idx,idx+edges,cmp);
		int cnt=0;
		for(int i=0;i<edges;++i)
		{
			int p=idx[i];
			int a=find(edge[p].s),b=find(edge[p].e);
			if(a!=b)
				fa[a]=b;
			else
				key[cnt++]=edge[p].w;
		}
		if(!cnt)
			puts("forest");
		else
		{
			sort(key,key+cnt);
			printf("%d",key[0]);
			bool first=true;
			for(int i=1;i<cnt;++i)
				printf(" %d",key[i]);
			putchar('\n');
		}
	}


	return 0;
}
