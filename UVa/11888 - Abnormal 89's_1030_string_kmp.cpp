/*
11888 - Abnormal 89's

string...

Original="123...321abc...cba" is alindrome

we revers the string to
	Rev="abc...cba123...321"
and double the string to
	Key="123...321abc...cba123...321abc...cba"
	 -> SubKey="#23...321abc...cba123...321abc...cb#"

we found that Rev is a substring of SubKey
use KMP algorithm to check this statement

don't use Key to process, it'll failed in the case below
Original="aba"
Rev="aba"
Key="abaaba" which is "palindrome" not "alindrome"
*/

#include<iostream>
#define MAXN 200003
using namespace std;

char s[MAXN],buf[MAXN*2];
int fa[MAXN],l;
bool palindrome;

bool init()
{
	fa[0]=-1;
	int p=-1;
	for(l=1;s[l];++l)
	{
		while(p!=-1 && s[ p+1 ]!=s[l])
			p=fa[p];
		if(s[p+1]==s[l])
			++p;
		fa[l]=p;
	}

	bool ok=true;
	for(int i=0;i<l;++i)
	{
		buf[l-1-i]=buf[2*l-1-i]=s[i];
		if(s[i]!=s[l-1-i])
			ok=false;
	}
	buf[l*2]=0;

	return ok;
}

const char key[][100]={
	"alindrome",
	"palindrome",
	"simple"
};

bool kmp()
{
	int p=-1,tl=l*2-1;
	for(int i=1;i<tl;++i)
	{
		while(p!=-1 && s[p+1]!=buf[i])
			p=fa[p];
		if(s[p+1]==buf[i])
			++p;
		if(p==l-1)
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);gets(s);
	while(dataset--)
	{
		gets(s);
		if(!s[0])
		{
			puts(key[0]);
			continue;
		}

		palindrome=init();

		if(kmp())
			puts(key[0]);
		else if(palindrome)
			puts(key[1]);
		else
			puts(key[2]);
	}

	return 0;
}
