/*
11636 - Hello World!

math...
算一下步长就可以了
(1<<m)>=n时,m就是解
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,cas=1;
	while(scanf("%d",&n) && n>=0)
	{
		int key=0,m=1;
		while(n>m)
		{
			m<<=1;
			++key;
		}
		printf("Case %d: %d\n",cas++,key);
	}

	return 0;
}
