/*
11313 - Gourmet Games

math...
每场有m人参加.
淘汰m-1个人...
总共n个人...
则,若n每次都减去(m-1),最后剩下的值为1..
可知,减得次数就是解...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,n,m;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&m);
		int key=0;
		while(n>=m)
		{
			++key;
			n-=m-1;
		}
		if(n==1)
			printf("%d\n",key);
		else
			puts("cannot do this");
	}

	return 0;
}
