/*
 * 10375 - Choose and divide
 *
 * math...
 * 公式变形后,该化简的化简,
 * 然后开个double,乘乘除除就好了
 *
 * happy coding~
 */

#include<iostream>
#include<cstdio>
#define MAXN 20003
using namespace std;

int a[MAXN],b[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int p,q,r,s; scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF; )
	{
		int n1=0, n2=0;
		for(int i=p-q+1;i<=p;++i)
			a[n1++]=i;
		for(int i=r-s+1;i<=r;++i)
			b[n2++]=i;
		if(s>q)
		{
			for(int i=q+1;i<=s;++i)
				a[n1++]=i;
		}
		else
		{
			for(int i=s+1;i<=q;++i)
				b[n2++]=i;
		}

		double key=1;
		int d=min(n1,n2);
		for(int i=0;i<d;++i)
			key=key*a[i]/b[i];
		if(n1>n2)
		{
			for(int i=d;i<n1;++i)
				key*=a[i];
		}
		else for(int i=d;i<n2; ++i)
			key/=b[i];

		printf("%.5lf\n", key);
	}

	return 0;
}
