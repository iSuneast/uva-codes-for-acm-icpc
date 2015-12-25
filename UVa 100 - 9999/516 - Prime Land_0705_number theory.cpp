/*
516 - Prime Land

number theory....
数论...
素数筛法...
没有特殊情况...
也不会有大整数情况...
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 32768
using namespace std;

int prime[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cnt=0;
	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
		if(prime[i]==0)
		{
			prime[cnt++]=i;
			for(int j=i+i;j<MAXN;j+=i)
				prime[j]=-1;
		}

	string s;
	while(getline(cin,s) && s!="0")
	{
		stringstream sin(s);
		long long a,b,c=1;
		while(sin>>a>>b)
			while(b--)
				c*=a;
		--c;

		bool first=true;
		for(int i=cnt-1;i>=0;--i)
			if(c%prime[i]==0)
			{
				int tot=0;
				while(c%prime[i]==0)
				{
					++tot;
					c/=prime[i];
				}
				if(!first)
					putchar(' ');
				first=false;
				printf("%d %d",prime[i],tot);
			}
		putchar('\n');
	}

	return 0;
}
