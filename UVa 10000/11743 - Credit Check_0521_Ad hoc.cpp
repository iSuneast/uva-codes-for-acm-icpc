/*
11743 - Credit Check

Ad hoc..
*/

#include<iostream>
using namespace std;

int sum(int n)
{
	n*=2;
	return n/10+n%10;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	char s[100];
	scanf("%d",&dataset);	gets(s);
	while(dataset--)
	{
		gets(s);
		bool pos_odd=true;
		int l=strlen(s),odd=0,even=0;
		for(int i=0;i<l;++i)
			if(isdigit(s[i]))
			{
				if(pos_odd)
					odd+=sum(s[i]-'0');
				else
					even+=s[i]-'0';
				pos_odd=!pos_odd;
			}
		if((odd+even)%10)
			puts("Invalid");
		else
			puts("Valid");
	}


	return 0;
}
