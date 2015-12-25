/*
10810  	Ultra-QuickSort

sorting...
算逆序对数
归并排序即可...
*/

#include<iostream>
#define MAXN 500010
using namespace std;

int var[MAXN],n;
int tmp[MAXN];
long long key;

void merge_sort(int l,int r)
{
	if(l+1>=r)
		return ;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m,r);

	int p=l,i=l,q=m;
	while(p<m || q<r)
	{
		if(q>=r || (p<m && var[p]<=var[q]))
			tmp[i++]=var[p++];
		else
		{
			key+=m-p;
			tmp[i++]=var[q++];
		}
	}

	for(i=l;i<r;++i)
		var[i]=tmp[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);
		key=0;
		merge_sort(0,n);
		printf("%lld\n",key);
	}

	return 0;
}
