/*
 * 10326 - The Polynomial Equation
 *
 * Ad hoc...
 *
 * ����~
 * n = 0��ʱ����� "+ 0 = 0"
 * �������,����Ŀ������������
 * ע��߽����
 * key[] = 0��1ʱҪע�����
 *
 * ���ʽ,���㲻��O(2^n)�ĸ��Ӷ�(��Ȼ��֮ǰ����ô��Ϊ��)
 * ����, n = 3�����:
 * x^      0        1          2           3
 *         1
 *         1       a1
 *         1      a1+a2       a1*a2
 *         1     a1+a2+a3  a1*a3+a2*a3   a1*a2*a3
 * �Ѿ����Ժ����Եÿ���, ֻҪO(n^2)�ĵ��ƾͿ�����...
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
