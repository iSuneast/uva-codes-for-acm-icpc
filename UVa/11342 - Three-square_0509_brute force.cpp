/*
11342 - Three-square

brute force...
�����Ļ�...
Ҳ��Ҫ������ı���...
����k�Ƚ�С..
����ֻҪö�ٵ�sqrt(k)�Ϳ�����
O(n^3)���㷨���Թ�...
���ǲ������ݺܶ�...
���...

���ǿ�����ö��i,j,kȻ���i^2+j^2+k^2�������.
���浽������...
���ֻҪ���һ��,�Ϳ���O(1)��ѯ����...
*/

#include<iostream>
#define MAXN 224
#define MAXSZ 50001
using namespace std;

int var[MAXN],n,ans[3][MAXSZ];
bool flag[MAXSZ];

void init()
{
	for(int i=1;i<MAXN;++i)
		var[i]=i*i;
	for(int i=0;i<MAXN;++i)
		for(int j=i;j<MAXN;++j)
			for(int k=j;k<MAXN;++k)
			{
				int t=var[i]+var[j]+var[k];
				if(t<MAXSZ && !flag[t])
				{
					flag[t]=true;
					ans[0][t]=i;
					ans[1][t]=j;
					ans[2][t]=k;
				}
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("acm.txt","w",stdout);
#endif

	init();
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		if(flag[n])
			printf("%d %d %d\n",ans[0][n],ans[1][n],ans[2][n]);
		else
			puts("-1");
	}

	return 0;
}
