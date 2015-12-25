/*
 * 10202 - Pairsumonious Numbers
 *
 * greedy...
 * 非常牛逼的做法
 * 令m为最小的sum,则,
 *   @ m<0 , ans[0] 最小为m
 *   @ 否则, ans[0] 最小为0
 *   ans[0] 最大为m/2
 *
 * 只需枚举ans[0]的值,就可以递推出所有其他解
 * 把sum保存到一个集合set
 *
 * ans[1] = set里面最小值-ans[0]
 * 删除 set里面的 ans[0] + ans[1]
 *
 * ans[2] = set里面最小值-ans[0]
 * 删除 set里面的 ans[0] + ans[2], ans[1]+ans[2]
 * ...
 * (仔细想象,上面的方法还是很显然的)
 *
 * 以此类推,如果能通过如上方法推得所有ans[],则ans[]即为可行解
 * 否则无解
 */

#include<cstdio>
#include<map>
#define MAXN 50
using namespace std;

int s[MAXN], n, tot, key[MAXN];

bool process()
{
	map<int,int> mii;
	for(int i=0;i<tot;++i)
	{
		if( mii.find(s[i]) == mii.end() )
			mii[ s[i] ]=1;
		else
			++mii[ s[i] ];
	}

	for(int i=1;i<n;++i)
	{
		key[i]=mii.begin()->first-key[0];
		for(int j=0;j<i;++j)
		{
			int t= key[i]+key[j];
			if(mii.find(t)==mii.end())
				return false;
			if(mii[t]==1)
				mii.erase(t);
			else
				mii[t]--;
		}
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		tot = n*(n-1)/2;
		int m=1e9;
		for(int i=0; i<tot; ++i)
		{
			scanf("%d", s+i);
			m=min(m, s[i]);
		}

		bool got=false;
		for(int l= (m<0)?m:0, u=s[0]/2; l<=u; ++l)
		{
			key[0]=l;
			if(process())
			{
				for(int i=0;i+1<n;++i)
					printf("%d ",key[i]);
				printf("%d\n",key[n-1]);
				got=true;
				break;
			}
		}

		if(!got)
			puts("Impossible");
	}

	return 0;
}
