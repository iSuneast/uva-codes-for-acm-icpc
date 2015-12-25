/*
855 - Lunch in Grid City

math...
中位数定理~

happy coding~
*/

#include<cstdio>
#include<algorithm>
#define MAXN 50003
using namespace std;

int x[MAXN],y[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%*d%*d%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",x+i,y+i);
		}
		sort(x, x+n);
		sort(y, y+n);

		printf("(Street: %d, Avenue: %d)\n", x[(n-1)>>1], y[(n-1)>>1]);
	}

	return 0;
}
