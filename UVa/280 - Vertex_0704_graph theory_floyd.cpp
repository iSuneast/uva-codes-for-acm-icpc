/*
280 - Vertex

graph theory...
floyd...
有向图的传递闭包...

果然是数据那边有问题...
所以只能一行一行地读入然后提取才行...
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 110
using namespace std;

bool g[MAXN][MAXN];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string s;
	while(scanf("%d",&n)!=EOF && n)
	{
		getline(cin,s);
		int u,v;
		memset(g,0,sizeof(g));
		while(getline(cin,s) && s!="0")
		{
			stringstream sin(s);
			sin>>u;
			while(sin>>v && v)
				g[u][v]=true;
		}

		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(g[i][k] && g[k][j])
						g[i][j]=true;

		int tot;
		getline(cin,s);
		stringstream sin(s);
		sin>>tot;
		while(tot--)
		{
			sin>>u;
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(!g[u][i])
					++cnt;
			printf("%d",cnt);
			for(int i=1;i<=n;++i)
				if(!g[u][i])
					printf(" %d",i);
			putchar('\n');
		}
	}

	return 0;
}
