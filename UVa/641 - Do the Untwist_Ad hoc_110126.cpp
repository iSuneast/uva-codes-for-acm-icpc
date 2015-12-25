/*
641 - Do the Untwist

Ad hoc...
a simple problem...
just do as the problem description

happy coding...
*/

#include<iostream>
#define MAXN 77
using namespace std;

int h(char c)
{
	if(c=='.')
		return 27;
	else if(c=='_')
		return 0;
	else
		return c-'a'+1;
}

char anti_h(int t)
{
	t=(t+28)%28;
	if(t==0)
		return '_';
	else if(t==27)
		return '.';
	else
		return 'a'+t-1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int k;
	char s[MAXN],key[MAXN];
	while(scanf("%d%s",&k,s)!=EOF && k)
	{
		int l=strlen(s);
		for(int i=0;i<l;++i)
		{
			key[ (k*i)%l ] = anti_h( h(s[i])+i );
		}
		key[l]=0;
		puts(key);
	}

	return 0;
}
