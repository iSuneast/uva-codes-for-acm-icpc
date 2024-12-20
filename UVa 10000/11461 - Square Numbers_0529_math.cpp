/*
11461 - Square Numbers

math...
把平方项打表后.
对a,b进行上下界二分查找后输出区间长度即可
*/

#include<iostream>
#include<algorithm>
#define MAXN 100000
using namespace std;

int key[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cnt=0;
	for(int i=0;i<MAXN;++i)
	{
		int t=i*i;
		if(t<=MAXN)
			key[cnt++]=t;
		else
			break;
	}
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && (a||b))
	{
		if(a>b)
			swap(a,b);
		int low=lower_bound(key,key+cnt,a)-key;
		int up=upper_bound(key,key+cnt,b)-key;
		printf("%d\n",up-low);
	}

	return 0;
}
