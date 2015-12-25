/*
10852 - Less Prime

number theory...
理解好题意...
巧妙地转化一下模型..
本题就变得很简单了...
找一个x<n,且x为素数使得n-p*x最大...
p满足p*x ≤ n < (p+1)*x...

可以暴力枚举,估计不会超时...
不过想一下就会发现.
n-p*x最大,且p*x<=n<(p+1)*x,必然有n%x最大...
则只需找最小的x,满足2*x>n即可
*/

#include<iostream>
#define MAXN 10010
using namespace std;

int prime[MAXN],cnt;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		if(prime[i]!=0)
			continue;
		prime[cnt++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			prime[j]=-1;
	}
	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n;
		cin>>n;
		for(int i=0;i<cnt;++i)
			if(prime[i]*2>n)
			{
				cout<<prime[i]<<endl;
				break;
			}
	}

	return 0;
}
