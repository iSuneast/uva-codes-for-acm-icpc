/*
11790 - Murcia's Skyline

dp...
非常无语的LIS题...
竟然会有负数解的情况...
可见以后初始化值是一定要小心一点的...
不过估计也就只有UVa这种OJ才会有这种BT数据...
*/

#include<iostream>
#define MAXN 10000
using namespace std;

int n,high[MAXN],wid[MAXN],buf[MAXN];

int lis()
{
	memset(buf,0,sizeof(buf));
	int ans=wid[0];
	for(int i=0;i<n;++i)
	{
		buf[i]=wid[i];
		for(int j=i-1;j>=0;--j)
			if(high[i]>high[j])
				buf[i]=max(buf[i],buf[j]+wid[i]);
		ans=max(ans,buf[i]);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",high+i);
		for(int i=0;i<n;++i)
			scanf("%d",wid+i);
		int ic=lis();
		for(int i=0;i<n/2;++i)
		{
			swap(high[i],high[n-1-i]);
			swap(wid[i],wid[n-1-i]);
		}
		int dc=lis();
		if(ic>=dc)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",cas,ic,dc);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",cas,dc,ic);
	}

	return 0;
}
