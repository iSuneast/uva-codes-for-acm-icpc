/*
 * 11878 - Homework Checker
 *
 * Ad hoc...
 *
 * quite a simple problem
 * No trick...
 * Happy solving : )
 */

#include<algorithm>
#include<cstdio>
#define MAXN
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int a,b,c,key=0;
	char op,res[10];

	while(scanf("%d%c%d%*c%s",&a,&op,&b,res)!=EOF)
	{
		if(res[0]=='?')
			continue;
		c=atoi(res);
		if(op=='+' && a+b==c)
			++key;
		if(op=='-' && a-b==c)
			++key;
	}
	printf("%d\n",key);

	return 0;
}

