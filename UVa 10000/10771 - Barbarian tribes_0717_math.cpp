/*
10771 - Barbarian tribes

math...
本来以为是模拟题的...

In every two sacrifices, there are three possible cases:
1. 1 G and 1 K are sacrificed, 1 K is placed.
2. 2 G are sacrificed, 1 G is placed.
3. 2 K are sacrificed, 1 G is placed.
In any case, the parity of K doesn't change.
So the initial parity of K is the same as the final parity of K.

竟然是博弈题,而且只和奇偶性有关...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF && (n||m||k))
	{
		if(m&1)
			puts("Keka");
		else
			puts("Gared");
	}

	return 0;
}
