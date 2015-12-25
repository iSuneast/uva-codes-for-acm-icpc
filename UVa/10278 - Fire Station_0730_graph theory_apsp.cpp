/*
10278 - Fire Station

graph theory...
apsp...
用floyd初始化一遍图后,枚举f的位置即可
记得如果没有找到解(可能是所有的i都有f了)
那么直接输出1,也就是说,最终的解在开始时要初始化为1
*/

#include<iostream>
#define MAXN 503
#define INF 0x3f3f3f3f
using namespace std;

int g[MAXN][MAXN],dis[MAXN],f,n;
char buf[MAXN];
bool flag[MAXN];

int floyd()
{
	for(int i=1;i<=n;++i)	g[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
		if(flag[i])
			for(int j=1;j<=n;++j)
				dis[j]=min(dis[j],g[i][j]);

	int key=INF,cur,p=1;
	for(int i=1;i<=n;++i)
		if(!flag[i])
		{
			cur=0;
			for(int j=1;j<=n;++j)
				cur=max(cur,min(g[i][j],dis[j]));
			if(cur<key)
			{
				key=cur;
				p=i;
			}
		}

	return p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&f,&n);
		memset(g,0x3f,sizeof(g));
		memset(flag,0,sizeof(flag));

		int u,v,w;
		for(int i=0;i<f;++i)
		{
			scanf("%d",&u);
			flag[u]=true;
		}

		gets(buf);
		while(gets(buf) && buf[0])
		{
			sscanf(buf,"%d%d%d",&u,&v,&w);
			g[u][v]=g[v][u]=min(g[u][v],w);
		}

		printf("%d\n",floyd());

		if(dataset)
			putchar(10);
	}

	return 0;
}
