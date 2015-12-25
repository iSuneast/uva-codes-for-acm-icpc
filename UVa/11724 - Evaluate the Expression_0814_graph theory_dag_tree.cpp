/*
11724 - Evaluate the Expression

graph theory...
DAG...
tree...
表达式剖析..
先对所有的限制条件建一张dag图...
判断是否有环...
无环的话,dp求出dag的最长路...
最长路的值就是符号的值,,,

最后对表达式建立一颗表达式树...
递归求出表达式的值
不会溢出
*/

#include<iostream>
#define MAXN 30
#define SZ 333
#define INF 0x3f3f3f3f
using namespace std;

char op[SZ],con[7];
bool g[MAXN][MAXN];
int dis[MAXN],n,flag[MAXN];

void input()
{
	scanf("%s%d",op,&n);
	memset(g,0,sizeof(g));
	while(n--)
	{
		scanf("%s",con);
		g[ con[0]-'a' ][ con[2]-'a' ]=true;
	}
}

bool dfs(int u)
{
	flag[u]=-1;
	for(int v=0;v<MAXN;++v)
		if(g[u][v])
			if(flag[v]==-1 || !dfs(v))
				return false;
	flag[u]=1;
	return true;
}

int dp(int u)
{
	if(dis[u]!=INF)
		return dis[u];
	bool got=false;
	dis[u]=0;
	for(int v=0;v<MAXN;++v)
		if(g[u][v])
		{
			got=true;
			dis[u]=max(dis[u],dp(v)+1);
		}
	if(!got)
		dis[u]=1;
	return dis[u];
}

int build(int s,int e)
{
	if(s+1==e)
		return dis[ op[s]-'a' ];

	int p=s,bk=-1,cnt=0;
	while(p<e)
	{
		if(op[p]=='(')
		{
			++cnt;	++p;
			while(cnt)
			{
				if(op[p]=='(')
					++cnt;
				else if(op[p]==')')
					--cnt;
				++p;
			}
			--p;
		}
		else if(op[p]=='+' && (bk==-1 || op[bk]=='*'))
			bk=p;
		else if(op[p]=='*' && bk==-1)
			bk=p;
		++p;
	}
	if(bk==-1)
		return build(s+1,e-1);
	int a=build(s,bk);
	int b=build(bk+1,e);
	return op[bk]=='+'?a+b:a*b;
}

int process()
{
	memset(flag,0,sizeof(flag));
	for(int i=0;i<MAXN;++i)
		if(!flag[i] && !dfs(i))
			return -1;

	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<MAXN;++i)
		if(dis[i]==INF)
			dp(i);

	return build(0,strlen(op));
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
		input();
		printf("Case %d: %d\n",cas,process());
	}

	return 0;
}
