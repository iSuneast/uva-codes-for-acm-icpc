/*
11628 - Another lottery

Ad hoc...

s=sum(data[i][m]),1<=i<=n
the answer is
data[i][m]/gcd(data[i][m],s) " / " s/gcd(data[i][m],s)
*/

#include<iostream>
#define MAXN 10003
using namespace std;

int n,m,var[MAXN];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		int s=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				scanf("%d",&var[i]);
			s+=var[i];
		}
		for(int i=0;i<n;++i)
		{
			int t=gcd(var[i],s);
			printf("%d / %d\n",var[i]/t,s/t);
		}
	}

	return 0;
}
