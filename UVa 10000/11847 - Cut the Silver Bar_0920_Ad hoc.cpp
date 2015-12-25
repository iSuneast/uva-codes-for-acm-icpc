/*
11847 - Cut the Silver Bar

Ad hoc...
just calc the bitLength of n
the answer is bitLength-1
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int key=0;
		while(n)
		{
			++key;
			n/=2;
		}
		printf("%d\n",key-1);
	}

	return 0;
}
