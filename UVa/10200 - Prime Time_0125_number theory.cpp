/*
10200 - Prime Time
...
又吃浮点数的亏了....
*/

#include<iostream>
#include<cmath>

using namespace std;

int prime[10010],flag[10010];

long euler(int n)
{
	return n*(n+1)+41;
}

int isprime(int n)
{
	int t,tn,i;
	flag[n]=1;
	tn=euler(n);
	t=sqrt(tn)+2;
	for(i=2;i<t;i++)
		if(tn%i==0)
			return prime[n]=0;
	return prime[n]=1;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10200.txt","w",stdout);

	int i,cnt,l,r;
	memset(flag,0,sizeof(flag));
	memset(prime,0,sizeof(prime));
	while(cin>>l>>r)
	{
		cnt=0;
		for(i=l;i<=r;i++)
		{
			if(!flag[i])
				isprime(i);
			if(prime[i])
				cnt++;
	}
		printf("%.2f\n",(double)cnt*100/(r-l+1)+1e-9);
	}

return 0;
}
