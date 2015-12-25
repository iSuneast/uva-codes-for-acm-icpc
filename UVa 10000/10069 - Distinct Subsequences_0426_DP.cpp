/*
10069 - Distinct Subsequences

DP...
神奇地WA了一次...
然后又神奇的CE了一次...

貌似不是很难的题...
可惜加了高精度进去有点不爽哈...
本来打算用java偷懒一下的...
无奈实在是不会java...
连字符串都读不进来...
无语掉...

关于状态转移方程...
若xj=yi的话dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
否则dp[i][j]=dp[i][j-1]...直接copy上面得到的值...

      r  a  b  b  b  i  t
   1  1  1  1  1  1  1  1   --->边界
r  0  1  1  1  1  1  1  1
a  0  0  1  1  1  1  1  1
b  0  0  0  1  2  3  3  3
b  0  0  0  0  1  3  3  3
i  0  0  0  0  0  0  3  3
t  0  0  0  0  0  0  0  3
  ^
 边界
*/

#include<iostream>
#define MAXN 10010
#define MAXLEN 110
using namespace std;

class bign
{
	friend ostream &operator<<(ostream &,bign &);
public:
	bign &operator+=(bign &);
	bign &operator=(bign &);
	bign(){memset(var,0,sizeof(var));}
	short var[MAXLEN];		//开short,不然image太大,会CE...
};

bign &bign::operator=(bign &b)
{
	memcpy(var,b.var,sizeof(var));
	return *this;
}

bign &bign::operator+=(bign &b)
{
	int i,carry=0;
	for(i=0;i<MAXLEN;++i)
		var[i]+=b.var[i];
	for(i=0;i<MAXLEN;++i)
	{
		var[i]=var[i]+carry;
		carry=var[i]/10;
		var[i]%=10;
	}
	return *this;
}

ostream & operator<<(ostream &os,bign &a)
{
	int i=MAXLEN-1;
	while(i>=0 && !a.var[i])
		--i;
	if(i<0)
		putchar('0');
	else for(;i>=0;--i)
		cout<<a.var[i];
	return os;
}

bign dp[MAXLEN][MAXN];		//这里的数组一二维不能弄反...
char x[MAXN],y[MAXLEN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,i,j,l1,l2;
	cin>>dataset;
	while(dataset--)
	{
		cin>>x>>y;
		l1=strlen(x);
		l2=strlen(y);
		for(j=0;j<=l1;++j)
			dp[0][j].var[0]=1;
		for(i=1;i<=l2;++i)
			for(j=1;j<=l1;++j)
				if(y[i-1]==x[j-1])
					dp[i][j]=dp[i-1][j-1],
					dp[i][j]+=dp[i][j-1];
				else
					dp[i][j]=dp[i][j-1];
		cout<<dp[l2][l1]<<endl;
	}

	return 0;
}
