/*
301 - Transportation

brute force...
无语...
位压缩的暴力复杂度O(2^n*n)超时了...
直接暴力回溯竟然可以过...
神奇...
*/

#include<iostream>
#define MAXN 10
using namespace std;

int cap,stations,orders,cnt[MAXN];
int od[25][3],key,money;

void dfs(int cur)
{
	if(cur==orders)
		return ;

	bool ok=true;
	for(int i=od[cur][0];i<od[cur][1] && ok;++i)
		if(cnt[i]+od[cur][2]>cap)
			ok=false;
	
	if(ok)
	{
		money+=(od[cur][1]-od[cur][0])*od[cur][2];
		key=max(money,key);
		for(int i=od[cur][0];i<od[cur][1] && ok;++i)
			cnt[i]+=od[cur][2];

		dfs(cur+1);

		money-=(od[cur][1]-od[cur][0])*od[cur][2];
		for(int i=od[cur][0];i<od[cur][1] && ok;++i)
			cnt[i]-=od[cur][2];
	}

	dfs(cur+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d%d",&cap,&stations,&orders)!=EOF && (cap||stations||orders))
	{
		for(int i=0;i<orders;++i)
			for(int j=0;j<3;++j)
				scanf("%d",&od[i][j]);

		key=0;
		memset(cnt,0,sizeof(cnt));
		dfs(0);

		printf("%d\n",key);
	}

	return 0;
}
