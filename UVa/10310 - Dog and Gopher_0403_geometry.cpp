/*
10310 - Dog and Gopher

geometry...
与精度有关?
把double转化为long long 型,避免不必要的精度误差...

一直WA还有一个nc的原因...
%.3lf 写成了 %.4lf...
orz.....
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10310.txt","w",stdout);

	long long n,a,b,c,d,dx1,dy1,dx2,dy2;
	double tx,ty;
	while(cin>>n)
	{
		cin>>tx>>ty;	//地鼠
		a=1000*tx;
		b=1000*ty;
		cin>>tx>>ty;	//狗
		c=1000*tx;
		d=1000*ty;
		bool more=true;
		for(int i=0;i<n;++i)
		{
			cin>>tx>>ty;
			if(more)
			{
				dx2=tx*1000;		dy2=ty*1000;
				dx1=a-dx2;		dy1=b-dy2;
				dx2=c-dx2;		dy2=d-dy2;
				if((dx1*dx1+dy1*dy1)*4<=(dx2*dx2+dy2*dy2))
				{
					printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",
						tx,ty);
					more=false;
				}
			}
		}
		if(more)
			cout<<"The gopher cannot escape."<<endl;
	}

	return 0;
}
