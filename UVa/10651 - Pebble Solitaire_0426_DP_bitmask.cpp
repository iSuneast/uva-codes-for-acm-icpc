/*
10651 - Pebble Solitaire

DP...
bitmask...

用位运算做出来了...
好开心啊...
  
daxia说过...
模型的转化能力很重要...

这题明显可以转化为位运算的形式求解...
将'-'设为0，'o'设为1.
则序列可以转变为[0,2^12)的二进制.

本来以为这题和DP扯不上关系...
现在想想...
其实也只是利用了记忆化搜索而已...

状态转移很简单...
只有x110x和x011x这两种情况才可转移...
只需用位运算查找数的二进制表示里面是否存在这样的序列
若有,则令x110x --> x001x
		 x011x --> x100x
然后记忆化搜索可得到全部可能解...
取各种解里面的最小值即可...
解里面还必须考虑未经过任何运算的情况...
即原变量里面含有的1的个数...
*/

#include<iostream>
#include<string>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN (1<<12)
#define ini ((0x6)<<9)
#define pick ((0x7)<<9)
using namespace std;

int dp[MAXN];

int calc(int n)
{
	int cnt=0;
	while(n)
	{
		if(n&1)
			++cnt;
		n=n>>1;
	}
	return cnt;
}

int dfs(int u)
{
	if(dp[u]!=-1)
		return dp[u];
	dp[u]=12;
	int key=ini,pic=pick,t;
	for(int j=0;j<10;++j)		//从最高有效位开始扫描
	{
		if((u&pic)==key)
		{
			t=dfs(u-(5<<(9-j)));
			dp[u]=min(dp[u],t);
		}
		key=key>>1;
		if((u&pic)==key)
		{
			t=dfs(u+(1<<(9-j)));
			dp[u]=min(dp[u],t);
		}
		pic=pic>>1;
	}
	t=calc(u);
	dp[u]=min(dp[u],t);
	return dp[u];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	int dataset;
	cin>>dataset;
	string buf;
	while(dataset--)
	{
		cin>>buf;
		int var=0;
		for(int i=0;i<12;++i)
			var=var*2+(buf[i]=='o'?1:0);	//模型的转化...
		cout<<dfs(var)<<endl;
	}

	return 0;
}
