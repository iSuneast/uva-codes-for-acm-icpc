/*
458 - The Decoder

simple
*/

#include<iostream>

using namespace std;

int main()
{
	char s[1000];
	int i;
	while(gets(s))
	{
		for(i=0;i<strlen(s);i++)
		putchar(s[i]-7);
		putchar('\n');
	}

return 0;
}