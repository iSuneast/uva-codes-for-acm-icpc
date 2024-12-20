/*
10920 - Spiral Tap

math...
从1开始,右上对角线的元素为odd^2
可以借此来判断p位置具体在哪个圈
然后模拟即可(数学方式的模拟,不能用一步一步地减,会TLE)
*/

#include<iostream>
#include<algorithm>
#define MAXN 50000
using namespace std;

long long tab[MAXN];
int x,y,sz,p;

void calc(int cur,int pase)
{
	if(p+pase>=cur)
	{
		x-=cur-p;
		return ;
	}
	cur-=pase;
	x-=pase;

	if(p+pase>=cur)
	{
		y-=cur-p;
		return ;
	}
	cur-=pase;
	y-=pase;

	if(p+pase>=cur)
	{
		x+=cur-p;
		return ;
	}
	cur-=pase;
	x+=pase;

	y+=cur-p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	for(long long i=0;i<MAXN;++i)
		tab[i]=(2*i+1)*(2*i+1);

	while(scanf("%d%d",&sz,&p)!=EOF && (sz||p))
	{
		int pos=lower_bound(tab,tab+MAXN,p)-tab;
		x=y=(sz+1)/2+pos;
		calc(tab[pos],2*pos);

		printf("Line = %d, column = %d.\n",x,y);
	}

	return 0;
}
