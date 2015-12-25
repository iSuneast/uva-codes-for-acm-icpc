/*
11058 - Encoding

Ad hoc...
simulation...
just character replace
no trick
*/

#include<iostream>
#define MAXN 103
using namespace std;

char s[MAXN],h[128],buf[3],bgn[3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int cas=1;
	while(scanf("%s",s)!=EOF)
	{
		int l=strlen(s),r,p,cur=0;

		for(int i='a';i<='z';++i)
		{
			scanf("%s",buf);
			h[i]=buf[0];
		}

		scanf("%d",&r);

		while(r--)
		{
			scanf("%d%s%s",&p,bgn,buf);
			while(cur<p)
			{
				s[cur]=h[ s[cur] ];
				++cur;
			}
			h[ bgn[0] ]=buf[0];
		}

		while(cur<l)
		{
			s[cur]=h[ s[cur] ];
			++cur;
		}

		printf("Case #%d: The encoding string is %s.\n\n",cas++,s);
	}

	return 0;
}
