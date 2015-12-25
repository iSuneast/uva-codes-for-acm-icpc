/*
10617 - Again Palindrome

DP...
谁叫你不认真看题目的...
暴力做果然TLE...
没发现题目说的是字符串的长度是60...
还以为是15...
结果发现15是测试数据组数= =

最后还好找到了状态转移方程...
若s[start]==s[target-1]则
		key[start][target]=
		1+dp(start+1,target)+dp(start,target-1)
否则
		key[start][target]=
		dp(start+1,target)+dp(start,target-1)-dp(start+1,target-1);
记忆化搜索即可...
*/

#include<iostream>
#define MAXN 63
using namespace std;

long long key[MAXN][MAXN];
char s[MAXN];

long long dp(int start,int target)
{
	if(key[start][target]!=-1)
		return key[start][target];
	else if(start==target)
		return 0;
	else if(start+1==target)
		return key[start][target]=1;
	else if(s[start]==s[target-1])
		return key[start][target]=1+dp(start+1,target)+dp(start,target-1);
	else
		return key[start][target]=dp(start+1,target)+dp(start,target-1)-dp(start+1,target-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s;
		memset(key,-1,sizeof(key));
		cout<<dp(0,strlen(s))<<endl;
	}

	return 0;
}
