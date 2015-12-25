/*
 * 11174 - Stand in a Line
 * 
 * graph theory...
 * dp on tree
 * calculate the valid number of Topo-Sort...
 * 
 * build the graph
 * if b is father of a, link(b,a)
 * if None of all is father of X link(0,x)
 * 
 * |SubTree[i]| is mark as the node count in tree i (i is included)
 * 
 * DP(X)
 * 	for each son of X
 * 	{
 * 		DP(son[i])
 * 		answer[X]*=answer[ son[i] ];
 * 		answer[X]/=( |SubTree[i]|! )
 * 	}
 * 
 * 	answer[X]*=( |SubTree[X]|! )
 * 
 * finally, answer[0] is the request answer...
 */

#include <cstdio>
#include <cstring>
#define MAXN 40001
#define MAXE 100001
#define MOD 1000000007LL
using namespace std;

long long factor[MAXN],revFactor[MAXN];

int powMod(long long n,long long p,long long m)
{
	long long key=1;
	for(; p; p>>=1)
	{
		if(p&1)
			key=key*n%m;
		n=n*n%m;
	}
	
	return key;
}

void init()
{
	factor[0]=1;
	for(int i=1;i<MAXN;++i)
	{
		factor[i]=i*factor[i-1]%MOD;
		revFactor[i]=powMod(factor[i], MOD-2, MOD);
	}
}

struct MY_GRAPH
{
	struct EDGE
	{
		int v;
		EDGE *next;
	}*edge[MAXN],data[MAXE];
	int tot,n,m;
	bool flag[MAXN];
	long long key[MAXN];
	int son[MAXN];
	
	void link(int u,int v)
	{
		data[tot].v=v;
		data[tot].next=edge[u];
		edge[u]=&data[tot++];
	}
	
	void read()
	{
		memset(edge,0,sizeof(edge));
		memset(flag,0,sizeof(flag));
		tot=0;
		
		scanf("%d%d",&n,&m);
		int u,v;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			link(v,u);
			flag[u]=true;
		}
		
		for(int i=1;i<=n;++i)
		{
			if(!flag[i])
				link(0,i);
		}
	}
	
	void dfs(int u)
	{
		key[u]=1;
		for(EDGE *cur=edge[u];cur;cur=cur->next)
		{
			dfs(cur->v);
			son[u]+=son[cur->v]+1;
			key[u]=key[u]*key[cur->v]%MOD;
			
			key[u]=key[u]*revFactor[ son[cur->v]+1 ]%MOD;
		}
		
		key[u]=key[u]*factor[ son[u] ]%MOD;
	}
	
	int process()
	{
		memset(key,0,sizeof(key));
		memset(son,0,sizeof(son));
		dfs(0);
		
		return key[0];
	}
}final;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	
	init();
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		final.read();
		printf("%d\n",final.process());
	}	

	return 0;
}

