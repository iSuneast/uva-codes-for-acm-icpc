/*
10511 - Councilling

graph theory...
max-flow
最大流...
建图会稍微麻烦一点

源->club(cap=1)->resident(cap=1)->
party(cap=1)->汇(cap=ceil(club_num/2)-1)....

求最大流,如果满流则
把club->resident有流量的边输出即可
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#define MAXN 5000
#define MAXE 300000
#define INF 0x3f3f3f3f
using namespace std;

struct EDGE
{
	int v,cap,flow;
	EDGE *next,*rev;
}*edge[MAXN],data[MAXE],*cur_edge[MAXN],*rev_edge[MAXN];
int tot,src,snk,node;

char buf[100];
map<string,int> res,par,club;
map<int,string> mis_club,mis_res;
vector<int> vi_par,vi_club;

void graph_init()
{
	res.clear();	par.clear();	club.clear();
	mis_res.clear();	mis_club.clear();
	vi_par.clear();	vi_club.clear();

	tot=0;
	src=0,snk=1,node=2;
	memset(edge,0,sizeof(edge));
}

void make_edge(EDGE *cur,int u,int v,int cap,EDGE *rev)
{
	cur->v=v;	cur->cap=cap;	cur->flow=0;
	cur->next=edge[u];	edge[u]=cur;	cur->rev=rev;
}

void link(int u,int v,int cap)
{
	make_edge(&data[tot],u,v,cap,&data[tot+1]);
	make_edge(&data[tot+1],v,u,0,&data[tot]);
	tot+=2;
}

void make_graph ()
{
	graph_init();

	int x,y,z,cap=0;
	while(gets(buf) && buf[0])
	{
		char *token=strtok(buf," ");
		mis_res[x=node]=token;
		res[token]=node++;

		token=strtok(NULL," ");
		if(par.find(token)==par.end())
		{
			vi_par.push_back(y=node);
			par[token]=node++;
		}
		else
			y=par[token];
		link(x,y,1);

		token=strtok(NULL," ");
		while(token)
		{
			if(club.find(token)==club.end())
			{
				++cap;
				vi_club.push_back(node);
				mis_club[z=node]=token;
				link(src,z,1);
				club[token]=node++;
			}
			else
				z=club[token];

			link(z,x,1);

			token=strtok(NULL," ");
		}
	}

	int sz=vi_par.size();
	if(cap&1)
		cap/=2;
	else
		cap=cap/2-1;
	for(int i=0;i<sz;++i)
		link(vi_par[i],snk,cap);
}

int q[MAXN],dis[MAXN],cnt[MAXN];

void rev_bfs()
{
#define PUSH(s) {q[rear++]=s;}

	int u=snk,front=0,rear=0;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	PUSH(u);	dis[u]=0;	cnt[0]=1;
	while(front<rear)
	{
		u=q[front++];
		for(EDGE *cur=edge[u];cur;cur=cur->next)
			if(dis[cur->v]==INF)
			{
				dis[cur->v]=dis[u]+1;
				++cnt[ dis[cur->v] ];
				PUSH(cur->v);
			}
	}
}

int augment()
{
	int flow=INF,u;

	for(u=src;u!=snk;u=cur_edge[u]->v)
		flow=min(flow,cur_edge[u]->cap);

	for(u=src;u!=snk;u=cur_edge[u]->v)
	{
		cur_edge[u]->cap-=flow;
		cur_edge[u]->flow+=flow;
		cur_edge[u]->rev->cap+=flow;
		cur_edge[u]->rev->flow-=flow;
	}

	return flow;
}

int isap()
{
	int flow=0,u=src;
	rev_bfs();
	memcpy(cur_edge,edge,sizeof(edge));

	while(dis[src]<node)
	{
		if(u==snk)
		{
			flow+=augment();
			u=src;
		}

		EDGE *cur=cur_edge[u];
		for(;cur;cur=cur->next)
			if(cur->cap && dis[u]==dis[cur->v]+1)
				break;

		if(cur)
		{
			cur_edge[u]=cur;
			rev_edge[cur->v]=cur->rev;
			u=cur->v;
		}
		else
		{
			if(!(--cnt[dis[u]]))
				break;
			cur_edge[u]=edge[u];
			int dist=node;
			for(cur=edge[u];cur;cur=cur->next)
				if(cur->cap)
					dist=min(dist,dis[cur->v]);
			dis[u]=dist+1;

			++cnt[ dis[u] ];
			if(u!=src)
				u=rev_edge[u]->v;
		}
	}

	return flow;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);gets(buf);gets(buf);
	while(dataset--)
	{
		make_graph();

		if(isap()!=club.size())
			puts("Impossible.");
		else
		{
			int sz=vi_club.size();
			for(int i=0;i<sz;++i)
			{
				int u=vi_club[i];
				for(EDGE *cur=edge[u];cur;cur=cur->next)
					if(!cur->cap && cur->flow>0)
						cout<<mis_res[cur->v]<<" "<<mis_club[u]<<endl;
			}
		}

		if(dataset)
			putchar(10);
	}

	return 0;
}
