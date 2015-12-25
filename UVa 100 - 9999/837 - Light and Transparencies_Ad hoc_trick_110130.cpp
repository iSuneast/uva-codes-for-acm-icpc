/*
837 - Light and Transparencies

Ad hoc...
��ʵ�����trick����ͦ���Ե���...
����������������������ͬ�Ļ�����ϲ��������...
��4�ֺϲ�
-inf �� �м��
�м�� �� �м��
�м�� �� +inf
-inf �� +inf
�㶨���⼸���ϲ�,ac��ûʲô��������~

happy coding...
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10001
using namespace std;
const double eps=1e-9;

struct SEG
{
	double s,e,w;
}seg[MAXN];
double p[MAXN<<1], ans[MAXN<<1];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		int tot=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%*lf%lf%*lf%lf", &seg[i].s, &seg[i].e, &seg[i].w);
			if(seg[i].s > seg[i].e)
				swap( seg[i].s, seg[i].e);
			p[tot++]=seg[i].s;
			p[tot++]=seg[i].e;
		}
		sort(p,p+tot);

		ans[0]=ans[tot]=1;
		for(int i=1;i<tot;++i)
		{
			ans[i]=1;
			for(int j=0;j<n;++j)
			{
				if(seg[j].s<=p[i-1]+eps && p[i]-eps<=seg[j].e)
					ans[i]*=seg[j].w;
			}
		}

		int key=0;
		for(int i=0; i<=tot;)
		{
			int j=i;
			while(j<=tot && ans[j]==ans[i])
				++j;

			if(i==0 && j==tot+1)
				++key;
			else if(i==0)
				++key;
			else if(j==tot+1)
				++key;
			else
				++key;

			i=j;
		}

		printf("%d\n",key);
		for(int i=0; i<=tot;)
		{
			int j=i;
			while(j<=tot && ans[j]==ans[i])
				++j;

			if(i==0 && j==tot+1)
				puts("-inf +inf 1.000");
			else if(i==0)
				printf("-inf %.3lf 1.000\n", p[j-1]);
			else if(j==tot+1)
				printf("%.3lf +inf 1.000\n", p[j-2]);
			else
				printf("%.3lf %.3lf %.3lf\n", p[i-1], p[j-1], ans[i]);

			i=j;
		}

		if(dataset)
			putchar(10);
	}

	return 0;
}
