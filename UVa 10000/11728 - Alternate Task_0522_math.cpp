/*
11728 - Alternate Task

math...
暴力O(n^2)打表输出即可

一个数的因子之和一定大于等于这个数本身
factors(n)=1+...+n
所以只需要打表到1000就可以了
*/

#include<iostream>
#define MAXN 1000
using namespace std;

int key[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(key,-1,sizeof(key));
	key[1]=1;
	for(int i=2;i<=MAXN;++i)
	{
		int t=0;
		for(int j=1;j<=i;++j)
			if(i%j==0)
				t+=j;
		if(t<=MAXN)
			key[t]=i;
	}
	int n,cas=1;
	while(scanf("%d",&n)!=EOF && n)
		printf("Case %d: %d\n",cas++,key[n]);

	return 0;
}
