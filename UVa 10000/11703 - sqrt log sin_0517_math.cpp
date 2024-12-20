/*
11703 - sqrt log sin

math...
brute force...
*/

#include<iostream>
#include<cmath>
#define MAXN 1000000
using namespace std;

int key[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	key[0]=1;
	for(int i=1;i<=MAXN;++i)
	{
		key[i]=key[int(i-sqrt(i+0.0))]+key[int(log(i+0.0))]+key[int(i*(sin(i+0.0)*sin(i+0.0)))];
		key[i]%=MAXN;
	}
	int n;
	while(scanf("%d",&n)!=EOF && n>=0)
		printf("%d\n",key[n]);

	return 0;
}
