/*
11069 - A Graph Problem

dp...
找递推关系...
joybo的解题报告错了...
浪费了我不少时间...
n	ans	key
1	1	{1}
2	2	{1},{2}
3	2	{1,3},{2}
4	3	{1,3},{1,4},{2,4}
5	4	{1,3,5},{2,5},{2,4},{1,4}
6	5	{2,4,6},{1,4,6},{1,3,6},{1,3,5},{2,5}
观察一下n=6的情况
	很明显是{6}+{n=4},{5}+{n=3}
	于是递推关系就出来了...
	dp[n]=dp[n-2]+dp[n-3]
	边界条件dp[1]=1，dp[2]=dp[3]=2
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dp[78];
	dp[1]=1;
	dp[2]=dp[3]=2;
	for(int i=4;i<=76;++i)
		dp[i]=dp[i-2]+dp[i-3];

	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",dp[n]);

	return 0;
}
