/*
11661 - Burger Time?

greedy...
找出R,D的位置,相减,取值的最小即可
*/

#include<iostream>
#define MAXN 2000010
using namespace std;

char s[MAXN];
int l;

int calc()
{
	int pos_r=-1,pos_d=-1,key=MAXN;
	for(int i=0;i<l;++i)
	{
		if(s[i]=='Z')
			return 0;
		else if(s[i]=='R')
			pos_r=i;
		else if(s[i]=='D')
			pos_d=i;
		if(pos_r!=-1 && pos_d!=-1)
			key=min(key,abs(pos_r-pos_d));
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&l)!=EOF && l)
	{
		scanf("%s",s);
		printf("%d\n",calc());
	}

	return 0;
}
