/*
10293 - Word Length and Frequency

strings...
Ad hoc...
简单题果然卡人啊...
Orz..
*/

#include<iostream>
#define MAXN 35
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	char c;
	while(scanf("%c",&c)!=EOF)
	{
		int hash[MAXN]={0},cnt=0,i,j;
		if(isalpha(c))
			++cnt;
		while(scanf("%c",&c)!=EOF && c!='#')
		{
			if(isalpha(c))
				++cnt;
			else if(c=='-')
			{
				while(scanf("%c",&c)!=EOF && !isalpha(c))
					;
				++cnt;
			}
			else if(c=='\'')
				continue;
			else if(cnt)
			{
				hash[cnt]++;
				cnt=0;
			}
		}
		i=MAXN-1;
		while(i && !hash[i])
			--i;
		if(!i)
			continue;
		for(j=1;j<=i;++j)
			if(hash[j])
				printf("%d %d\n",j,hash[j]);
		putchar('\n');
	}

	return 0;
}
