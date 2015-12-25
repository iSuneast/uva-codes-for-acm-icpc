/*
325 - Identifying Legal Pascal Real Constants

Ad hoc...
有史以来最长的一道水题代码...
无语了...
最近的代码老是越写越长...

WA了好多次...
实践证明...
做水题一定要仔细要认真...
*/

#include<iostream>
using namespace std;
char s[10000];
int len;

bool chk_left(int p,bool more)
{
	if(p==0)
		return false;
	int start=0;
	if(s[start]=='+' || s[start]=='-')
		++start;
	if(s[start]=='.')
		return false;
	int dote=0,digit=0;
	for(;start<p;++start)
	{
		if(isdigit(s[start]))
			++digit;
		else if(s[start]=='.' && !dote)
			dote=1;
		else
			return false;
	}
	if(isdigit(s[p-1]))
	{
		if(more)
			return dote==1;
		return true;
	}
	return false;
}

bool chk_right(int p)
{
	if(s[p]=='+' || s[p]=='-')
		++p;
	if(p>=len)
		return false;
	while(p<len)
	{
		if(isdigit(s[p]))
			++p;
		else
			return false;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("325.txt","w",stdout);
#endif

	while(gets(s) && strcmp(s,"*"))
	{
		len=strlen(s);
		int p=0,start=0,end=len,i;
		while(start<len && s[start]==' ')
			++start;
		while(end>0 && s[end-1]==' ')
			--end;
		bool found=false;
		for(i=0;start<end;++start,++i)
		{
			if(s[start]==' ')
				found=true;
			s[i]=s[start];
		}
		s[i]=0;
		len=i;
		if(found)
		{
			cout<<s<<" is illegal."<<endl;
			continue;
		}
		for(int i=0;i<len;++i)
			if(s[i]!=' ')
				s[p++]=s[i];
		s[p]=0;
		len=p;
		for(int i=0;i<len;++i)
			if(s[i]=='e' || s[i]=='E')
			{
				if(chk_left(i,false) && chk_right(i+1))
					cout<<s<<" is legal."<<endl;
				else
					cout<<s<<" is illegal."<<endl;
				found=true;
				break;
			}
		if(!found)
		{
			if(chk_left(len,true))
				cout<<s<<" is legal."<<endl;
			else
				cout<<s<<" is illegal."<<endl;
		}
	}

	return 0;
}
