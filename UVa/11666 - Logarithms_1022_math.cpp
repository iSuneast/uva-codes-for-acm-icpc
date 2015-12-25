/*
11666 - Logarithms

math...

ln(n)=L+ln(1-x)
so exp(L)=n/(1-x)
x=1-n/exp(L), noticed that |x|<1.0

L could be floor( log(n) ) ,if |x|<1.0
else L should be ceil( log(n) )

solved...
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int l=floor(log(n+0.0));
		double x=1-n/exp(l+0.0);

		if(fabs(x)<1.0)
			printf("%d %.8lf\n", l, x);
		else
			printf("%d %.8lf\n", l+1, 1-n/exp(l+1.0));
	}

	return 0;}