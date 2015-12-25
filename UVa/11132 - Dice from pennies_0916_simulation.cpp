/*
11132 - Dice from pennies

simulation...
just do as the problem description...
*/

#include<iostream>
#define MAXN 1003
using namespace std;

int log2(int var)
{
	int key=0;
	for(;var>0;var/=2,++key)
		;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	char dice[MAXN];
	int n,c;
	while(scanf("%d%*c%d",&n,&c)!=EOF && (n||c))
	{
		scanf("%s",dice);
		int l=strlen(dice),jump=log2(c-1),key=0;
		for(int i=0;i+jump<=l && n;i+=jump)
		{
			int var=0;
			for(int j=i;j<i+jump;++j)
				var=var*2+(dice[j]=='T'?1:0);
			if(var<c)
			{
				--n;
				key+=var+1;
			}
		}

		printf("%d\n",n?-1:key);
	}

	return 0;
}
