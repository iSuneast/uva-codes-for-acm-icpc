/*
10919 - Prerequisites?

Ad hoc...
二分优化...
*/

#include<iostream>
#include<algorithm>
#define MAXN 110
using namespace std;

int k,m,course[MAXN],cate[MAXN],cnt,req;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&k)!=EOF && k)
	{
		scanf("%d",&m);
		for(int i=0;i<k;++i)
			scanf("%d",course+i);
		bool yes=true;

		while(m--)
		{
			scanf("%d",&cnt);
			scanf("%d",&req);
			for(int i=0;i<cnt;++i)
				scanf("%d",cate+i);
			sort(cate,cate+cnt);

			if(yes)
			{
				int key=0;
				for(int i=0;i<k && key<req;++i)
				{
					int p=lower_bound(cate,cate+cnt,course[i])-cate;
					if(p<cnt && cate[p]==course[i])
						++key;
				}
				if(key<req)
					yes=false;
			}
		}
		if(yes)
			puts("yes");
		else
			puts("no");
	}

	return 0;
}
