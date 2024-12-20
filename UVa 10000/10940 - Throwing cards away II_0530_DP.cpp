/*
10940 - Throwing cards away II

DP...
这dp也够简单的了...

	1 2 3 4 ... i-2 i-1 i   第i种状态
=>    3 4 5 ... i-1  i  2     丢掉一张牌,并且将第一张牌移动到底部后
      1 2 3 ... i-3 i-2 i-1 第i-1种状态
显然,当card[i-1]=i-1时card[i]的值应该是2
	 其它情况card[i]=card[i-1]+2
*/

#include<iostream>
#define MAXN 500000
using namespace std;

int card[MAXN+3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	card[1]=1;
	for(int i=2;i<=MAXN;++i)
		if(card[i-1]==i-1)
			card[i]=2;
		else
			card[i]=card[i-1]+2;
	int n;
	while(scanf("%d",&n)!=EOF && n)
		printf("%d\n",card[n]);

	return 0;
}
