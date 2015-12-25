/*
11151 - Longest Palindrome

DP...
edit steps...

发现自己对这个类型的题目已经很熟悉了...
所以,就不用写什么状态转移方程了...
基本一看就懂...
*/

#include<iostream>
#define MAXN 1010
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int key[MAXN][MAXN];
char s[MAXN];

int dp(int start,int end)
{
	if(start==end)
		return 0;
	else if(key[start][end]!=-1)
		return key[start][end];
	else if(start+1==end)
		return key[start][end]=1;
	else if(s[start]==s[end-1])
		return key[start][end]=dp(start+1,end-1)+2;
	else
		return key[start][end]=max(dp(start+1,end),dp(start,end-1));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	getchar();
	while(dataset--)
	{
		gets(s);
		memset(key,-1,sizeof(key));
		cout<<dp(0,strlen(s))<<endl;
	}

	return 0;
}
