/*
 * 11877 - The Coco-Cola Store
 *
 * Ad hoc
 *
 * while N > 2, we can got N/3 Coco-Cola and remain N/3 + N%3 bottles
 * if final N==2, we can got one more Coco-Cola
 *      because of borrow an empty bottle from others
 */

#include<cstdio>
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
		while(n>2)
		{
			key+=n/3;
			n=n/3+n%3;
		}
		if(n==2)
			++key;
		printf("%d\n",key);
	}

	return 0;
}

