/*
11452 - Dancing the Cheeky-Cheeky

kmp...
预处理字符串...
然后滚动输出最后一个周期即可...
*/

#include<iostream>
#define MAXN 2010
using namespace std;

int fa[MAXN];
char s[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",s);
		fa[0]=-1;
		int p=-1,l=strlen(s);
		for(int i=1;i<l;++i)
		{
			while(p>=0 && s[i]!=s[p+1])
				p=fa[p];
			if(s[i]==s[p+1])
				++p;
			fa[i]=p;
		}

		int tot=8;
		while(tot)
		{
			p=fa[l-1]+1;
			while(tot && p<l)
				putchar(s[p++]),--tot;
		}
		puts("...");
	}

	return 0;
}
