/*
11526 - H(n)

math...
��ѧ��,�ƹ�ʽ...
@ n<=0�Ļ�,��Ϊ0
@ n�Ƚ�С�Ļ�,ֱ�ӱ���ö��
@ n�Ƚϴ�Ļ�,ö�ٵ�sqrt(n)Ϊֹ,Ȼ���ҹ���
	n=15   /1 /2 /3 /4 /5 /6 /7 /8  ......
	key+=  15  7  5  3  3  2  2  1  1...
���ɻ��Ǻ����Ե�
*/

#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long long dataset;
	scanf("%lld",&dataset);
	while(dataset--)
	{
		long long key=0,i,j,cur,n;
		scanf("%lld",&n);
		if(n<=0)
			key=0;
		else if(n<=1000)
		{
			for(i=1;i<=n;++i)
				key+=n/i;
		}
		else
		{
			for(i=1;i*i<=n;++i)
				key+=n/i;
			for(j=--i;j>1;--j)
			{
				cur=n/j;
				key+=(cur-i)*j;
				i=cur;
			}
			key+=n-n/2;
		}
		printf("%lld\n",key);
	}

	return 0;
}
