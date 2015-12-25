/*
 * 709 - Formatting Text
 * 
 * dp...
 * sssp...
 * you can transform this problem to SSSP problem
 * if word[i]~word[j] is in the same line
 * we can link(i, j+1, the_cost_if_i&&j__is_in_the_same_line )
 * use spfa to calculate the sssp
 * 
 * then just backtrack and find the best path
 * don't use simple dfs function or U will get TLE
 * use array next[i] to store the next pase from i
 * for each father node of generate by SPFA
 * 		if next[ father ]<i, next[father]=i
 * 		it's something about GREEDY, but it's right according to
 * 			"Let A and B be two solutions. Find the first gap
 *			 which has not the same length in A and B."
 * 		because, we'd better go as father as possible to minimum our current pase...
 * 
 * done!
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define MAXN 10003
#define MAXE 1000000
#define MAXL 83
#define PENALTY 500
using namespace std;

int len,node_n;
struct NODE
{
	char s[MAXL];
	int l;
}node[MAXN];

struct MY_GRAPH
{
	struct EDGE
	{
		int v,w,blank;
		EDGE *next;
	}*edge[MAXN],data[MAXE];
	int tot;
	
	void init()
	{
		memset(edge,0,sizeof(edge));
		tot=0;
	}
	
	void link(const int &u,const int &v,const int &w,const int &blank)
	{
		data[tot].v=v;
		data[tot].w=w;
		data[tot].blank=blank;
		data[tot].next=edge[u];
		edge[u]=&data[tot++];
	}
	
	int penalty(const int &n,const int &rem)
	{
		int avg=rem%n,more=rem/n;
		return avg*(more+1)*(more+1) + (n-avg)*more*more;
	}
	
	void build()
	{
		for(int i=0;i<node_n;++i)
		{
			int curL=node[i].l;
			link(i,i+1,PENALTY,0);
			for(int j=i+1; j<node_n; ++j)
			{
				curL+=node[j].l+1;
				if(curL>len)
					break;
				link(i,j+1, penalty(j-i, len-curL), len-curL);
			}
		}
	}
	
	bool inq[MAXN];
	int dis[MAXN];
	vector<int> fa[MAXN];
	int blank[MAXN];
	
	void modify(int s,int e)
	{
		if(s+1==e)
		{
			blank[s]=0;
			return ;
		}
		
		for(EDGE *cur=edge[s];cur;cur=cur->next)
		{
			if(cur->v==e)
			{
				int avg=cur->blank/(e-s-1)+1,more=cur->blank%(e-s-1);
				
				blank[e-1]=0;
				for(;s+1<e;++s)
					blank[s]=avg;
				for(;more;more--)
					blank[--s]++;
				
				return ;
			}
		}
	}
	
	int next[MAXN];
	bool vis[MAXN];
	void new_graph(int u)
	{
		if(vis[u])
			return ;
		vis[u]=true;
		for(int i=0,sz=fa[u].size(); i<sz; ++i)
		{
			new_graph(fa[u][i]);
			if( next[ fa[u][i] ]< u )
				next[ fa[u][i] ] = u;
		}
	}
	
	void spfa()
	{
		for(int i=0;i<=node_n;++i)
		{
			fa[i].clear();
		}
		memset(dis,0x3f,sizeof(dis));
		queue<int> q;
		
		q.push(0);	inq[0]=true;	dis[0]=0;
		while(!q.empty())
		{
			int u=q.front();	q.pop();	inq[u]=false;
			for(EDGE *cur=edge[u]; cur; cur=cur->next)
			{
				if(dis[cur->v]>dis[u]+cur->w)
				{
					dis[cur->v]=dis[u]+cur->w;
					fa[cur->v].clear();
					fa[cur->v].push_back(u);
					if(!inq[cur->v])
					{
						inq[cur->v]=true;
						q.push(cur->v);
					}
				}
				else if(dis[cur->v]==dis[u]+cur->w)
					fa[cur->v].push_back(u);
			}
		}
		
		memset(next,0,sizeof(next));
		memset(vis,0,sizeof(vis));
		new_graph(node_n);
		for(int u=0; u!=node_n; u=next[u])
		{
			modify(u,next[u]);
		}		
	}
	
	void output()
	{
		for(int i=0;i<node_n;++i)
		{
			printf("%s",node[i].s);
			if(!blank[i])
				putchar(10);
			else for(int j=0; j<blank[i]; ++j)
				putchar(' ');
		}
	}
	
	void process()
	{
		init();
		build();
		spfa();
		output();
	}
}final;

char buf[MAXN];
void read()
{
	node_n=0;
	while(gets(buf) && buf[0])
	{
		for(char *token=strtok(buf," "); token; token=strtok(NULL," "))
		{
			node[node_n].l=strlen(token);
			strcpy(node[node_n++].s, token);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    while(scanf("%d%*c",&len)!=EOF && len)
    {
    	read();
    	final.process();
    	putchar(10);
    }

    return 0;
}

