/*
11207 - The easiest way

geometry...
总共就三种情况...
讨论一下就可以了...
1.w>4*h			key=h
----------------------------
|                           |
----------------------------
2.w<4*h			key=w/4
------
|    |
------
3.因为必有w>=h(不满足可以交换w,h)	key=h/2
然后取当前(w,h)最大的key即可
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		double key=0;
		int p,w,h;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&w,&h);
			if(w<h)
				swap(w,h);
			double t=0;
			if(w<=4*h)
				t=w/4.0;
			else
				t=h;
			t=max(t,h/2.0);
			if(t>key)
			{
				key=t;
				p=i;
			}
		}
		printf("%d\n",p);
	}

	return 0;
}
