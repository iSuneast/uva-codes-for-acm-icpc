/*
10310 - Dog and Gopher

geometry...
�뾫���й�?
��doubleת��Ϊlong long ��,���ⲻ��Ҫ�ľ������...

һֱWA����һ��nc��ԭ��...
%.3lf д���� %.4lf...
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
		cin>>tx>>ty;	//����
		a=1000*tx;
		b=1000*ty;
		cin>>tx>>ty;	//��
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
