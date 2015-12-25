/*
10012 - How Big Is It?

brute force...
dp...
������Ϊ�Ǽ��㼸�ε���Ŀ...
û�뵽�Ǳ���ö��ȫ��
Ȼ����Բ�Ŀ�Ⱥ�

Ҫ��dp����,����ֱ��̰...
��Ϊ���ܳ����м�ĳ��Բ��С...
���ߺܴ�����

��x[i]Ϊ��i��Բ��Բ�ĵĺ�����
���ܳ���Ϊmax(x[i]+r[i])
��ʼ��x[i]=r[i]
Ȼ��x[i]=max(x[i],x[j]+dis(r[i],r[j]))
����disΪ�뾶Ϊr[i],r[j]�ĺ�����ľ���
*/

#include<iostream>
#include<cmath>
#define MAXN 10
#define INF 0x7f7f7f7f
using namespace std;

int n;
double radii[MAXN],key,cur[MAXN];
bool flag[MAXN];

double dis(double r1,double r2)
{
	double c=r1+r2,b=r1-r2;
	return sqrt(c*c-b*b);
}

void dfs(int dep)
{
	if(dep==n)
	{
		double x[MAXN],ans=0;
		for(int i=0;i<n;++i)
		{
			x[i]=cur[i];
			for(int j=0;j<i;++j)
				x[i]=max(x[i],x[j]+dis(cur[i],cur[j]));
			ans=max(ans,x[i]+cur[i]);
		}
		key=min(key,ans);
	}
	else for(int i=0;i<n;++i)
		if(!flag[i])
		{
			flag[i]=true;
			cur[dep]=radii[i];
			dfs(dep+1);
			flag[i]=false;
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
		for(int i=0;i<n;++i)
			scanf("%lf",radii+i);
		key=INF;
		dfs(0);
		printf("%.3lf\n",key);
	}

	return 0;
}
