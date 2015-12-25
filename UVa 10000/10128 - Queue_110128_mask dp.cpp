/*
 * 10128 - Queue
 *
 * mask dp...
 * ��ʵ�и��Ӷ�O(N*N)��DP�ⷨ��~
 * Ҫ�õ������ѧ��֪ʶ
 *
 * ������ͨ��״̬DP,�ⷨ���Ǻ���Ȼ��
 * dp[����][��ǰ���ü�����][״̬]
 * "��ߵ���"���Դ�״̬����õ�,��ΪH
 * ��δѡ�е�������ѡһ��,��ΪX
 * ���X>H && ��ǰ���ü�����<���ü�����
 * 		״̬ת��Ϊdp[����][��ǰ���ü�����+1][�ϲ���״̬]
 * ���X<H
 * 		״̬ת��Ϊdp[����][��ǰ���ü�����][�ϲ���״̬]
 *
 * �÷��ε�˼��,��ߵ���һ����N,N�������Ҫ��p-1����,�ұ�����r-1����
 * ����ö���������,��Ϊi,���ұ���n-i-1����
 * ������ߵ�i���˿��Դ�n����������ѡ,������ΪC(n-1,i-1)
 * ���ΪSUM( dp[i][0][0]*dp[n-i-1][0][0]*C(n-1,i-1) )
 *
 * happy coding~
 */

#include<iostream>
#define INSIDE(i,s) ((1<<(i))&s)
#define MERGE(i,s) ((1<<(i))|s)
#define ALL(n) ((1<<(n))-1)
#define MAXN 13
using namespace std;
typedef long long LL;

LL dp[MAXN][MAXN][1<<MAXN];

LL DP(int n,int p,int state)
{
	if(dp[n][p][state]!=-1)
		return dp[n][p][state];
	if(state==ALL(n))
		return dp[n][p][state]=(p==0);

	int hei=-1;
	for(int i=0;i<n;++i)
	{
		if(INSIDE(i,state))
			hei=i;
	}

	dp[n][p][state]=0;
	for(int i=0;i<n;++i)
	{
		if(!INSIDE(i,state))
		{
			if(i>hei && p>0)
				dp[n][p][state]+=DP(n,p-1,MERGE(i,state));
			else if(i<hei)
				dp[n][p][state]+=DP(n,p,MERGE(i,state));
		}
	}

	return dp[n][p][state];
}

LL C(int n,int p)
{
	LL key=1;
	for(int i=p+1;i<=n;++i)
		key*=i;
	for(int i=2;i<=n-p;++i)
		key/=i;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	int dataset,n,p,r;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d",&n,&p,&r);
		LL key=0;
		for(int i=p;i<=n-r+1;++i)
		{
			key+=DP(i-1,p-1,0)*DP(n-i,r-1,0)*C(n-1,i-1);
		}

		printf("%lld\n",key);
	}

	return 0;
}
