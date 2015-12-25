/*
10298 - Power Strings

KMP...
杯具啊...
数组开得小了竟然给我WA...

终于理解kmp怎么回事了...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

char s[MAXN];
int fa[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(gets(s) && strcmp(s,"."))
	{
		fa[0]=-1;
		int p=-1,l;

		for(l=1;s[l];++l)
		{
			while(p>=0 && s[p+1]!=s[l])
				p=fa[p];
			if(s[p+1]==s[l])
				++p;
			fa[l]=p;
		}

		if( l%(l-1-fa[l-1])==0 )
			printf("%d\n",l/(l-1-fa[l-1]));
		else
			puts("1");
	}

	return 0;
}
