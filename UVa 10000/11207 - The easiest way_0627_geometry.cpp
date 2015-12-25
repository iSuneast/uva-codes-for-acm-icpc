/*
11207 - The easiest way

geometry...
�ܹ����������...
����һ�¾Ϳ�����...
1.w>4*h			key=h
----------------------------
|                           |
----------------------------
2.w<4*h			key=w/4
------
|    |
------
3.��Ϊ����w>=h(��������Խ���w,h)	key=h/2
Ȼ��ȡ��ǰ(w,h)����key����
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		double key=0;
		int p,w,h;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&w,&h);
			if(w<h)
				swap(w,h);
			double t=0;
			if(w<=4*h)
				t=w/4.0;
			else
				t=h;
			t=max(t,h/2.0);
			if(t>key)
			{
				key=t;
				p=i;
			}
		}
		printf("%d\n",p);
	}

	return 0;
}
