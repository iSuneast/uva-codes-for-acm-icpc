/*
10054 - The Necklace

graph theory...
euler...
要输出欧拉回路...
图还不小..所以要做些优化

判顶点度数是否全部为偶数
判连通
将图里面的圈一个一个删掉,最后把所有的圈连在一起就是一个欧拉回路了...
*/

#include<iostream>
#include<vector>
#define MAXN 51
using namespace std;

int g[MAXN][MAXN],tmp[MAXN][MAXN],degree[MAXN],buf[MAXN];
vector<int> edge[1010];
int fa[MAXN],end;
bool got;

void dfs(int u)
{
	if(got)
		return ;
	for(int v=1;v<MAXN;++v)
		if(g[u][v]>0)
		{
			if(fa[v]==-1)
			{
				--g[u][v],--g[v][u];
				fa[v]=u;
				dfs(v);
				++g[u][v],++g[v][u];
			}
			else
			{
				fa[v]=u;
				end=u;
				got=true;
			}
			return ;
		}
}

int cnt;
bool flag[1010];

void chk(int u)
{
	for(int i=1;i<cnt;++i)
		if(!flag[i])
		{
			int sz=edge[i].size();
			for(int j=0;j<sz;++j)
				if(edge[i][j]==u)
				{
					flag[i]=true;
					if(j&1)
					{
						for(int k=j;k>0;k-=2)
						{
							chk(edge[i][k]);
							printf("%d %d\n",edge[i][k],edge[i][k-1]);
							chk(edge[i][k-1]);
						}
						for(int k=sz-1;k>j;k-=2)
						{
							chk(edge[i][k]);
							printf("%d %d\n",edge[i][k],edge[i][k-1]);
							chk(edge[i][k-1]);
						}
					}
					else
					{
						for(int k=j;k+1<sz;k+=2)
						{
							chk(edge[i][k]);
							printf("%d %d\n",edge[i][k],edge[i][k+1]);
							chk(edge[i][k+1]);
						}
						for(int k=0;k<j;k+=2)
						{
							chk(edge[i][k]);
							printf("%d %d\n",edge[i][k],edge[i][k+1]);
							chk(edge[i][k+1]);
						}
					}
					return ;
				}
		}
}

void euler()
{
	for(int i=0;i<1010;++i)
		edge[i].clear();
	cnt=0;

	for(int i=1;i<MAXN;++i)
	{
		for(int j=1;j<MAXN;++j)
			if(g[i][j]>2)
			{
				while(g[i][j]>2)
				{
					edge[cnt].push_back(i);
					edge[cnt].push_back(j);
					edge[cnt].push_back(j);
					edge[cnt].push_back(i);
					g[i][j]-=2;		g[j][i]-=2;
					degree[i]-=2;	degree[j]-=2;
				}
				++cnt;
			}
	}

	for(int i=1;i<MAXN;++i)
		while(degree[i]>0)
		{
			memset(fa,-1,sizeof(fa));
			got=false;
			fa[i]=i;
			dfs(i);

			while(fa[end]!=-1)
			{
				int u=fa[end],v=end;
				edge[cnt].push_back(v);
				edge[cnt].push_back(u);
				--g[u][v];	--g[v][u];
				--degree[u];	--degree[v];
				fa[end]=-1;
				end=u;
			}
			++cnt;
		}
	
	int sz=edge[0].size();
	memset(flag,0,sizeof(flag));	flag[0]=true;
	for(int i=0;i<sz;i+=2)
	{
		chk(edge[0][i]);
		printf("%d %d\n",edge[0][i],edge[0][i+1]);
		chk(edge[0][i+1]);
	}
}

void dfs_vis(int u)
{
	buf[u]=0;
	for(int v=1;v<MAXN;++v)
		if(buf[v] && g[u][v])
			dfs_vis(v);
}

bool check()
{
	for(int i=1;i<MAXN;++i)
	{
		if(degree[i]&1)
			return false;
		buf[i]=degree[i];
	}

	for(int i=1;i<MAXN;++i)
		if(buf[i])
		{
			dfs_vis(i);
			for(int j=i;j<MAXN;++j)
				if(buf[j])
					return false;
			return true;
		}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		memset(degree,0,sizeof(degree));

		int u,v;
		while(n--)
		{
			scanf("%d%d",&u,&v);
			++g[u][v];	++g[v][u];
			++degree[u];	++degree[v];
		}

		printf("Case #%d\n",cas);
		if(!check())
			puts("some beads may be lost");
		else
			euler();

		if(cas!=dataset)
			putchar('\n');
	}

	return 0;
}

/*
chk.cpp		------		spj
#include<iostream>
using namespace std;

int main()
{
	freopen("my_out.txt","r",stdin);
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int u,v,ori;
		scanf("%d%d",&u,&v);
		ori=u;
		u=v;
		bool got=false;
		for(int i=2;i<=n;++i)
		{
			scanf("%d",&v);
			if(u!=v)
				got=true;
			scanf("%d",&u);
		}
		if(got)
			cout<<"-------------WA"<<endl;
		else
			cout<<"AC"<<endl;
	}

	return 0;
}

*/

/*
rand.cpp	随机数据生成
#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	
	srand((unsigned)time(NULL));
	int dataset=100;
	cout<<dataset<<endl;
	while(dataset--)
	{
		int edge=rand()%1000;
		cout<<edge+1<<endl;
		int u,v,ori;
		ori=u=rand()%50+1;
		while(edge--)
		{
			v=rand()%50+1;
			cout<<u<<" "<<v<<endl;
			u=v;
		}
		cout<<u<<" "<<ori<<endl;
	}

	return 0;
}

*/