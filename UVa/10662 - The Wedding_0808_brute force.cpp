/*
10662 - The Wedding

brute force...
显然可以O(n^3)的暴力...
为什么我之前要搞成floyd求图的传递闭包...
*/

#include<iostream>
#define MAXN 23
#define INF 0x3f3f3f3f
using namespace std;

int t,r,h,tr[MAXN][MAXN],rh[MAXN][MAXN],ht[MAXN][MAXN];
int t_c[MAXN],r_c[MAXN],h_c[MAXN];

void input()
{
	for(int i=0;i<t;++i)
	{
		scanf("%d",&t_c[i]);
		for(int j=0;j<r;++j)
			scanf("%d",&tr[i][j]);
	}

	for(int i=0;i<r;++i)
	{
		scanf("%d",&r_c[i]);
		for(int j=0;j<h;++j)
			scanf("%d",&rh[i][j]);
	}

	for(int i=0;i<h;++i)
	{
		scanf("%d",&h_c[i]);
		for(int j=0;j<t;++j)
			scanf("%d",&ht[i][j]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d%d",&t,&r,&h)!=EOF)
	{
		input();

		int key=INF,a,b,c;
		for(int i=0;i<t;++i)
			for(int j=0;j<r;++j)
				for(int k=0;k<h;++k)
					if(!tr[i][j] && !rh[j][k] && !ht[k][i])
						if(key>t_c[i]+r_c[j]+h_c[k])
						{
							key=t_c[i]+r_c[j]+h_c[k];
							a=i,b=j,c=k;
						}

		if(key==INF)
			puts("Don't get married!");
		else
			printf("%d %d %d:%d\n",a,b,c,key);	
	}

	return 0;
}
