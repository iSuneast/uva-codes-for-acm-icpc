/*
11222 - Only I did it!

Ad hoc...
just sort and count the unique number

*
* followed by the number of problems that he solved
* but none of the other 2 did
*
*/

#include<iostream>
#include<algorithm>
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;

int solve[3][MAXN],flag[MAXN*10],cnt[3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		memset(flag,0,sizeof(flag));
		for(int i=0;i<3;++i)
		{
			scanf("%d",&solve[i][0]);
			for(int j=1;j<=solve[i][0];++j)
			{
				scanf("%d",&solve[i][j]);
				++flag[ solve[i][j] ];
			}
		}

		int key=0;
		for(int i=0;i<3;++i)
		{
			cnt[i]=0;
			int t=solve[i][0];
			for(int j=1;j<=t;++j)
			{
				if( flag[ solve[i][j] ] == 1 )
					++cnt[i];
				else
				{
					solve[i][j]=INF;
					--solve[i][0];
				}
			}
			sort(solve[i]+1,solve[i]+t+1);
			key=max(cnt[i],key);
		}

		printf("Case #%d:\n",cas);
		for(int i=0;i<3;++i)
		{
			if(cnt[i]!=key)
				continue;
			printf("%d",i+1);
			for(int j=0;j<=solve[i][0];++j)
				printf(" %d",solve[i][j]);
			putchar(10);
		}
	}

	return 0;
}
