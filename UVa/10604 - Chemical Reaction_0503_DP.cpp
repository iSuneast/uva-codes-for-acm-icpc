/*
10604 - Chemical Reaction

DP...
���˺ô���������һ��DP��...
���Ǵ�˵�е�״̬ת��DP...
֮ǰһֱû���ҵ��õ�״̬ת�Ʒ���...
��������״̬����һ��������Ļ�...
�ͱ�úܼ���...

��ʵ���԰���ѧ��Ʒ������ѹ��...
�����ǰ���һ��״̬�ľ�����̬ѹ��...

����һ��sample��ѹ�������ͺ�������...
	--- 1 2 2 3	����ת��Ϊ
���� 1 ���� 1
���� 2 ���� 2
���� 3 ���� 1
��״̬��Ϊ	121
��,״̬ת����úܼ���...
121	->	*11+() || 1*1+() || 11*+() ->...
���������10���Թ�����ѹ����11���Ƶ�������...
ÿ��Ҫ�õ�ʱ�򻯻�����������...

���⻹��һ������Ҫ�ĵط�...
��Ҫ���׵ض���Ŀû����������صط���������...
Ҫ֪��˵(1,3)�����(3,1)����ǲ��ȼ۵�...
��Ȼ�Ⲣ��Ӱ��״̬ת��...
���Ǵ���ļ���ó��Ľ�����ȻҲ�Ǵ����...
WA��N�εĴ���...
*/

#include<iostream>
#define MAXSTATE 1610510
#define MAXN 10
#define MOD 11
#define INF 0x7f7f7f7f
using namespace std;

int state[MAXSTATE],var[MAXN],n,m;
struct pii
{
	int first,second;
}g[MAXN][MAXN];

int hash()
{
	int key=0;
	for(int i=1;i<=n;++i)
		key=key*MOD+var[i];
	return key;
}

int dp(int cur)
{
	if(state[cur]!=INF)
		return state[cur];
	else
	{
		bool done=false;
		for(int i=1;i<=n;i++)
			if(var[i])
				for(int j=i;j<=n;++j)
					if((j==i && var[j]>1) || (j>i && var[j]))
					{
						--var[i];
						--var[j];
						++var[ g[i][j].first ];
						int t=dp(hash())+g[i][j].second;
						--var[ g[i][j].first ];
						state[cur]=min(state[cur],t);
						++var[ g[j][i].first ];
						t=dp(hash())+g[j][i].second;
						state[cur]=min(state[cur],t);
						--var[ g[j][i].first ];
						++var[i];
						++var[j];
						done=true;
					}
		if(!done)
			state[cur]=0;
		return state[cur];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		int i,j;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				scanf("%d%d",&g[i][j].first,&g[i][j].second);
		scanf("%d",&m);
		int t;
		memset(var,0,sizeof(var));
		for(i=0;i<m;++i)
		{
			scanf("%d",&t);
			++var[t];
		}
		memset(state,0x7f,sizeof(state));
		printf("%d\n",dp(hash()));
		char c;
		while((c=getchar())!='/' && c!='.')	;
	}

	return 0;
}
