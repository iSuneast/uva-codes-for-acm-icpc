/*
271 - Simply Syntax

Ad hoc...
stack...
prefix expression...
前缀表达式...
判断表达式是否合法即可...
*/

#include<iostream>
#include<string>
using namespace std;

string s;
char hash[128];

void init()
{
	for(int i='p';i<='z';++i)
		hash[i]=1;		//相当于变量
	hash['N']=2;		//相当与单目运算符
	hash['C']=hash['D']=hash['E']=hash['I']=3;	//相当于双目运算符
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	while(cin>>s)
	{
		int l=s.length(),i,correct=0;
		bool key=true;
		for(i=l-1;i>=0 && key;--i)
			if(hash[s[i]]==1)
				++correct;
			else if(hash[s[i]]==2 && correct>=1)
				continue;
			else if(hash[s[i]]==3 && correct>=2)
				correct--;
			else
				key=false;
		cout<<((key && correct==1)?"YES":"NO")<<endl;
	}

	return 0;
}
