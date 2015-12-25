/*
11149 - Power of Matrix

matrix...
矩阵乘法...
按题意模拟,只是多了相加的过程而已..
*/

#include<iostream>
#define MAXN 43
#define MOD 10
using namespace std;

template<class T>
struct MATRIX
{
	T mat[MAXN][MAXN];
	MATRIX(){memset(mat,0,sizeof(mat));}
	MATRIX multiply(const MATRIX &t,const int n)const
	{
		MATRIX tmp;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				tmp.mat[i][j]=0;
				for(int k=0;k<n;++k)
					tmp.mat[i][j]=(tmp.mat[i][j]+mat[i][k]*t.mat[k][j])%MOD;
			}
			return tmp;
	}
	MATRIX add(const MATRIX &t,const int n)const
	{
		MATRIX tmp;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				tmp.mat[i][j]=(mat[i][j]+t.mat[i][j])%MOD;
		return tmp;
	}
};

typedef pair< MATRIX<short>,MATRIX<short> > pMM;
MATRIX<short> ori;
int n,k;

void output(MATRIX<short> cur)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(j)
				putchar(' ');
			printf("%d",cur.mat[i][j]);
		}
		putchar(10);
	}
	putchar(10);
}

pMM pow_mod(MATRIX<short> cur,int k)
{
	if(k==1)
		return make_pair(cur,cur);

	pMM tmp=pow_mod(cur,k/2);
	MATRIX<short> sum=tmp.first,power=tmp.second;
	MATRIX<short> buf=sum.multiply(power,n);

	sum=sum.add(buf,n);
	power=power.multiply(power,n);

	if(k&1)
	{
		power=power.multiply(ori,n);
		sum=sum.add(power,n);
	}

	return make_pair(sum,power);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%d",&n,&k)!=EOF && n)
	{
		int t;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&t);
				ori.mat[i][j]=t%MOD;
			}
		}

		output(pow_mod(ori,k).first);
	}

	return 0;
}
