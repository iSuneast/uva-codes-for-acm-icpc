/*
11634 - Generate random numbers

Ad hoc...
直接模拟即可...
*/

#include<iostream>
#define MOD 10000
using namespace std;

int n,key;
bool flag[MOD*10];

void calc(int var)
{
	if(flag[var])
		return ;
	++key;
	flag[var]=true;
	calc(var*var/100%MOD);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		key=0;
		memset(flag,0,sizeof(flag));
		calc(n);
		printf("%d\n",key);
	}

	return 0;
}
