/*
11774 - Doom's Day

math...
奇强的yy能力是解决此题的关键...
*/

#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",cas,(a+b)/gcd(a,b));
	}

	return 0;
}
