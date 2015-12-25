/*
10626 - Buying Coke

dp...
��,����Խ���˾�Ȼ��wa...
��˵��̰�Ľⷨ...
�����Ƚϱ�û�����...

state[c][n5][n10]
����Ҫ��c����,ʣ��n5,n10��Ǯ
��tot=_n1 + 5*_n5 + 10*_n10 - _c*8,��ɵ�
	n1=tot+8*c-5*n5-10*n10
	��ֻ�豣��c,n5,n10����״̬����...
n1>=8	dp(c-1,n5,n10)+8
n1>=3	
	n5>=1	dp(c-1,n5-1,n10)+4
	n10>=1	dp(c-1,n5+1,n10-1)+4
n5>=2	dp(c-1,n5-2,n10)+2
n10>=1	dp(c-1,n5,n10-1)+1
�ؼ�����n1==3,n10==1��һ��
	10*1+1*3=8(һƿ����)+5*1(һö5Ӳ��)
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
