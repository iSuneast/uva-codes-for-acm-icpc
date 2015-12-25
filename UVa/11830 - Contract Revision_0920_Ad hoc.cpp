/*
11830 - Contract Revision

Ad hoc...
Oh~ my god...
I even track in this kind of problem...
I am no longer Suneast?
*/

#include<iostream>
#define MAXN 103
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	char s[MAXN],buf[MAXN];
	int d;
	while(scanf("%d%s",&d,s)!=EOF && d)
	{
		int l=0;
		for(int i=0;s[i];++i)		//i<s[i]...   are u kidding?
		{
			if(s[i]-'0'!=d)
			{
				if(!l && s[i]=='0')
					continue;
				buf[l++]=s[i];
			}
		}

		if(!l)
			puts("0");
		else
		{
			buf[l]=0;
			puts(buf);
		}
	}

	return 0;
}
