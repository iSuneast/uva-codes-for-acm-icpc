/*
10611 - The Playboy Chimp

search...
���ֲ��Ҳ���...
����������STL��upper_bound����lower_bound�����̴��볤��..
����Ҫ����һЩ�������...
h<var[0]	h=var[0]
h=var[n-1]	h<var[n-1]
���ֱ߽�����...
�������ҵ���ŵ�λ�ú�ֱ��whileһ��������ȵ�ֵ�Ϳ�����...
*/

#include<iostream>
#include<algorithm>
#define MAXN 50010
using namespace std;

int var[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,q,i,h;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf("%d",var+i);
	scanf("%d",&q);
	for(i=0;i<q;++i)
	{
		scanf("%d",&h);
		if(h<var[0])
			printf("X %d\n",var[0]);
		else if(h==var[0])
		{
			int p=0;
			while(var[p]<=h)
				++p;
			printf("X %d\n",var[p]);
		}
		else if(h>var[n-1])
			printf("%d X\n",var[n-1]);
		else if(h==var[n-1])
		{
			int p=n-1;
			while(var[p]>=h)
				--p;
			printf("%d X\n",var[p]);
		}
		else
		{
			int p=(int *)lower_bound(var,var+n,h)-var,t=p;
			while(var[p]>=h)
				--p;
			while(var[t]<=h)
				++t;
			printf("%d %d\n",var[p],var[t]);
		}
	}

	return 0;
}
