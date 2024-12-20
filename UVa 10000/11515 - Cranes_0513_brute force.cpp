/*
11515 - Cranes

brute force...
直接暴力枚举吧..
状态量只有1^15。..
不会超时...
*/

#include<iostream>
#define MAXN 20
using namespace std;

struct point
{
	int x,y,w;
}pnt[15];

int g[MAXN][MAXN],lis[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,key=-1;
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&pnt[i].x,&pnt[i].y,&pnt[i].w);
			for(int j=0;j<i;++j)
			{
				int dx=pnt[i].x-pnt[j].x;
				int dy=pnt[i].y-pnt[j].y;
				int r=pnt[i].w+pnt[j].w;
				if(dx*dx+dy*dy>r*r)		//没有等号
					g[i][j]=g[j][i]=1;
			}
		}
		for(int i=1;i<(1<<n);++i)
		{
			bool done=true;
			int t=0,cnt=0;
			for(int j=0;j<n && done;++j)
				if(i&(1<<j))
				{
					for(int k=0;k<cnt;++k)
						if(!g[j][lis[k]])
						{
							done=false;
							break;
						}
					lis[cnt++]=j;
					t+=pnt[j].w*pnt[j].w;
				}
			if(done)
				key=max(t,key);
		}
		printf("%d\n",key);
	}

	return 0;
}
