/*
10739 - String to Palindrome

DP...
经典的模型...
编辑距离...

其实这个模型和矩阵链乘很像...
首先两者都是O(n^3)的复杂度...
而且都是从长度短的序列开始递推的...

令start,target分别为当前序列的首尾两端...
则可以得到...
case 1: start>=target dp[start][target]=0;	//序列为空的情况
case 2: str[start]==str[target] dp[start][target]=
		1+min(dp[start+1][target-1],dp[start+1][target],dp[start][target-1]);
		即考虑到三种情况的递推中取最小的即可...
可以用记忆化搜索...
不过估计TLE希望很大...
因为我用递推都跑了1.0s...
所以...
*/

#include<iostream>
#include<string>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 1010
using namespace std;

int dp[MAXN][MAXN];
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,cas=1;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s;
		int len=s.length();
		memset(dp,0,sizeof(dp));
		for(int l=1;l<len;++l)
			for(int start=0;start<len-l;++start)
				for(int target=start+1;target<=start+l;++target)
					if(s[start]==s[target])
						dp[start][target]=dp[start+1][target-1];
					else
						dp[start][target]=1+min(dp[start+1][target-1],
							min(dp[start+1][target],dp[start][target-1]));
		cout<<"Case "<<cas++<<": "<<dp[0][len-1]<<endl;
	}

	return 0;
}
