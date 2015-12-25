/*
494 - Kindergarten Counting Game
*/

#include<iostream>
#include<ctype.h>
#include<string>

using namespace std;

int main()
{
	char s[1000];
	int i,cnt,flag;
	while(gets(s))
	{
		cnt=0;
		flag=1;
		for(i=0;i<strlen(s);i++)
			if(isalpha(s[i]))
			{
				if(flag)
					cnt++,flag=0;
			}
			else
				flag=1;
		cout<<cnt<<endl;
	}

return 0;
}