/*
670 - The dog task

graph theory...
hungry...
*/

#include<iostream>
#include<cmath>
#define MAXN 210
using namespace std;

struct POINT
{
	int x,y;
}dog[MAXN>>1],ppl[MAXN>>1];

int n,m,tot;
bool g[MAXN][MAXN],flag[MAXN];
int match[MAXN];

double dis(POINT a,POINT b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

void link(POINT s,POINT t,POINT c,int u,int v)
{
	if(dis(s,t)*2>=dis(s,c)+dis(c,t))
		g[u][v]=g[v][u]=true;
}

int dfs(int u)
{
	for(int i=0;i<tot;++i)
		if(g[u][i] && !flag[i])
		{
			flag[i]=true;
			int t=match[i];
			match[i]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[i]=t;
		}
	return 0;
}

int hungry()
{
	int key=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<tot;++i)
	{
		memset(flag,0,sizeof(flag));
		key+=dfs(i);
	}
	return key>>1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		tot=n+m;
		memset(g,0,sizeof(g));
		for(int i=0;i<n;++i)
			scanf("%d%d",&ppl[i].x,&ppl[i].y);
		for(int j=0;j<m;++j)
		{
			scanf("%d%d",&dog[j].x,&dog[j].y);
			for(int i=0;i<n-1;++i)
				link(ppl[i],ppl[i+1],dog[j],i,j+n);
		}

		printf("%d\n",n+hungry());
		bool first=true;
		for(int i=0;i<n;++i)
		{
			if(!first)
				putchar(' ');
			first=false;
			printf("%d %d",ppl[i].x,ppl[i].y);
			if(match[i]!=-1)
				printf(" %d %d",dog[ match[i]-n ].x,dog[ match[i]-n ].y);
		}
		putchar('\n');
		if(dataset)
			putchar('\n');
	}

	return 0;
}
