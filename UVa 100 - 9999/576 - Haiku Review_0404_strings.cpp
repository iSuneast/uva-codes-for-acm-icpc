/*
576 - Haiku Review

字符串的水题...
*/

#include<iostream>
using namespace std;
char hash[100];

bool chk(char *s,int cnt)
{
	bool next;
	next=true;
	while(*s)
	{
		if(hash[*s] && next)
		{
			--cnt;
			next=false;
		}
		else if(!hash[*s])		//要判断当前是不是元音,不是则置next为true;
			next=true;
		++s;
	}
	return cnt==0;
}

int main()
{
//	freopen("in.txt","r",stdin);

	hash['a']=hash['e']=hash['i']=hash['o']=hash['u']=hash['y']=1;
	char str[1000];

	while(gets(str) && strcmp(str,"e/o/i"))
	{
		int l=strlen(str),key=0;
		char *token=strtok(str,"/");
		if(!chk(token,5))
		{
			puts("1");
			continue;
		}
		token=strtok(NULL,"/");
		if(!chk(token,7))
		{
			puts("2");
			continue;
		}
		token=strtok(NULL,"/");
		if(!chk(token,5))
		{
			puts("3");
			continue;
		}
		puts("Y");
	}

	return 0;
}
