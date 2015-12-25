/*
10508 - Word Morphing

Ad hoc...
don't mess up the problem
it's just a simple problem
calculate the different char numbers with the first word
and then just sort them by the differ value 
at last, just output them
*/

#include<iostream>
#define MAXN 3000
using namespace std;

char s[MAXN][MAXN];
int n,m,dif[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		scanf("%s",s[0]);
		for(int i=1;i<n;++i)
		{
			scanf("%s",s[i]);
			dif[i]=0;
			for(int j=0;s[i][j] && s[0][j];++j)
				dif[i]+=(s[i][j]==s[0][j]?0:1);
		}

		puts(s[0]);
		for(int d=1;d<=m;++d)
		{
			for(int i=1;i<n;++i)
				if(dif[i]==d)
				{
					puts(s[i]);
					break;
				}
		}
	}

	return 0;
}
