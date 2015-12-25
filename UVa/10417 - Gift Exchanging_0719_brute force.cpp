/*
10417 - Gift Exchanging

brute force...
暴力枚举所有可能的排列...
"1 3 2 1 1" -->	s="12223345"(代表每个物品出现的位置)
用stl的next_permutation枚举即可
将 key[ s[0] ]+=pro[0][ s[0] ]*pro[1][ s[1] ]*...pro[n-1][ s[n-1] ]
令sum=sum(key[0-4])
则每个物品取到的概率为key[i]/sum/cnt[i]
*/

#include<iostream>
#include<algorithm>
#define MAXN 15
using namespace std;

int cnt[5];
double pro[MAXN][5],key[5];
char s[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,p=0;
		scanf("%d",&n);
		for(int j=0;j<5;++j)
		{
			scanf("%d",&cnt[j]);
			key[j]=0;
			for(int k=0;k<cnt[j];++k)
				s[p++]='0'+j;
		}

		for(int i=0;i<n;++i)
			for(int j=0;j<5;++j)
				scanf("%lf",&pro[i][j]);

		do
		{
			double t=1.0;
			for(int i=0;i<n;++i)
				t*=pro[i][ s[i]-'0' ];
			key[ s[0]-'0' ]+=t;
		}while(next_permutation(s,s+p));

		double s=0;
		for(int j=0;j<5;++j)
			s+=key[j];

		p=0;
		for(int j=0;j<5;++j)
			if(cnt[j])
			{
				key[j]/=(s*cnt[j]);
				if(key[j]>key[p])
					p=j;
			}

		printf("%d %.3lf\n",p+1,key[p]);
	}

	return 0;
}
