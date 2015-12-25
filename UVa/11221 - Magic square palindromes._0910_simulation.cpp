/*
11221 - Magic square palindromes.

simulation...
check whether the string length is perfect square
just enum the four string and check whether they are all the same
*/

#include<iostream>
#include<cmath>
#define MAXN 10003
using namespace std;

int l,key;
char s[MAXN],buf[MAXN];

bool chk()
{
	key=sqrt(l+0.0);
	if(key*key!=l)
		return false;

	buf[l]=0;
	for(int i=0;i<l;++i)
		buf[i]=s[l-1-i];
	if(strcmp(buf,s))
		return false;

	int p=0;
	for(int i=0;i<key;++i)
		for(int j=i;j<l;j+=key)
			buf[p++]=s[j];
	if(strcmp(buf,s))
		return false;

	p=0;
	for(int i=l-1;i>=l-key;--i)
		for(int j=i;j>=0;j-=key)
			buf[p++]=s[j];
	if(strcmp(buf,s))
		return false;

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);	gets(s);
	for(int cas=1;cas<=dataset;++cas)
	{
		gets(s);
		int p=strlen(s);
		l=0;
		for(int i=0;i<p;++i)
		{
			if(isalpha(s[i]))
				s[l++]=s[i];
		}
		s[l]=0;

		printf("Case #%d:\n",cas);
		if(chk())
			printf("%d\n",key);
		else
			puts("No magic :(");
	}

	return 0;
}
