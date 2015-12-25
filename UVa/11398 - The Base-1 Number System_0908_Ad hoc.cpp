/*
11398 - The Base-1 Number System

Ad hoc...
just do as the problem description...
no trick..
*/

#include<iostream>
#define MAXN 36
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	char s[MAXN];
	int l,ans;
	bool flag;

	while(scanf("%s",s)!=EOF && s[0]!='~')
	{
		ans=0;
		do
		{
			l=strlen(s);
			if(l==1)
				flag=true;
			else if(l==2)
				flag=false;
			else
			{
				l-=2;
				while(l--)
					ans=ans*2+(flag?1:0);
			}
		}while(scanf("%s",s)!=EOF && s[0]!='#');

		printf("%d\n",ans);
	}

	return 0;
}
