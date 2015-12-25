/*
334 - Identifying Concurrent Events

graph theory...
apsp...
有向图的传递闭包...
注意输出格式...
题目没说清楚...
在并行后都要输出空格...
只要输出任意前两个就可以了...
*/

#include<iostream>
#include<map>
#define MAXN 250
using namespace std;

char buf[8],dic[MAXN][8];
bool g[MAXN][MAXN];
int n,tot;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1,i,j,k,u,v;
	while(scanf("%d",&n)!=EOF && n)
	{
		map<string,int> msi;
		tot=0;
		memset(g,0,sizeof(g));

		for(i=0;i<n;++i)
		{
			scanf("%d",&k);
			for(j=0;j<k;++j)
			{
				scanf("%s",buf);
				if(j)
					g[tot-1][tot]=true;
				g[tot][tot]=true;
				strcpy(dic[tot],buf);
				msi[buf]=tot++;
			}
		}

		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",buf);	u=msi[buf];
			scanf("%s",buf);	v=msi[buf];
			g[u][v]=true;
		}

		for(k=0;k<tot;++k)
			for(i=0;i<tot;++i)
				for(j=0;j<tot;++j)
					g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);

		int cnt=0;
		for(i=0;i<tot;++i)
			for(j=0;j<i;++j)
				cnt+=!g[i][j] && !g[j][i];

		if(!cnt)
			printf("Case %d, no concurrent events.\n",cas++);
		else
		{
			printf("Case %d, %d concurrent events:\n",cas++,cnt);
			cnt=min(cnt,2);
			int t=cnt;
			for(i=0;i<tot && cnt;++i)
				for(j=i+1;j<tot && cnt;++j)
					if(!g[i][j] && !g[j][i])
					{
						printf("(%s,%s) ",dic[i],dic[j]);
						--cnt;
					}
			putchar(10);
		}
	}

	return 0;
}
