/*
10125 - Sumsets
......
programming的感觉....

从过去到现在.
一直是这样的...
无论我做什么事...
经常都是一个人...
孤孤单单....
...
小时候会跑mm家玩...
可是现在不回了...
我的生活变得单调...
变得苍白...
...
我知道ACM不会成为我生活的全部...
但是..
我爱她...
正如我爱心中的she一样...
...
她们都会在我的梦里...
令我辗转...
令我难眠...
*/

#include<iostream>
#include<algorithm>

using namespace std;
int n,cnt,num[1010];

struct set
{
	int s,a,b;
}sum[1000000];

int cmp(const void *a,const void *b)
{
	return ((set *)a)->s - ((set *)b)->s;
}

bool chk(set *p,int a,int b)
{
	while(p-1>=sum && p->s == (p-1)->s)
		p--;
	bool flag=false;
	if(!(p->a == a || p->b == b || p->a == b || p->b == a))
		flag=true;
	while(p+1<sum+cnt && p->s == (p+1)->s)
	{
		p++;
		if(!(p->a == a || p->b == b || p->a == b || p->b == a))
			flag=true;
	}
	return flag;
}

void calc()
{
	for(int i=n-1;i;i--)
		for(int j=i-1;j>=0;j--)		//这里之前写成;j;也就是说吧j==0给漏了...
		{
			set t;
			t.s=num[i]-num[j];
			set	*p=(set *)bsearch(&t,sum,cnt,sizeof(sum[0]),cmp);
			if(p && chk(p,j,i))
			{
				cout<<num[i]<<endl;
				return ;
			}
		}
	cout<<"no solution"<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10125.txt","w",stdout);
	
	while(cin>>n && n)
	{
		int i,j;
		for(i=0;i<n;i++)
			cin>>num[i];
		sort(num,num+n);
		cnt=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				sum[cnt].s=num[i]+num[j];
				sum[cnt].a=i;
				sum[cnt++].b=j;
			}
		qsort(sum,cnt,sizeof(sum[0]),cmp);
		calc();
	}

return 0;
}
