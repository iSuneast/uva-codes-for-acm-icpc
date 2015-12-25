/*
10738 - Riemann vs Mertens

number theory...
thieves...
��ʵ����ɸ������ǿ��..
i������
����ܱ�i*iɸ��,����mu[]=0
����++�����Ӹ���
���ͳ��һ�������Ӹ���Ϊ������ż������...
*/

#include<iostream>
#define MAXN 1000003
using namespace std;

int mu[MAXN],MU[MAXN],n;
int prime[MAXN];

void init()
{
	memset(mu,0x3f,sizeof(mu));
	mu[1]=1;	MU[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(prime[i]==0)
		{
			mu[i]=-1;
			int t=i*i;
			if(t/i==i)
				for(int j=t;j<MAXN;j+=t)
					prime[j]=-1;
			for(int j=i+i;j<MAXN;j+=i)
				if(prime[j]!=-1)
					prime[j]++;
		}
		else if(prime[i]==-1)
			mu[i]=0;
		else if(prime[i]&1)
			mu[i]=-1;
		else
			mu[i]=1;

		MU[i]=MU[i-1]+mu[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%d",&n)!=EOF && n)
		printf("%8d%8d%8d\n",n,mu[n],MU[n]);

	return 0;
}
