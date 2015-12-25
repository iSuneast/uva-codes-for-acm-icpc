/*
11889 - Benefit

number theory...
A = p1^a1 * p2^a2 * ... * pi^ai
B = p1^b1 * p2^b2 * ... * pi^bi
C = p1^n1 * p2^n2 * ... * pi^ni
which "pi" is a prime, and "ni" is its power

if 0 <= ai < ni, bi = ni
else bi= 0
*/

#include<iostream>
#define MAXN 3163
using namespace std;

bool flag[MAXN];
int prime[MAXN],cnt=0;

void init()
{
	memset(flag,0,sizeof(flag));
	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		if(flag[i])
			continue;
		prime[cnt++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			flag[j]=true;
	}
}

int calc(int &t,int &p)
{
	int key=0;
	while(t%p==0)
	{
		t/=p;
		++key;
	}
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int a,c,dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&a,&c);
		int tc=c;
		if(c%a)
			puts("NO SOLUTION");
		else
		{
			int t=c/a,b=1;
			for(int i=0;i<cnt;++i)
			{
				if(t%prime[i]==0)
				{
					int numT=calc(t,prime[i]);
					if(calc(a,prime[i]))
					{
						int numC=calc(c,prime[i]);
						while(numC--)
							b*=prime[i];
					}
					else while(numT--)
						b*=prime[i];
				}
			}
			b*=t;
			printf("%d\n",b);
		}
	}

	return 0;
}
