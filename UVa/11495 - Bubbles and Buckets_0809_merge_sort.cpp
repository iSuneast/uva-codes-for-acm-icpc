/*
11495 - Bubbles and Buckets

merge_sort...
算出逆序对数,判断奇偶性即可...
*/

#include<iostream>
#define MAXN 100003
using namespace std;

int n,var[MAXN],buf[MAXN];
long long key;

void merge_sort(int s,int e)
{
	if(s+1>=e)
		return ;
	int mid=(s+e)/2;
	merge_sort(s,mid);
	merge_sort(mid,e);
	int p=s,q=mid,i=s;
	while(p<mid || q<e)
	{
		if((p<mid && var[p]<=var[q]) || q==e)
			buf[i++]=var[p++];
		else
		{
			key+=mid-p;
			buf[i++]=var[q++];
		}
	}
	for(i=s;i<e;++i)
		var[i]=buf[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);
		key=0;
		merge_sort(0,n);
		puts(key&1?"Marcelo":"Carlos");
	}

	return 0;
}
