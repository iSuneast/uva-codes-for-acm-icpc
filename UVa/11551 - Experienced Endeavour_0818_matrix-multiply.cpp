/*
11551 - Experienced Endeavour

matrix multiply...
赤裸裸的矩阵乘法...
b[]数组里面的元素可能重复的...
也就是说有"x b b"="2 1 1"的情况
初始化的矩阵的时候应该是元素++,而不是为1.
*/

#include<iostream>
#include<ctime>
#define MOD 1000
#define MAXN 54
using namespace std;

int mat[MAXN][MAXN],e[MAXN][MAXN],buf[MAXN][MAXN];
int var[MAXN],n;

void multiply(int a[MAXN][MAXN],int b[MAXN][MAXN])
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			buf[i][j]=0;
			for(int k=0;k<n;++k)
				buf[i][j]=(buf[i][j]+a[i][k]*b[k][j])%MOD;
		}
	memcpy(a,buf,sizeof(buf));
}

void pow_mod(int mat[MAXN][MAXN],int r,int final[MAXN][MAXN])
{
	for(;r;r/=2)
	{
		if(r&1)
			multiply(final,mat);
		multiply(mat,mat);
	}
}

void random_data();

int main()
{
#ifndef ONLINE_JUDGE
//	random_data();	return 0;
	freopen("in","r",stdin);
//	freopen("314","w",stdout);
#endif

	int dataset,r,s,t;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&n,&r);
		memset(mat,0,sizeof(mat));
		memset(e,0,sizeof(e));
		for(int i=0;i<n;++i)
		{
			e[i][i]=1;
			scanf("%d",&var[i]);
			var[i]%=MOD;
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",&s);
			while(s--)
			{
				scanf("%d",&t);
				++mat[i][t];
			}
		}
		pow_mod(mat,r,e);

		for(int i=0;i<n;++i)
		{
			int key=0;
			for(int j=0;j<n;++j)
				key=(key+e[i][j]*var[j])%MOD;
			if(i)
				putchar(' ');
			printf("%d",key);
		}
		putchar(10);
	}

	return 0;
}

void random_data()
{
	freopen("in","w",stdout);

	bool tmp[MAXN][MAXN];
	srand((unsigned)time(NULL));
	int dataset=100;
	cout<<dataset<<endl;
	while(dataset--)
	{
		int n=rand()%49+1,r=rand()*rand()%1000000000;
		cout<<n<<" "<<r<<endl;
		for(int i=0;i<n;++i)
			cout<<rand()<<" ";
		cout<<endl;
		memset(tmp,0,sizeof(tmp));
		int s=rand()*rand()%(n*n);
		while(s--)
			tmp[ rand()%n ][ rand()%n ]=true;
		for(int i=0;i<n;++i)
		{
			int cnt=0;
			for(int j=0;j<n;++j)
				if(tmp[i][j])
					++cnt;
			cout<<cnt;
			for(int j=0;j<n;++j)
				if(tmp[i][j])
					cout<<" "<<j;
			cout<<endl;
		}
		cout<<endl;
	}
}
