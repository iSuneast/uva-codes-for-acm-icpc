/*
11296 - Counting Solutions to an Integral Equation

Ad hoc...
x+2*y+2*z = n
we can find that z is equal to y, so the format becomes
x+2*y=n
when x or y is known, the other is unique
y -> [0,n/2], the solution for y=Num is Num+1
so the total number of solution is 
set k= n/2+1
answer=k*(1+k)/2 (noticed that, answer will overflow using int)
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			puts("0");
		else
		{
			long long key=n/2+1;
			printf("%lld\n",key*(key+1)/2);
		}
	}

	return 0;
}
