/*
11577 - Letter Frequency

Ad hoc..
算字母出现次数最多的词频...
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,h[128];
	char buf[210];
	scanf("%d",&dataset);	gets(buf);
	while(dataset--)
	{
		gets(buf);
		memset(h,0,sizeof(h));
		int p=0,m=0;
		while(buf[p])
		{
			if(isalpha(buf[p]))
				m=max(m,++h[ tolower(buf[p])]);
			++p;
		}

		for(char i='a';i<='z';++i)
			if(h[i]==m)
				putchar(i);
		putchar(10);
	}

	return 0;
}
