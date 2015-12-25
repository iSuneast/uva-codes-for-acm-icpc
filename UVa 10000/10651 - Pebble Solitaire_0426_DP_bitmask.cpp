/*
10651 - Pebble Solitaire

DP...
bitmask...

��λ������������...
�ÿ��İ�...
  
daxia˵��...
ģ�͵�ת����������Ҫ...

�������Կ���ת��Ϊλ�������ʽ���...
��'-'��Ϊ0��'o'��Ϊ1.
�����п���ת��Ϊ[0,2^12)�Ķ�����.

������Ϊ�����DP�����Ϲ�ϵ...
��������...
��ʵҲֻ�������˼��仯��������...

״̬ת�ƺܼ�...
ֻ��x110x��x011x����������ſ�ת��...
ֻ����λ����������Ķ����Ʊ�ʾ�����Ƿ��������������
����,����x110x --> x001x
		 x011x --> x100x
Ȼ����仯�����ɵõ�ȫ�����ܽ�...
ȡ���ֽ��������Сֵ����...
�����滹���뿼��δ�����κ���������...
��ԭ�������溬�е�1�ĸ���...
*/

#include<iostream>
#include<string>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN (1<<12)
#define ini ((0x6)<<9)
#define pick ((0x7)<<9)
using namespace std;

int dp[MAXN];

int calc(int n)
{
	int cnt=0;
	while(n)
	{
		if(n&1)
			++cnt;
		n=n>>1;
	}
	return cnt;
}

int dfs(int u)
{
	if(dp[u]!=-1)
		return dp[u];
	dp[u]=12;
	int key=ini,pic=pick,t;
	for(int j=0;j<10;++j)		//�������Чλ��ʼɨ��
	{
		if((u&pic)==key)
		{
			t=dfs(u-(5<<(9-j)));
			dp[u]=min(dp[u],t);
		}
		key=key>>1;
		if((u&pic)==key)
		{
			t=dfs(u+(1<<(9-j)));
			dp[u]=min(dp[u],t);
		}
		pic=pic>>1;
	}
	t=calc(u);
	dp[u]=min(dp[u],t);
	return dp[u];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	int dataset;
	cin>>dataset;
	string buf;
	while(dataset--)
	{
		cin>>buf;
		int var=0;
		for(int i=0;i<12;++i)
			var=var*2+(buf[i]=='o'?1:0);	//ģ�͵�ת��...
		cout<<dfs(var)<<endl;
	}

	return 0;
}
