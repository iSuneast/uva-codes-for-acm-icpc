/*
11086 - Composite Prime

number theory...
prime...
sieve...
just a normal number theory problem...
count the number of prime factors
if the value is 2, then the number is OK
*/

#include<iostream>
#define MAXN 1048577
using namespace std;

bool flag[MAXN];
int cnt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	flag[0]=flag[1]=true;
	for(int i=2;i<MAXN;++i)
	{
		if(!flag[i])
		{
			flag[i]=true;
			for(int j=i+i;j<MAXN;j+=i)
			{
				flag[j]=true;
				int t=j;
				while(t%i==0 && cnt[j]<3)
				{
					++cnt[j];
					t/=i;
				}
			}
		}
	}

	for(int i=2;i<MAXN;++i)
	{
		if(cnt[i]==2)
			flag[i]=false;
	}

	int k;
	while(scanf("%d",&k)!=EOF)
	{
		int var,key=0;
		while(k--)
		{
			scanf("%d",&var);
			key+=!flag[var]?1:0;
		}
		printf("%d\n",key);
	}

	return 0;
}
