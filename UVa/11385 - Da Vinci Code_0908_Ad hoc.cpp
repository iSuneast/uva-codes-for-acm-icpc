/*
11385 - Da Vinci Code

Ad hoc...
not a hard problem, but with so many tricks..
*
* Note that only uppercase letters conveys the message; 
* other characters are simply garbage.
*
but if there are more than n upper-case letter,
we should only process first n.
*/

#include<iostream>
#include<algorithm>
#define MAXN 103
#define FIB 50
using namespace std;

long long fib[FIB];
char s[MAXN],key[FIB];
int h[FIB];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	fib[0]=fib[1]=1;
	for(int i=2;i<FIB;++i)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}

	int dataset,n,f;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		int end=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&f);
			h[i]=lower_bound(fib+1,fib+FIB,f)-fib;
			end=max(end,h[i]+1);
		}

		for(int i=0;i<end;++i)
		{
			key[i]=' ';
		}
		key[end]=0;

		gets(s);	gets(s);
		int p=1;
		for(int i=0;s[i] && p<=n;++i)
		{
			if(isupper(s[i]))
				key[ h[p++] ]=s[i];
		}

		puts(key+1);
	}

	return 0;
}
