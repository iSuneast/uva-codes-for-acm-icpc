/*
892 - Finding words

Ad hoc...
认真一点慢慢写就好了~
唯一的trick就是'-'
可以有
Hell-
o-
Wor-
ld
这种情况吧~

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	char c;
	string buf="",s;
	bool rem=false;
	while(getline(cin,s) && s!="#")
	{
		for(int i=0; i<s.length(); ++i)
		{
			c=s[i];
			if(c==' ')
			{
				if(rem)
				{
					cout<<endl<<buf<<endl;
					rem=false;
				}
				else
					cout<<buf;
				buf="";
				putchar(' ');
			}
			else if(isalpha(c))
				buf+=c;
		}

		if(s[ s.length()-1 ]!='-')
		{
			cout<<buf<<endl;
			buf="";
		}
		else
			rem=true;
	}

	return 0;
}
