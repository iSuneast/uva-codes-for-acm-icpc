/*
11108 - Tautology

brute force...
表达式一定合法...
注意到
题目给的表达式其实是一个表达式的前序表示...
所以只要模拟递归就可以了..
*/

#include<iostream>
#include<string>
#define MAXN 128
using namespace std;

bool hash[MAXN],good[MAXN];
string s,buf;
int l;

void init()
{
	good['p']=true;
	good['q']=true;
	good['r']=true;
	good['s']=true;
	good['t']=true;
	good['K']=true;
	good['A']=true;
	good['N']=true;
	good['C']=true;
	good['E']=true;
}

bool chk(int p,int end)
{
	if(s[p]=='N')
		return !chk(p+1,end);
	else if(islower(s[p]))
		return hash[ s[p] ];
	else
	{
		int more=1;
		for(int i=p+1;i<end;++i)
		{
			if(islower(s[i]))
				--more;
			else if(s[i]!='N')
				more+=1;
			if(!more)
			{
				if(s[p]=='K')
					return (chk(p+1,i+1)==true && chk(i+1,end)==true);
				else if(s[p]=='A')
					return (chk(p+1,i+1)==true || chk(i+1,end)==true);
				else if(s[p]=='C')
					return !(chk(p+1,i+1)==true && chk(i+1,end)==false);
				else if(s[p]=='E')
					return (chk(p+1,i+1)==chk(i+1,end));
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(getline(cin,s) && s!="0")
	{
		l=s.length();
		memset(hash,0,sizeof(hash));

		buf="";
		for(int i=0;i<l;++i)
			if(good[ s[i] ])
				buf+=s[i];

		s=buf;
		l=s.length();
		buf="";

		int len=0;
		for(int i=0;i<l;++i)
			if(islower(s[i]) && !hash[ s[i] ])
			{
				hash[ s[i] ]=true;
				buf+=s[i];
				++len;
			}
		bool got=true;
		for(int i=0;i<(1<<len) && got;++i)
		{
			for(int j=0;j<len;++j)
				if(i&(1<<j))
					hash[ buf[j] ]=true;
				else
					hash[ buf[j] ]=false;
			if(!chk(0,l))
				got=false;
		}

		if(got)
			puts("tautology");
		else
			puts("not");
	}

	return 0;
}
