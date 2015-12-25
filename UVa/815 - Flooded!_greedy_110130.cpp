/*
815 - Flooded!

Ad hoc...
greedy
����һ��n*m�ĵ�ͼ,ÿ���С10*10ƽ����,��������Щ�صĺ���
�Լ����������Ľ�����,��,ˮ��߿����͵����,
�����θ߶�̰��һ�¾ͺ���~

happy coding~
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const double eps=1e-9;
typedef pair<double,double> pdd;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,m,cas=1;
	double l,s;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		double sz=n*m;
		priority_queue<pdd,vector<pdd>,greater<pdd> > pq;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				scanf("%lf",&l);
				pq.push( make_pair(l,100) );
			}
		}

		scanf("%lf",&s);
		while(s!=0)
		{
			pdd cur=pq.top();	pq.pop();
			while( !pq.empty() && fabs(pq.top().first-cur.first)<eps )
			{
				cur.second+=pq.top().second;
				pq.pop();
			}

			double hei=s;
			if(!pq.empty())
				hei=pq.top().first;
			double dif=hei-cur.first;
			double up=s/cur.second;

			if(dif>=up)
			{
				cur.first+=up;
				s=0;
			}
			else
			{
				cur.first+=dif;
				s-=dif*cur.second;
			}

			pq.push(cur);
		}

		printf("Region %d\n",cas++);
		printf("Water level is %.2lf meters.\n",pq.top().first);
		printf("%.2lf percent of the region is under water.\n",pq.top().second/sz);
		putchar(10);
	}

	return 0;
}
