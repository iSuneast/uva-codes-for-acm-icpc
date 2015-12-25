/*
10534 - Wavio Sequence

DP...
LIS...
非主流的LIS的题目...
规模比较大所以要用O(NlogN)的算法优化...

将序列弄成forward和backward两种...
对两个序列跑两次LIS就OK了...
然后取forseq和backseq里面的相同位置的最小值的最大值key...
则解即为2*key-1...(序列是对称的)...

sample
forward		1 2 3 4 5 4 3 2 1 10
backward	10 1 2 3 4 5 4 3 2 1
跑LIS后得到
forseq		1 2 3 4 5 4 3 2 1 6
backseq		1 2 3 4 5 4 3 2 1 1
于是key=max(key,min(forseq,backseq))=5
	ans=key*2-1=9...
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;

int forward[MAXN],backward[MAXN],forseq[MAXN],backseq[MAXN],buf[MAXN],n;

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

void lis(int a[MAXN],int seq[MAXN])
{
	memset(buf,0,sizeof(buf));
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		int p=upper_bound(buf,buf+cnt,a[i])-buf;
		while(p && a[i]<=buf[p-1])
			--p;
		if(p>=cnt)
			++cnt;
		buf[p]=a[i];
		seq[i]=p+1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;++i)
			scanf("%d",forward+i);
		for(i=0;i<n;++i)
			backward[i]=forward[n-1-i];
		lis(forward,forseq);
		lis(backward,backseq);
		int key=0;
		for(i=0;i<n;++i)
			key=max(key,(min(forseq[i],backseq[n-1-i])));
		printf("%d\n",key*2-1);
	}

	return 0;
}
