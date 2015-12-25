/*
11081 - Strings

DP...
这题一开始拖lrj的福...
我想的很复杂...
而且似乎是想到了解法却一直不敢下手去写...
其实说起来还是很简单的...

只需依次枚举a,b,c三个字符串的关系即可...
a[tsa]==c[sc]	则	dp(tsa+1,sb,sc+1)
b[tsb]==c[sc]	则	dp(sa,tsb+1,sc+1)
记忆化搜索即可...
(速度比较慢...花了2.0sAC...卡过)
边界条件是sc==lc	即c字符串已经到达末尾..

最后注意一点是结果要取模...
key[sa][sb][sc]%=10007	用%=而不是%
否则中间结果溢出...
*/

#include<iostream>
#define MAXN 65
using namespace std;

char a[MAXN],b[MAXN],c[MAXN];
int key[MAXN][MAXN][MAXN],la,lb,lc;

int dp(int sa,int sb,int sc)
{
	if(key[sa][sb][sc]!=-1)
		return key[sa][sb][sc];
	key[sa][sb][sc]=0;
	if(sc==lc)
		return key[sa][sb][sc]=1;
	for(int tsa=sa;tsa<la;++tsa)
		if(a[tsa]==c[sc])
			key[sa][sb][sc]+=dp(tsa+1,sb,sc+1);
	for(int tsb=sb;tsb<lb;++tsb)
		if(b[tsb]==c[sc])
			key[sa][sb][sc]+=dp(sa,tsb+1,sc+1);
	return key[sa][sb][sc]%=10007;	//用%=而不是%
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
		cin>>a>>b>>c;
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		memset(key,-1,sizeof(key));
		cout<<dp(0,0,0)<<endl;
	}

	return 0;
}
