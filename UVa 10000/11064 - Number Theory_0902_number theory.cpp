/*
11064 - Number Theory

number theory...
euler function...
it's a simple euler problem...
n=p1^n1*p2^n2*...
the final answer is n-phi(n)-multiply( ni+1 )+1
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int t=n,cnt,phi=n,key=1;

		if(t%2==0)
		{
			cnt=1;
			while(t%2==0)
			{
				t/=2;
				++cnt;
			}
			key*=cnt;
			phi=phi/2;
		}

		for(int i=3;i*i<=t && i*i/i==i;i+=2)
		{
			if(t%i==0)
			{
				cnt=1;
				while(t%i==0)
				{
					t/=i;
					++cnt;
				}
				key*=cnt;
				phi=phi/i*(i-1);
			}
		}

		if(t!=1)
		{
			key*=2;
			phi=phi/t*(t-1);
		}

		printf("%d\n",n-phi-key+1);
	}

	return 0;
}
