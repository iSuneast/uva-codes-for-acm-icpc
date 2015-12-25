/*
 * 11917 - Do Your Own Homework
 *
 * Ad hoc...
 * 水题 , 不过我之前竟然连题目都没看懂...
 * 如果科目不在列表内, 或者科目用时>d+5, 则Do your own homework!
 * 如果科目能在<=d天内完成, Yesss
 * 否则Late
 *
 * happy coding~
 */

#include<iostream>
#include<map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, n, d;
	map<string,int> msi;
	char buf[23];

	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas)
	{
		scanf("%d",&n);
		msi.clear();
		while(n--)
		{
			scanf("%s%d", buf, &d);
			msi[ buf ]=d;
		}
		scanf("%d%s", &d, buf);
		if(msi.find(buf)==msi.end() || msi[buf]>d+5)
			printf("Case %d: Do your own homework!\n", cas);
		else if(msi[buf]<=d)
			printf("Case %d: Yesss\n", cas);
		else
			printf("Case %d: Late\n",cas);
	}

	return 0;
}
