/*
11854 - Egypt

Ad hoc...
sort this three integer
check whether a^2+b^2==c^2
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	long long a[3];
	while(scanf("%lld%lld%lld",&a[0],&a[1],&a[2]) && (a[0]||a[1]||a[2]))
	{
		sort(a,a+3);
		puts(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]?"right":"wrong");
	}

	return 0;
}
