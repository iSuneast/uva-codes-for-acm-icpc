/*
11865 - Stream My Contest

graph theory...
MSDT...
Minimum Spanning Direct Tree...
try to use b_search to locate the final "b" we want
build the graph according to the b
and if the weight of msdt <=cost, then b is ok.
*/

#include<iostream>
#include<algorithm>
#define MAXN 66
using namespace std;
const int INF=0x3f3f3f3f;

struct MSDT
{
	int g[MAXN][MAXN],n;
	int fa[MAXN],key;
	bool flag[MAXN],scc[MAXN];

	void dfs(int u)
	{
		flag[u]=true;
		for(int v=0;v<n;++v)
			if(g[u][v]!=INF && !flag[v])
				dfs(v);
	}

	void init(int _n)
	{
		memset(g,0x3f,sizeof(g));
		n=_n;
	}

	void link(int u,int v,int w)
	{
		g[u][v]=min(g[u][v],w);
	}

	bool chk()
	{
		memset(flag,0,sizeof(flag));
		dfs(0);
		for(int i=0;i<n;++i)
			if(!flag[i])
				return false;
		return true;
	}

	int msdt()
	{
		for(int i=0;i<n;++i)
			if(fa[i]!=i)
				key+=g[fa[i]][i];
		return key;
	}

	int chu_liu()
	{
		key=0;
		memset(scc,0,sizeof(scc));
		scc[0]=true;

		while(true)
		{
			for(int i=0;i<n;++i)	//find the min fa node
			{
				fa[i]=i;
				if(scc[i])
					continue;
				for(int j=0;j<n;++j)
					if(g[fa[i]][i]>g[j][i])
						fa[i]=j;
			}

			bool bk=true;
			for(int i=0;i<n;++i)	//check SCC state
			{
				if(scc[i])
					continue;

				int j=fa[i],tot=0;
				memset(flag,0,sizeof(flag));
				while(!flag[j])
				{
					flag[j]=true;
					tot+=g[ fa[j] ][j];
					j=fa[j];
				}

				if(!flag[i])	//no SCC found
					continue;

				for(int k=0;k<n;++k)
				{
					if(flag[k])	//is a node in SCC
						continue;
					for(int j=0;j<n;++j)
					{
						if(!flag[j])	//isn't a node in SCC
							continue;
						//ReWeighted
						g[i][k]=min(g[i][k],g[j][k]);
						g[k][i]=min(g[k][i],g[k][j]-g[ fa[j] ][j]);
					}
				}

				for(int j=0;j<n;++j)
					if(flag[j] && j!=i)
					{
						for(int k=0;k<n;++k)
							g[k][j]=g[j][k]=INF;
						scc[j]=true;
					}

				key+=tot;
				bk=false;
				break;
			}
			if(bk)
				return msdt();
		}
	}
};

struct DATA
{
	int u,v,b,c;
}data[10003];
bool flag[10003];
int n,m,cost,buf[10003];
MSDT msdt;

void build(int var)
{
	msdt.init(n);
	for(int i=0;i<m;++i)
		if(data[i].b>=var)
			msdt.link(data[i].u,data[i].v,data[i].c);
}

bool ok(int p)
{
	build(buf[p]);
	return msdt.chk() && msdt.chu_liu()<=cost;
}

int b_located(int l,int r)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(!ok(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	return r;
}

void process()
{
	sort(buf,buf+m);
	int p=b_located(0,m-1);

	if(p<0)
		puts("streaming not possible.");
	else
		printf("%d kbps\n",buf[p]);
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
		scanf("%d%d%d",&n,&m,&cost);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&data[i].u,&data[i].v,&data[i].b,&data[i].c);
			buf[i]=data[i].b;
		}

		process();
	}

	return 0;
}
