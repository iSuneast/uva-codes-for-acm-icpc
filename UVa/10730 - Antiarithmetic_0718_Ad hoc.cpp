/*
10730 - Antiarithmetic?

Ad hoc...
判断一个序列的子序列是否无法构成等差数列
对原始序列排序,记录初始位置
由(a+c)=2*b
只需枚举等差数列的a,c然后二分查找b是否存在
且b的下标在a,c之间则不存在...
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;

struct DATA
{
	int var,pos;
	bool operator<(const DATA &t)const
	{
		if(var==t.var)
			return pos<t.pos;
		return var<t.var;
	}
}data[MAXN];
int n,ori[MAXN];

bool chk()
{
	DATA t;
	t.pos=0;
	for(int i=0;i<n;++i)
		for(int j=i+2;j<n;++j)
		{
			t.var=ori[i]+ori[j];
			if(t.var%2==0)
			{
				t.var/=2;
				int p=lower_bound(data,data+n,t)-data;
				while(p<n && data[p].var==t.var)
				{
					if(data[p].pos>=i && data[p].pos<=j)
						return false;
					++p;
				}
			}
		}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d",&n)!=EOF && n)
	{
		getchar();
		for(int i=0;i<n;++i)
		{
			scanf("%d",&data[i].var);
			ori[i]=data[i].var;
			data[i].pos=i;
		}
		sort(data,data+n);

		if(chk())
			puts("yes");
		else
			puts("no");
	}


	return 0;
}
