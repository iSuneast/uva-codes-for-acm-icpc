/*
11687 - Digits

Ad hoc...
情况果然有限...
直接讨论就可以了...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

char buf[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%s",buf)!=EOF && buf[0]!='E')
	{
		int l=strlen(buf);
		if(l>=10)
			puts("4");
		else if(l>=2)
			puts("3");
		else if(buf[0]=='1')
			puts("1");
		else
			puts("2");
	}

	return 0;
}
