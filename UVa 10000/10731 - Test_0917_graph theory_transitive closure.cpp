/*
10731 - Test

graph theory...
transitive closure...
use floyd is enough
*/

#include<iostream>
#define MAXN 30
using namespace std;

bool g[MAXN][MAXN],flag[MAXN];
int fa[MAXN];

int find(int u)
{
	return u==fa[u]?u:fa[u]=find(fa[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	char a[3],b[3],c[3],d[3],e[3],f[3];
	bool first=true;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(!first)
			putchar(10);
		first=false;

		memset(g,0,sizeof(g));
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;++i)
		{
			scanf("%s%s%s%s%s%s",a,b,c,d,e,f);
			g[ f[0]-'A' ][ a[0]-'A' ]=true;
			g[ f[0]-'A' ][ b[0]-'A' ]=true;
			g[ f[0]-'A' ][ c[0]-'A' ]=true;
			g[ f[0]-'A' ][ d[0]-'A' ]=true;
			g[ f[0]-'A' ][ e[0]-'A' ]=true;

			flag[ a[0]-'A' ]=flag[ b[0]-'A' ]=flag[ c[0]-'A' ]=
				flag[ d[0]-'A' ]=flag[ e[0]-'A' ]=true;
		}

		for(int k=0;k<MAXN;++k)
		{
			fa[k]=k;
			for(int i=0;i<MAXN;++i)
				for(int j=0;j<MAXN;++j)
					g[i][j]=g[i][j] || (g[i][k] && g[k][j]);
		}

		for(int i=0;i<MAXN;++i)
		{
			for(int j=0;j<MAXN;++j)
				if(i!=j && g[i][j] && g[j][i])
					fa[ find(i) ]=find(j);
		}

		for(int i=0;i<MAXN;++i)
		{
			if(!flag[i])
				continue;
			putchar('A'+i);
			for(int j=i+1;j<MAXN;++j)
				if(find(j)==find(i))
				{
					printf(" %c",'A'+j);
					flag[j]=false;
				}
				putchar(10);
		}
	}

	return 0;
}
