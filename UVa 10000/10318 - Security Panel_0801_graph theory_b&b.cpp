/*
10318 - Security Panel

graph theory...
搜索题...
直接暴力+B&&B
分支界定...其实就是剪枝啦...
从sample可以观察到说操作的顺序其实是无关紧要的
所以可以从(1,1)枚举到(n,m)
其次,可以发现说枚举(i,j)的时候如果发现([1,i-2],j)有未翻转的则可以剪枝
因为(i,j)的操作至多只会影响到i-1行,上面的状态已经是确定了...
*/

#include<iostream>
#define MAXN 10
#define INF 0x3f3f3f3f
using namespace std;

char buf[MAXN];
int g[MAXN][MAXN],n,m,ans[MAXN*MAXN];
const int dx[]={-1,-1,-1,0,0,0,1,1,1};
const int dy[]={-1,0,1,-1,0,1,-1,0,1};
int tot,cnt;
bool add[MAXN];

void process(int x,int y)
{
	for(int d=0;d<9;++d)
	{
		int tx=x+dx[d],ty=y+dy[d];
		if(g[tx][ty] && add[d])
			g[tx][ty]*=-1;
	}
}

void recovery(int x,int y)
{
	for(int d=0;d<9;++d)
	{
		int tx=x+dx[d],ty=y+dy[d];
		if(g[tx][ty] && add[d])
			g[tx][ty]*=-1;
	}
}

bool chk()
{
	for(int i=max(n-2,1);i<=n;++i)
		for(int j=1;j<=m;++j)
			if(g[i][j]==-1)
				return false;
	return true;
}

bool well(int p)
{
	if(p<1)
		return true;
	for(int j=1;j<=m;++j)
		if(g[p][j]==-1)
			return false;
	return true;
}

int final[MAXN*MAXN],sz;

void dfs(int p)
{
	if(cnt>sz)
		return ;
	else if(p>=tot)
	{
		if(!chk())
			return ;
		if(sz>cnt)
		{
			sz=cnt;
			memcpy(final,ans,sizeof(ans));
		}
	}
	else
	{
		int x=p/m+1,y=p%m+1;
		if(!well(x-2))
			return ;

		process(x,y);
		ans[cnt++]=p;
		dfs(p+1);
		--cnt;

		recovery(x,y);
		dfs(p+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		tot=n*m;
		for(int i=0;i<3;++i)
		{
			scanf("%s",buf);
			for(int j=0;j<3;++j)
				add[i*3+j]=(buf[j]=='*'?1:0);
		}

		printf("Case #%d\n",cas++);
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				g[i][j]=-1;

		cnt=0;
		sz=INF;
		dfs(0);

		if(sz==INF)
			puts("Impossible.");
		else
		{
			printf("%d",final[0]+1);
			for(int i=1;i<sz;++i)
				printf(" %d",final[i]+1);
			putchar(10);
		}
	}

	return 0;
}
