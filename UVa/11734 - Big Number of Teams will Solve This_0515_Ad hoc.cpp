/*
11734 - Big Number of Teams will Solve This

Ad hoc...
*/

#include<iostream>
#define MAXN 25
using namespace std;

char s1[MAXN],s2[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	gets(s1);
	for(int cas=1;cas<=dataset;++cas)
	{
		gets(s1);
		int l=strlen(s1),p=0;
		for(int i=0;i<l;++i)
			if(s1[i]!=' ')
				s1[p++]=s1[i];
		s1[p]=0;
		gets(s2);
		printf("Case %d: ",cas);
		if(strcmp(s1,s2))
			puts("Wrong Answer");
		else if(p!=l)
			puts("Output Format Error");
		else
			puts("Yes");
	}

	return 0;
}
