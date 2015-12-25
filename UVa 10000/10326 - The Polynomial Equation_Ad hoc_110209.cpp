/*
 * 10326 - The Polynomial Equation
 *
 * Ad hoc...
 *
 * 杂题~
 * n = 0的时候输出 "+ 0 = 0"
 * 其它情况,按题目描述的做即可
 * 注意边界情况
 * key[] = 0与1时要注意输出
 *
 * 表达式,计算不是O(2^n)的复杂度(虽然我之前是这么认为的)
 * 例如, n = 3的情况:
 * x^      0        1          2           3
 *         1
 *         1       a1
 *         1      a1+a2       a1*a2
 *         1     a1+a2+a3  a1*a3+a2*a3   a1*a2*a3
 * 已经可以很明显得看到, 只要O(n^2)的递推就可以了...
 *
 * happy coding~
 */

#include<iostream>
#include<cstdio>
#define MAXN 54
using namespace std;
typedef long long LL;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	LL a[MAXN], key[MAXN];
	for(int n; scanf("%d",&n)!=EOF; )
	{
		if(!n)
		{
			puts("+ 0 = 0");
			continue;
		}

		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			a[i]*=-1;
			key[i]=0;
		}
		key[0]=1;

		for(int p=1; p<=n; ++p)
		{
			for(int t=p; t>=1; --t)
			{
				key[t] += a[p]*key[t-1];
			}
		}

		for(int i=0;i*2<n;++i)
		{
			swap(key[i], key[n-i]);
		}

		bool first=true;
		for(int i=n; i>=0; --i)
		{
			if(key[i]==0 && i!=0)
				continue;

			if(!first)
				putchar(' ');

			if(key[i]<0)
			{
				printf("- ");
				key[i]*=-1;
			}
			else if(!first)
				printf("+ ");

			if(key[i]!=1 || i==0)
				printf("%lld",key[i]);

			if(i>1)
				printf("x^%d",i);
			else if(i==1)
				printf("x");

			first=false;
		}
		puts(" = 0");
	}

	return 0;
}
