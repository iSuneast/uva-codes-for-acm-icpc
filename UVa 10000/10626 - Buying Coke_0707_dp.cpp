/*
10626 - Buying Coke

dp...
汗,数组越界了竟然是wa...
听说有贪心解法...
不过比较笨没想出来...

state[c][n5][n10]
保存要买c可乐,剩余n5,n10的钱
令tot=_n1 + 5*_n5 + 10*_n10 - _c*8,则可得
	n1=tot+8*c-5*n5-10*n10
	故只需保存c,n5,n10三个状态即可...
n1>=8	dp(c-1,n5,n10)+8
n1>=3	
	n5>=1	dp(c-1,n5-1,n10)+4
	n10>=1	dp(c-1,n5+1,n10-1)+4
n5>=2	dp(c-1,n5-2,n10)+2
n10>=1	dp(c-1,n5,n10-1)+1
关键是在n1==3,n10==1这一步
	10*1+1*3=8(一瓶可乐)+5*1(一枚5硬币)
*/

#include<iostream>
#define MAXC 160
#define MAX5 160
#define MAX10 60
#define COST 8
#define INF 0x3f3f3f3f
using namespace std;

int state[MAXC][MAX5][MAX10],tot;

int dp(int c,int n5,int n10)
{
	int n1=tot+COST*c-5*n5-10*n10;
	int &cur=state[c][n5][n10];

	if(!c)
		return 0;
	if(cur!=INF)
		return cur;

	if(n1>=COST)
		cur=min(cur,dp(c-1,n5,n10)+COST);
	if(n1>=3)
	{
		if(n5>=1)
			cur=min(cur,dp(c-1,n5-1,n10)+4);
		if(n10>=1)
			cur=min(cur,dp(c-1,n5+1,n10-1)+4);
	}
	if(n5>=2)
		cur=min(cur,dp(c-1,n5-2,n10)+2);
	if(n10>=1)
		cur=min(cur,dp(c-1,n5,n10-1)+1);
	return cur;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,c,n1,n5,n10;

	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d%d%d%d",&c,&n1,&n5,&n10);
		tot=n1+5*n5+10*n10-c*COST;
		memset(state,0x3f,sizeof(state));
		printf("%d\n",dp(c,n5,n10));
	}

	return 0;
}
