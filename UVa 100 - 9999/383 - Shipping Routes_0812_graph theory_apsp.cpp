/*
383 - Shipping Routes

graph theory...
apsp...
求一下apsp...
然后判路径是否存在...
输出答案即可...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 33
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN],m,n,p;
map<string,int> msi;
char buf[MAXN];

void input()
{
	scanf("%d%d%d",&m,&n,&p);
	msi.clear();
	for(int i=0;i<m;++i)
	{
		scanf("%s",buf);
		msi[buf]=i;
	}

	memset(g,0x3f,sizeof(g));
	for(int i=0;i<n;++i)
	{
		scanf("%s",buf);
		int u=msi[buf];
		scanf("%s",buf);
		int v=msi[buf];
		g[u][v]=g[v][u]=1;
	}
}

void floyd()
{
	for(int k=0;k<m;++k)
		for(int i=0;i<m;++i)
			for(int j=0;j<m;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);

	puts("SHIPPING ROUTES OUTPUT\n");
	for(int cas=1;cas<=dataset;++cas)
	{
		input();
		floyd();

		printf("DATA SET  %d\n\n",cas);
		int w,u,v;
		while(p--)
		{
			u=v=-1;
			scanf("%d",&w);
			scanf("%s",buf);
			if(msi.find(buf)!=msi.end())
				u=msi[buf];
			scanf("%s",buf);
			if(msi.find(buf)!=msi.end())
				v=msi[buf];

			if(u==-1 || v==-1 || g[u][v]==INF)
				puts("NO SHIPMENT POSSIBLE");
			else
				printf("$%d\n",w*g[u][v]*100);
		}
		putchar(10);
	}
	puts("END OF OUTPUT");

	return 0;
}
