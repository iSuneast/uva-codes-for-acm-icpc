/*
10784 - Diagonal

geometry...
*/

#include<iostream>
#define MAXN 50000000
using namespace std;

long long var[MAXN];

long long b_locate(long long key)
{
	long long start=4,end=MAXN-1,mid=(start+end)>>1;
	while(start<end)
	{
		if(key==var[mid])
			return mid;
		else if(key<var[mid])
		{
			if(end==mid)
				return mid+1;
			end=mid;
		}
		else
		{
			if(start==mid)
				return mid+1;
			start=mid;
		}
		mid=(start+end)>>1;
	}
	return mid;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long i,cas=1;
	for(i=4;i<MAXN;++i)
		var[i]=i*(i-3)/2;
	while(scanf("%lld",&i)!=EOF && i)
		cout<<"Case "<<cas++<<": "<<b_locate(i)<<endl;

	return 0;
}
