/*
11716 - Digital Fortress

string...
*/

#include<iostream>
#include<cmath>
#define MAXN 10010
using namespace std;

char s[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	gets(s);
	while(dataset--)
	{
		gets(s);
		int l=strlen(s),t=sqrt(l+0.0);
		if(t*t!=l)
			puts("INVALID");
		else
		{
			for(int i=0;i<t;++i)
				for(int j=0;j<t;++j)
					putchar(s[i+j*t]);
			putchar('\n');
		}
	}

	return 0;
}
