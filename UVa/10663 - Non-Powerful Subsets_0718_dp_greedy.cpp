/*
10663 - Non-Powerful Subsets

greedy...
dp...
knapsack...
��һ��������Ӽ�,�ǵ�����Լ����������Ԫ�ص���ϲ��������ȫ��
̰��˼��

�ȶ�(1+1000)*1000/2��Χ��Ԫ�ؽ���ɸ��,����ȫ��ɸ��
Ȼ����������x,��x��ʼö��x����һ��Ԫ��y
���y��֮ǰ�ļ��ϲ��������ȫ�������y
�жϼ����Ƿ������ȫ�������ñ������

���ݹ�ģ�Ƚϴ�
ֱ�ӳ�[x,1000]���Ȼ���������
*/

#include<iostream>
#define MAXN 500510
using namespace std;

bool flag[MAXN];
int key[1010][100],tot,a,b,sz[1010];
bool dp[MAXN];

void output(int p)
{
	printf("%d",key[p][0]);
	for(int i=1;i<sz[p] && key[p][i]<=b;++i)
		printf(" %d",key[p][i]);
	putchar('\n');
}

bool chk(int var)
{
	for(int j=tot;j>=0;--j)
		if(dp[j])
			if(flag[j+var])
				return false;
	return true;
}

void insert(int p,int var)
{
	key[p][ sz[p]++ ]=var;
	for(int j=tot;j>=0;--j)
		if(dp[j])
			dp[j+var]=true;
	tot+=var;
}

void init()
{
	memset(flag,0,sizeof(flag));
	for(int i=2;i<708;++i)
		if(!flag[i])
		{
			int t=i*i;
			while(t<MAXN)
			{
				flag[t]=true;
				t*=i;
			}
		}

	for(int i=1;i<=1000;++i)
	{
		sz[i]=0;
		if(!flag[i])
		{
			memset(dp,0,sizeof(dp));
			dp[0]=true;		tot=0;
			for(int j=i;j<=1000;++j)
				if(!flag[j])
					if(chk(j))
						insert(i,j);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		bool got=false;
		for(int i=a;i<=b && !got;++i)
			if(sz[i])
			{
				output(i);
				got=true;
			}
		if(!got)
			putchar('\n');
	}

	return 0;
}
