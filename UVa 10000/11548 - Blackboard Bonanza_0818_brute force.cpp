/*
11548 - Blackboard Bonanza

brute force...
暴力枚举即可...
模拟滚动匹配,取最大值...
o(n^4)复杂度...
之前多写了一重循环...TLE了...
*/

#include<iostream>
#define MAXN 77
using namespace std;

char s[MAXN][MAXN];
int l[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int key=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s",s[i]);
			l[i]=strlen(s[i]);
			for(int j=0;j<i;++j)
			{
				for(int x=0;x<l[j];++x)
				{
					int a=l[i]-1,b=x,cnt=0;
					while(a>=0 && b>=0)
					{
						if(s[i][a]==s[j][b])
							++cnt;
						--a,--b;
					}
					key=max(key,cnt);
				}
				for(int x=l[i]-1;x!=0;--x)
				{
					int a=x,b=l[j]-1,cnt=0;
					while(a>=0 && b>=0)
					{
						if(s[i][a]==s[j][b])
							++cnt;
						--a,--b;
					}
					key=max(key,cnt);
				}
			}
		}

		printf("%d\n",key);
	}

	return 0;
}
