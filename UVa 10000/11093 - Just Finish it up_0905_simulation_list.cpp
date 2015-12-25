/*
11093 - Just Finish it up

simulation...
use double-link-list to simulate the operation
you'll get an O(n) solution...

1) read p,q, the gas of position[i] should be t=p-q
2) while(t<0) del(i) from list, scan from current to pre
	modify t with the pre var
3) the first undelete node of the list is the answer
*/

#include<iostream>
#define MAXN 100003
using namespace std;

struct JUST
{
	int var,pos;
	bool flag;
	JUST *next,*pre;
}just[MAXN];

void del(JUST *cur)
{
	cur->pre->next=cur->next;
	cur->next->pre=cur->pre;
	cur->flag=true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int n,t,tot=0;

		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&just[i].var);
			just[i].pos=i;
			just[i].flag=false;
			just[i].pre=&just[i-1];
			just[i].next=&just[i+1];
		}
		just[1].pre=&just[n];
		just[n].next=&just[1];

		for(int i=1;i<=n;++i)
		{
			scanf("%d",&t);
			just[i].var-=t;
			tot+=just[i].var;
		}

		if(tot<0)
			printf("Case %d: Not possible\n",cas);
		else
		{
			for(int i=1;i<=n;++i)
			{
				if(!just[i].flag && just[i].var<0)
				{
					del(&just[i]);
					t=just[i].var;
					JUST *cur=just[i].pre;
					while(true)
					{
						cur->var+=t;
						if(cur->var<0)
						{
							del(cur);
							t=cur->var;
							cur=cur->pre;
						}
						else
							break;
					}
				}
			}

			for(int i=1;i<=n;++i)
			{
				if(!just[i].flag)
				{
					printf("Case %d: Possible from station %d\n",cas,i);
					break;
				}
			}
		}
	}

	return 0;
}
