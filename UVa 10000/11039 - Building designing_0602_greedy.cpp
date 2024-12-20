/*
11039 - Building designing

greedy...
题目理解错了...
直接贪心就可以了...
不要dp...
*/

#include<iostream>
#include<algorithm>
#define MAXN 500010
#define INF 0x7f7f7f7f
using namespace std;

int red[MAXN],blue[MAXN];

void calc(int *a,int &la,int *b,int &lb)
{
	int key=0,cur=INF;
	while(la && lb)
	{
		while(la && a[la-1]>cur)
			--la;
		if(!la)
			break;
		++key;
		cur=a[la-1];

		while(lb && b[lb-1]>cur)
			--lb;
		if(!lb)
			break;
		++key;
		cur=b[lb-1];
	}
	printf("%d\n",key);
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
		int n,red_cnt=0,blue_cnt=0,t;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&t);
			if(t<0)
				red[red_cnt++]=-t;
			else
				blue[blue_cnt++]=t;
		}
		sort(red,red+red_cnt);
		sort(blue,blue+blue_cnt);
		if(!red_cnt || !blue_cnt)
			puts("1");
		else if(red[red_cnt-1]>blue[blue_cnt-1])
			calc(red,red_cnt,blue,blue_cnt);
		else
			calc(blue,blue_cnt,red,red_cnt);
	}

	return 0;
}
