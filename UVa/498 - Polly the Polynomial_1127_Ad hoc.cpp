/*
498 - Polly the Polynomial

Ad hoc...
a simple problem...
use QingJiuShao format to solve it...
*/

#include<iostream>
#define MAXN 1000
using namespace std;

int c[MAXN],x;
char buf[100000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(gets(buf))
	{
		int n=0;
		for(char *token=strtok(buf," ");token;token=strtok(NULL," "))
			sscanf(token,"%d",&c[n++]);
		gets(buf);
		bool first=true;
		for(char *token=strtok(buf," ");token;token=strtok(NULL," "))
		{
			if(!first)
				putchar(' ');
			first=false;
			sscanf(token,"%d",&x);
			int key=c[0];
			for(int i=1;i<n;++i)
				key=key*x+c[i];
			printf("%d",key);
		}
		putchar(10);
	}

	return 0;
}
