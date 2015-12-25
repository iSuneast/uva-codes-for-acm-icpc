/*
10271 - Chopsticks

dp...
���׹۲쵽˵...
dp[i][j]��ʾΪ����i��Ϊֹѡk��...
��dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+badness(i,i-1))
������Ŀ������˵A<=B<=C,
���������ôѡ�Ļ�,���޷���֤ȡ����C����������
���Զ����еĳ�����������,����״̬ת�Ƶ�ʱ��֤i>=3*j�Ϳ�����
*/

#include<iostream>
#define MAXN 5003
#define MAXK 1003
using namespace std;

int n,k,var[MAXN],dp[MAXN][MAXK];

void init()
{
	memset(dp[0],0x3f,sizeof(dp[0]));
	memset(dp[1],0x3f,sizeof(dp[1]));
	for(int i=0;i<n;++i)
		dp[i][0]=0;
}

int badness(int i,int j)
{
	int d=var[i]-var[j];
	return d*d;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d",&k,&n);
		k+=8;
		for(int i=n;i;--i)
			scanf("%d",&var[i]);
		init();
		for(int i=2;i<=n;++i)
			for(int j=1;j<=k;++j)
			{
				if(i>=3*j)
					dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+badness(i,i-1));
				else
					dp[i][j]=dp[i-1][j];
			}
		printf("%d\n",dp[n][k]);
	}

	return 0;
}
