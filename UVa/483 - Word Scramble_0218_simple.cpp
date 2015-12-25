/*
483 - Word Scramble

simple
*/

#include<iostream>

using namespace std;

char s[1000000],buf[1000000];

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j;
	while(gets(s))
	{
		i=0;
		while(s[i])
		{
			j=0;
			do
			buf[j++]=s[i++];
			while(s[i] && s[i]!=' ');
			while(j)
				cout<<buf[--j];
			while(s[i] && s[i]==' ')
				cout<<s[i++];
		}
		cout<<endl;
	}

return 0;
}
