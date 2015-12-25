/*
481 - What Goes Up

LIS...
很久以前自己想出来的...
赞一个先.
*/

#include<iostream>
#include<algorithm>
#define MAXN 5000000		//晕,竟然是这里开的太小了...无数次WA的悲剧就是这样炼成的.
using namespace std;

int num[MAXN],ls[MAXN],p[MAXN],cnt=0;

void print(int key,int p)
{
	for(;cnt>=0;cnt--)
		if(ls[cnt]==p && num[cnt]<key)
		{
			int t=cnt;
			print(num[t],p-1);
			cout<<num[t]<<endl;
			return ;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("481.txt","w",stdout);

	int cnt2=0,*pnt;
	if(scanf("%d",num+cnt)==EOF)
	{
		cout<<0<<endl<<'-'<<endl;
		return 0;
	}
	do
	{
		ls[cnt]=1;
		pnt=(int *)upper_bound(p,p+cnt2,num[cnt]);
		if(pnt!=p && num[cnt]==*(pnt-1))
			--pnt;
		if(pnt!=p+cnt2)
		{
			*pnt=num[cnt];
			ls[cnt]=pnt-p+1;
		}
		else
		{
			p[cnt2++]=num[cnt];
			ls[cnt]=cnt2;
		}
		cnt++;
	}while(scanf("%d",num+cnt)!=EOF);
	cout<<cnt2<<endl<<'-'<<endl;

	for(--cnt;cnt>=0;cnt--)
		if(ls[cnt]==cnt2)
		{
			int k=cnt;
			print(num[cnt],cnt2-1);
			cout<<num[k]<<endl;
			break;
		}

return 0;
}
