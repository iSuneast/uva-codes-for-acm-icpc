/*
636 - Squares (III)

math...
����ת��...
ע��һ�½��ƴ�2��ʼ����...
һ������ƽ����...
�������Ǹ����Ʊ�ʾ�޹�...
����ת��Ϊ10����ͳһ�жϼ���
*/

#include<iostream>
#include<cmath>
#define MAXN 35
using namespace std;

char num[MAXN];
int len,base;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(gets(num) && strcmp(num,"0"))
	{
		len=strlen(num);
		base=2;
		for(int i=0;i<len;++i)
		{
			num[i]-='0';
			base=max(base,num[i]+1);
		}

		while(true)
		{
			int key=0;
			for(int i=0;i<len;++i)
				key=key*base+num[i];
			int t=sqrt(key*1.0);
			if(t*t==key)
			{
				printf("%d\n",base);
				break;
			}
			++base;
		}
	}

	return 0;
}
