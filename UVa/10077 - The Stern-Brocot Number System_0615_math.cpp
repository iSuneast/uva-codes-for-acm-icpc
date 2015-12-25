/*
10077 - The Stern-Brocot Number System

math...
��ʱ�����ǻᱻ����ı������ɱ�...
��ʵ�Ǻ�ˮ����Ŀ...
���Ǳ���Ŀ����ĸ������ŵ�...

��ʵ����һ������������...
����ȥ����...
��ʵ�ܼ�...
*/

#include<iostream>
using namespace std;
typedef pair<int,int> pii;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

bool inside(pii a,pii s,pii e)
{
	return a.first*s.second>s.first*a.second
		&& a.first*e.second<e.first*a.second;
}

pii add(pii a,pii b)
{
	a.first=a.first+b.first;
	a.second=a.second+b.second;
	int t=gcd(a.first,a.second);
	a.first/=t;
	a.second/=t;
	return a;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	pii l,r,m,key;
	while(scanf("%d%d",&key.first,&key.second)!=EOF && (key.first!=1 || key.second!=1))
	{
		l=make_pair(0,1);
		r=make_pair(1,0);
		m=make_pair(1,1);

		while(m!=key)
		{
			if(inside(key,l,m))
			{
				r=m;
				m=add(m,l);
				putchar('L');
			}
			else if(inside(key,m,r))
			{
				l=m;
				m=add(m,r);
				putchar('R');
			}
		}
		putchar('\n');
	}

	return 0;
}
