/*
10911 - Forming Quiz Teams

DP...
��˵�е�״̬ת��DP...
Messi��ţ�̵�...

����ÿһ��״̬������һ��������������...
��Ϊö��ÿһ��״̬...
�����ܵ�ö�ٴ�����2^(2*n)����ڱ���ö����˵�Ѿ��൱�Ż�...
�����ĸ��Ӷ���c(16,2)+c(14,2)+...TLE�Ŀ�����->����...
*/

#include<iostream>
#include<cmath>
#define MAXN 20
#define MAXSZ 1<<16
#define INF 1e9
using namespace std;

struct point{	double x,y;	}pnt[MAXN];
int n;
bool flag[MAXN];
double g[MAXN][MAXN],state[MAXSZ];

double dis(int i,int j)
{
	double dx=pnt[i].x-pnt[j].x;
	double dy=pnt[i].y-pnt[j].y;
	return sqrt(dx*dx+dy*dy);
}

double dp(int cur)
{
	if(state[cur])
		return state[cur];
	else for(int i=0;i<2*n;++i)
		if(!(cur&(1<<i)))
			for(int j=i+1;j<2*n;++j)
				if(!(cur&(1<<j)))
				{
					int t=cur+(1<<i)+(1<<j);
					if(!state[cur])
						state[cur]=dp(t)+g[i][j];
					else
						state[cur]=min(dp(t)+g[i][j],state[cur]);
				}
	return state[cur];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cas=1;
	while(cin>>n && n)
	{
		char buf[30];
		int i,j;
		for(i=0;i<2*n;++i)
		{
			cin>>buf>>pnt[i].x>>pnt[i].y;
			for(j=0;j<i;++j)
				g[i][j]=g[j][i]=dis(i,j);
		}
		memset(state,0,sizeof(state));
		printf("Case %d: %.2lf\n",cas++,dp(0));
	}

	return 0;
}
