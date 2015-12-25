/*
402 - M*A*S*H

simulation....
果然还是UVa的数据比较nb...

要注意的就是n==x的情况
此外UVa的题多了无解输出剩余所有人的情况
*/

#include<iostream>
#define MAXN 20
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1,n,card,x;
	bool ppl[55],ans[55];

	while(scanf("%d%d",&n,&x)!=EOF)
	{
		for(int i=1;i<=n;++i)
			ppl[i]=false;
		int tot=n;

		for(int i=0;i<MAXN;++i)
		{
			scanf("%d",&card);
			int p=1,cnt=card;
			while(p<=n)
			{
				card=cnt;
				while(--card && p<=n)
				{
					while(p<=n && ppl[p])
						++p;
					++p;
				}
				while(p<=n && ppl[p])
					++p;
				if(p<=n)
				{
					if(tot==x)
						break;
					--tot;
					ppl[p]=true;
					if(tot==x)
						memcpy(ans,ppl,sizeof(ppl));
				}
			}
		}
		if(tot!=x)
			memcpy(ans,ppl,sizeof(ppl));

		if(n==x)
			memset(ans,0,sizeof(ans));

		printf("Selection #%d\n",cas++);
		bool first=true;
		for(int i=1;i<=n;++i)
			if(!ans[i])
			{
				if(!first)
					putchar(' ');
				first=false;
				printf("%d",i);
			}
		printf("\n\n");
	}

	return 0;
}

