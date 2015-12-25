/*
 * 10337 - Flight Planner
 *
 * dp...
 * 非常简单的递推...
 *
 * happy coding~
 */

#include<iostream>
#include<cstdio>
#define MAXN 1003
#define MAXH 10
#define UP 60
#define DOWN 20
#define HOLD 30
using namespace std;

int wind[MAXH][MAXN], dp[MAXH][MAXN];

void ChkMin(int &a,const int &t)
{
	if(a>t)
		a=t;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, x;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&x);
		x/=100;
		for(int h=MAXH-1; h>=0; --h)
		{
			for(int p=0; p<x; ++p)
			{
				scanf("%d",&wind[h][p]);
			}
		}

		memset(dp, 0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int p=0; p<x; ++p)
		{
			for(int h=0; h<MAXH; ++h)
			{
				if(h!=0)
					ChkMin(dp[h-1][p+1], dp[h][p]+DOWN-wind[h][p]);
				if(h+1!=MAXH)
					ChkMin(dp[h+1][p+1], dp[h][p]+UP-wind[h][p]);
				ChkMin(dp[h][p+1], dp[h][p]+HOLD-wind[h][p]);
			}
		}

		printf("%d\n\n", dp[0][x]);
	}

	return 0;
}
