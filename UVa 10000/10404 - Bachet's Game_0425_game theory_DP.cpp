/*
10404 - Bachet's Game

DP...
带着不少的博弈色彩...
貌似和背包问题也很像...

对于sample: 23 3 1 3 8
我们可以得到如下的状态转移...
  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
  1  0  1  0  1  0  1  1  1  1  0  1  0  1  0  1  0  1  1  1  1  0  1
1代表-----Stan wins
0代表-----Ollie wins

易知:对于任意状态对于Stan非赢即输...
于是可以得到说如果在第i种状态,对于取子个数w[j]种任一有flag[i-w[j]]为false
即代表说在状态i-w[j]是Ollie赢..则
根据博弈里面每个人都采取最优策略,所以在i-w[j]态一定有Ollie赢..
于是在第i种状态Stan就一定赢...

而且从上面的打表可以看出..
先手的获胜几率更大...
*/

#include<iostream>
#define MAXN 1000010
using namespace std;

bool flag[MAXN];
int w[20],n,m;

bool dp()
{
	memset(flag,0,sizeof(flag));
	int i,j;
	flag[0]=true;
	for(i=0;i<m;++i)
		flag[w[i]]=true;
	for(i=1;i<=n;++i)
		if(!flag[i])
			for(j=0;j<m;++j)
				if(i>=w[j] && !flag[i-w[j]])
				{
					flag[i]=true;
					break;
				}
	return flag[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>n>>m)
	{
		for(int i=0;i<m;++i)
			cin>>w[i];
		if(dp())
			puts("Stan wins");
		else
			puts("Ollie wins");
	}

	return 0;
}
