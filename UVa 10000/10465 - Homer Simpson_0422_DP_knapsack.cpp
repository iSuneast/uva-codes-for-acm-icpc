/*
10465 - Homer Simpson

DP...
knapsack...
ACM���ĵĵ�һ��0-1��������...
WA��4��...
��ʵ���ڿ������ñ���������ʵҲ���������...
ʲô������������...
����˾ͺ�˵...
���ڱ����ĳ�ʼ��....
dp[0]=1����...
��ҪŪ��dp[n[0]]=dp[n[1]]=1...
��������ܴ�..
*/

#include<iostream>
#define MAXN 10010
using namespace std;

int dp[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n[2],t;
	while(cin>>n[0]>>n[1]>>t)
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		dp[0]=1;	//��ʼ��...����0�ɴ�...
		for(i=0;i<2;++i)
			for(j=0;j<=t;++j)
				if(j>=n[i] && dp[j-n[i]])
					dp[j]=max(dp[j],dp[j-n[i]]+1);
		if(dp[t])
			cout<<dp[t]-1<<endl;
		else for(int i=t;i>=0;--i)
				if(dp[i])
				{
					cout<<dp[i]-1<<" "<<t-i<<endl;
					break;
				}
	}

	return 0;
}
