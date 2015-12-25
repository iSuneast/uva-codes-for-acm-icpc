/*
542 - France '98

dp...
手工打表...很好很强大...

把每一轮的对手按规则取出来
然后,队伍i的第ROUND轮对手为j,有
win[ROUND][i]=win[ROUND-1][i]*sum(g[i][j]*win[ROUND-1][j])
其中win[0][i]=1

打表一定要有耐心啊...
*/

#include<iostream>
#define MAXN 16
#define ROUND 5
using namespace std;

char country[MAXN][MAXN];
double g[MAXN][MAXN];
double win[ROUND][MAXN];
int player[ROUND][MAXN],cnt[ROUND];
void init();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	for(int i=0;i<MAXN;++i)
	{
		scanf("%s",&country[i]);
		win[0][i]=1.0;
	}

	for(int i=0;i<MAXN;++i)
		for(int j=0;j<MAXN;++j)
		{
			scanf("%lf",&g[i][j]);
			g[i][j]/=100.0;
		}

	for(int i=1;i<ROUND;++i)
		for(int j=0;j<MAXN;++j)
		{
			double key=0;
			for(int k=player[i][j];k<player[i][j]+cnt[i];++k)
				key+=g[j][k]*win[i-1][k];
			win[i][j]=win[i-1][j]*key;
		}

	for(int i=0;i<MAXN;++i)
		printf("%-10s p=%.2lf%%\n",country[i],win[ROUND-1][i]*100);

	return 0;
}

void init()
{
	cnt[1]=1;
	cnt[2]=2;
	cnt[3]=4;
	cnt[4]=8;

	player[1][0]=1;
	player[1][1]=0;
	player[1][2]=3;
	player[1][3]=2;
	player[1][4]=5;
	player[1][5]=4;
	player[1][6]=7;
	player[1][7]=6;
	player[1][8]=9;
	player[1][9]=8;
	player[1][10]=11;
	player[1][11]=10;
	player[1][12]=13;
	player[1][13]=12;
	player[1][14]=15;
	player[1][15]=14;

	player[2][0]=2;
	player[2][1]=2;
	player[2][2]=0;
	player[2][3]=0;
	player[2][4]=6;
	player[2][5]=6;
	player[2][6]=4;
	player[2][7]=4;
	player[2][8]=10;
	player[2][9]=10;
	player[2][10]=8;
	player[2][11]=8;
	player[2][12]=14;
	player[2][13]=14;
	player[2][14]=12;
	player[2][15]=12;

	player[3][0]=4;
	player[3][1]=4;
	player[3][2]=4;
	player[3][3]=4;
	player[3][4]=0;
	player[3][5]=0;
	player[3][6]=0;
	player[3][7]=0;
	player[3][8]=12;
	player[3][9]=12;
	player[3][10]=12;
	player[3][11]=12;
	player[3][12]=8;
	player[3][13]=8;
	player[3][14]=8;
	player[3][15]=8;

	player[4][0]=8;
	player[4][1]=8;
	player[4][2]=8;
	player[4][3]=8;
	player[4][4]=8;
	player[4][5]=8;
	player[4][6]=8;
	player[4][7]=8;
	player[4][8]=0;
	player[4][9]=0;
	player[4][10]=0;
	player[4][11]=0;
	player[4][12]=0;
	player[4][13]=0;
	player[4][14]=0;
	player[4][15]=0;
}