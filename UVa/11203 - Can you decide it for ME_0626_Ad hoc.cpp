/*
11203 - Can you decide it for ME?

Ad hoc...
其实就是给定一个加法表达式
判断等式是否成立...
M是"+",E是"="
*/

#include<iostream>
#include<string>
using namespace std;

string s;
int l;

void chk()
{
	int a=-1,b=-1;
	for(int i=0;i<l;++i)
		if(s[i]=='?')
			continue;
		else if(s[i]=='M' && a==-1)
			a=i;
		else if(s[i]=='E' && b==-1)
			b=i;
		else
		{
			puts("no-theorem");
			return ;
		}
	if(a>b)
	{
		puts("no-theorem");
		return ;
	}
	int x=a,y=b-a-1,z=l-1-b;
	if(!x || !y || x+y!=z)
		puts("no-theorem");
	else
		puts("theorem");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s;
		l=s.length();
		chk();
	}

	return 0;
}
