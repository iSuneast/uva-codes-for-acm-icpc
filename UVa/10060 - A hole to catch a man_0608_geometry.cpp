/*
10060 - A hole to catch a man

geometry....
²æ»ý...
*/

#include<iostream>
#include<cmath>
#define pi (2*acos(0.0))
#define eps 1e-9
using namespace std;

struct POINT
{
	double x,y;
}a,b,end;

double square(POINT &a,POINT &b)
{
	return a.x*b.y-a.y*b.x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	while(cin>>n && n)
	{
		double tot=0;
		while(n--)
		{
			double s=0,h;
			cin>>h;
			cin>>a.x>>a.y;
			end=a;

			do 
			{
				b=a;
				cin>>a.x>>a.y;
				s+=square(b,a);
			}while(fabs(end.x-a.x)>eps || fabs(end.y-a.y)>eps);

			tot+=fabs(s)/2.0*h;
		}

		double r,t;
		cin>>r>>t;
		double per=pi*r*r*t;

		cout<<floor(tot/per)<<endl;
	}

	return 0;
}
