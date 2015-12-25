/*
153 - Permalex

Ad hoc...
permutation...
算某个全排列的位置...
不能直接枚举...

计算出某个序列前面的排列数+1就是答案了
*/

#include<iostream>
#include<vector>
#define MAXN 33
using namespace std;

char s[MAXN],cnt[128];
vector<int> vi,t1,t2;
int sum;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int calc()
{
	t1.clear(),t2.clear();
	for(char i='a';i<='z';++i)
		if(cnt[i])
		{
			int t=cnt[i];
			for(int j=2;j<=t;++j)
				t2.push_back(j);
			while(t--)
				t1.push_back(--sum);
		}

	int sz1=t1.size(),sz2=t2.size();
	for(int i=0;i<sz1;++i)
		for(int j=0;j<sz2;++j)
		{
			int t=gcd(t1[i],t2[j]);
			t1[i]/=t,t2[j]/=t;
		}

	int key=1;
	for(int i=0;i<sz1;++i)
		key*=t1[i];

	return key;
}

int dfs(int l)
{
	int tot=0;
	for(int cur=0;cur<l;++cur)
	{
		vi.clear();
		for(char i='a';i<s[cur];++i)
			if(cnt[i])
			{
				sum=l-cur;
				--cnt[i];
				tot+=calc();
				++cnt[i];
			}

		--cnt[ s[cur] ];
	}

	return tot;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%s",s)!=EOF && strcmp(s,"#"))
	{
		memset(cnt,0,sizeof(cnt));
		int l=0;
		while(s[l])
			++cnt[ s[l++] ];

		printf("%10d\n",dfs(l)+1);
	}

	return 0;
}
