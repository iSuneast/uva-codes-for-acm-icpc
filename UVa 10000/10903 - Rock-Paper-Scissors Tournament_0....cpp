/*
10903 - Rock-Paper-Scissors Tournament

simulation...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int win[MAXN],lose[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,k,p1,p2;
	char state1[10],state2[10];
	bool first=true;
	while(scanf("%d",&n)!=EOF && n)
	{
		if(!first)
			putchar('\n');
		first=false;
		scanf("%d",&k);
		k=k*n*(n-1)/2;
		memset(win,0,sizeof(win));
		memset(lose,0,sizeof(lose));
		while(k--)
		{
			scanf("%d%s%d%s",&p1,state1,&p2,state2);
			if(state1[0]=='r')
			{
				if(state2[0]=='s')
				{
					++win[p1];
					++lose[p2];
				}
				else if(state2[0]=='p')
				{
					++win[p2];
					++lose[p1];
				}
			}
			else if(state1[0]=='s')
			{
				if(state2[0]=='p')
				{
					++win[p1];
					++lose[p2];
				}
				else if(state2[0]=='r')
				{
					++win[p2];
					++lose[p1];
				}
			}
			else if(state1[0]=='p')
			{
				if(state2[0]=='r')
				{
					++win[p1];
					++lose[p2];
				}
				else if(state2[0]=='s')
				{
					++win[p2];
					++lose[p1];
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(win[i]==lose[i])
				puts("-");
			else
				printf("%.3lf\n",win[i]/(double(win[i]+lose[i])));
		}
	}

	return 0;
}
