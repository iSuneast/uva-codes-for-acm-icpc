/*
10113 - Exchange Rates

graph theory....
apsp....
floyd动态加边的O(n^2)算法
只需更新g[u][v]相关的边即可
g[i][j]={ g[i][u] , g[u][v] , g[v][j] }
本题的边权用分式表示,不能直接用浮点数
*/

#include<iostream>
#include<map>
#define MAXN 66
using namespace std;

struct DATA
{
	int m,n;
}g[MAXN][MAXN];
int tot,m,n;
char buf[25],dic[MAXN][25];

template<class T>
int gcd(T a,T b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	map<string,int> msi;
	int i,j,k,u,v;
	memset(g,0,sizeof(g));
	for(i=0;i<MAXN;++i)
		g[i][i].n=g[i][i].m=1;
	while(scanf("%s",buf)!=EOF && buf[0]!='.')
	{
		if(buf[0]=='!')
		{
			scanf("%d%s",&m,buf);
			if(msi.find(buf)==msi.end())
			{
				strcpy(dic[tot],buf);
				msi[buf]=tot++;
			}
			u=msi[buf];

			scanf("%*s%d%s",&n,buf);
			if(msi.find(buf)==msi.end())
			{
				strcpy(dic[tot],buf);
				msi[buf]=tot++;
			}
			v=msi[buf];

			int t=gcd(m,n);
			m/=t,n/=t;
			g[u][v].m=n,g[u][v].n=m;
			g[v][u].m=m,g[v][u].n=n;

			for(i=0;i<tot;++i)
				for(j=0;j<tot;++j)
					if(g[i][u].n && g[v][j].n && !g[i][j].n)
					{
						long long a=g[i][u].m*g[u][v].m*g[v][j].m;
						long long b=g[i][u].n*g[u][v].n*g[v][j].n;
						long long t=gcd(a,b);
						a/=t,b/=t;
						g[i][j].m=a,g[i][j].n=b;
						g[j][i].m=b,g[j][i].n=a;
					}
		}
		else
		{
			scanf("%s",buf);
			u=-1;
			if(msi.find(buf)!=msi.end())
				u=msi[buf];
			scanf("%*s%s",buf);
			v=-1;
			if(msi.find(buf)!=msi.end())
				v=msi[buf];
			if(u==-1 || v==-1 || !g[u][v].n)
				printf("? %s = ? %s\n",dic[u],dic[v]);
			else
				printf("%d %s = %d %s\n",g[u][v].n,dic[u],g[u][v].m,dic[v]);
		}
	}

	return 0;
}
