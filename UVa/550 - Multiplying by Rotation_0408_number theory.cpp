/*
550 - Multiplying by Rotation

number theory...
数论...
移位乘法...

(XXX*base+factor)*digit=factor*base^(n-1)+XXX...
化简...
XXX=(factor*base^(n-1)-factor*digit)/(base*digit-1)...
只需验证可以整除即可...
即令(factor*base^(n-1)-factor*digit)%(base*digit-1)==0

暴力枚举超时...估计是base^(n-1)这里出问题...
作如下优化.

令	c=base*digit-1
	b=(factor*digit)%c
	a=(factor*base)%c
则根据同余定理,每次只需验证a==b即可.
	若不满足条件则a=(a*base)%c...
	每次求余可以避免溢出..

此外还必须注意一点...
当factor=0的时候,或者digit=1的时候.位数为1...
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
