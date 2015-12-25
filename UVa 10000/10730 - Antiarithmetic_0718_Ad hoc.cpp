/*
10730 - Antiarithmetic?

Ad hoc...
�ж�һ�����е��������Ƿ��޷����ɵȲ�����
��ԭʼ��������,��¼��ʼλ��
��(a+c)=2*b
ֻ��ö�ٵȲ����е�a,cȻ����ֲ���b�Ƿ����
��b���±���a,c֮���򲻴���...
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
