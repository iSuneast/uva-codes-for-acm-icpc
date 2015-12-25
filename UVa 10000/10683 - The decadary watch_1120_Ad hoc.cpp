/*
10683 - The decadary watch

Ad hoc...

First time I got WA, but I don't know whether the problem
is cause by the precision
just change my output format from
	static_cast<int>(Time*10/8.64)
to	static_cast<int>(Time*125/108+eps)
and got AC...
*/

#include<iostream>
#define eps 1e-9
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	const int more[]={0,60,60,100};
	char s[20];
	int Time;
	while(scanf("%s",s)!=EOF)
	{
		for(int i=0;i<8;i+=2)
			Time=Time*more[i/2]+(s[i]-'0')*10+s[i+1]-'0';

		printf("%07d\n",static_cast<int>(Time*125/108+eps));
	}

	return 0;
}
