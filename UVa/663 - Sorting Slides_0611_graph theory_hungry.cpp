/*
663 - Sorting Slides

graph theory...
hungry...
题目并没有要求一定要最大匹配才行...
也就是说能确定几个是几个...

然后枚举匹配的点对...
删除它们的边并重置为未匹配的状态...
尝试重新匹配...
如果匹配成功则匹配不唯一...

kao,怎么会WA那么多次...
*/

#include<iostream>
#define MAXN 100
using namespace std;

struct POINT
{
	int x,y;
}alpha;

pair<POINT,POINT> slide[MAXN];
int g[MAXN][MAXN],match[MAXN],tot,n;
bool flag[MAXN];
int buf[MAXN],ans[MAXN];

int dfs(int u)
{
	for(int v=0;v<tot;++v)
		if(g[u][v] && !flag[v])
		{
			flag[v]=true;
			int t=match[v];
			match[v]=u;
			if(t==-1 || dfs(t))
				return 1;
			match[v]=t;
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

	memcpy(ans,match,sizeof(match));
	for(int i=0;i<tot;++i)
		if(match[i]!=-1)
		{
			memcpy(buf,match,sizeof(match));
			memset(flag,0,sizeof(flag));
			int t=match[i];
			g[i][t]=g[t][i]=false;
			match[t]=match[i]=-1;
			if(dfs(t))
			{
				ans[i]=-1;
				key--;
			}
			g[i][t]=g[t][i]=true;
			memcpy(match,buf,sizeof(match));
		}

	return key!=0;
}

bool inside(int u,int s,int e)
{
	return u>=s && u<=e;
}

void link(POINT a,pair<POINT,POINT> s,int u,int v)
{
	if(!inside(a.x,s.first.x,s.second.x))
		return ;
	if(!inside(a.y,s.first.y,s.second.y))
		return ;
	g[u][v]=g[v][u]=true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		tot=n*2;
		memset(g,0,sizeof(g));

		for(int i=0;i<n;++i)
			scanf("%d%d%d%d",&slide[i].first.x,&slide[i].second.x,
				&slide[i].first.y,&slide[i].second.y);

		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&alpha.x,&alpha.y);
			for(int j=0;j<n;++j)
				link(alpha,slide[j],n+i,j);
		}

		printf("Heap %d\n",cas++);
		if(hungry())
		{
			bool first=true;
			for(int i=0;i<n;++i)
				if(ans[i]!=-1)
				{
					if(!first)
						putchar(' ');
					first=false;
					printf("(%c,%d)",i+'A',ans[i]-n+1);
				}
			putchar('\n');
		}
		else
			puts("none");

		putchar('\n');
	}

	return 0;
}
