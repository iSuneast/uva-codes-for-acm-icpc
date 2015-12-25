/*
865 - Substitution Cypher

Ad hoc...
isn't a simple problem?
keep getting WA?
have you ever considered about the exist of empty line 
for the substitution alphabet && plaintext alphabet?
*/

#include<iostream>
#define MAXN 128
using namespace std;

char h[MAXN],buf[MAXN],s1[MAXN],s2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	gets(buf);	gets(buf);

	while(dataset--)
	{
		gets(s1);
		gets(s2);
		puts(s2);
		puts(s1);
		memset(h,0,sizeof(h));
		for(int i=0;s1[i] && s2[i];++i)
			h[ s1[i] ]=s2[i];

		while(gets(buf) && buf[0])
		{
			for(int i=0;buf[i];++i)
				if(h[ buf[i] ])
					buf[i]=h[ buf[i] ];
			puts(buf);
		}

		if(dataset)
			putchar(10);
	}

	return 0;
}
