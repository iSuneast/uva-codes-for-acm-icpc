/*
10105 - Polynomial Coefficients

math...
赤裸裸的高中组合数学的知识...
对12!,直接算c(n,r)不会溢出
*/

#include<iostream>
using namespace std;

int c(int a,int b)
{
	int key=1;
	for(int i=0;i<b;++i)
		key*=a-i;
	for(int i=1;i<=b;++i)
		key/=i;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int p,key=1;
		for(int i=0;i<k;++i)
		{
			scanf("%d",&p);
			key*=c(n,p);
			n-=p;
		}
		printf("%d\n",key);
	}

	return 0;
}
