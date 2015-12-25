/*
550 - Multiplying by Rotation

number theory...
����...
��λ�˷�...

(XXX*base+factor)*digit=factor*base^(n-1)+XXX...
����...
XXX=(factor*base^(n-1)-factor*digit)/(base*digit-1)...
ֻ����֤������������...
����(factor*base^(n-1)-factor*digit)%(base*digit-1)==0

����ö�ٳ�ʱ...������base^(n-1)���������...
�������Ż�.

��	c=base*digit-1
	b=(factor*digit)%c
	a=(factor*base)%c
�����ͬ�ඨ��,ÿ��ֻ����֤a==b����.
	��������������a=(a*base)%c...
	ÿ��������Ա������..

���⻹����ע��һ��...
��factor=0��ʱ��,����digit=1��ʱ��.λ��Ϊ1...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int base,factor,digit;
	while(scanf("%d%d%d",&base,&factor,&digit)!=EOF)
	{
		if(factor==0 || digit==1)
		{
			cout<<1<<endl;
			continue;
		}
		int key=2,a,b,c=base*digit-1;
		b=(factor*digit)%c;
		a=(factor*base)%c;
		while(true)
			if(a==b)
				break;
			else
				a=(a*base)%c,++key;
		cout<<key<<endl;
	}

	return 0;
}
