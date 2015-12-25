/*
10518 - How Many Calls?

fib
matrix multiply
ans[n]=ans[n-1]+ans[n-2]+1
*/

#include<iostream>
using namespace std;

const int A[3][3]={
	1,1,1,
	1,0,0,
	0,0,1
};

const int E[3][3]={
	1,0,0,
	0,1,0,
	0,0,1
};

int R[3][3],D[3][3];

void mul(int a[3][3],int b[3][3],int m)
{
	int c[3][3];
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			c[i][j]=0;
			for(int k=0;k<3;++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%m;
		}
	memcpy(a,c,sizeof(int)*9);
}

int pow_mod(long long b,int m)
{
	memcpy(D,A,sizeof(int)*9);
	memcpy(R,E,sizeof(int)*9);

	for(;b>0;b/=2)
	{
		if(b&1)
			mul(R,D,m);
		mul(D,D,m);
	}

	return (R[0][0]+R[0][1]+R[0][2])%m;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int b,cas=1;
	long long n;
	while(scanf("%lld%d",&n,&b)!=EOF && (n||b))
	{
		printf("Case %d: %lld %d %d\n",cas++,n,b,pow_mod(n-1,b));
	}

	return 0;
}
