/*
190 - Circle Through Three Points

貌似这题和精度无关.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("190.txt","w",stdout);

	long double pnt[3][2],rx,ry,r,a[2][3];
	bool first=true;
	while(cin>>pnt[0][0]>>pnt[0][1]>>pnt[1][0]>>pnt[1][1]>>pnt[2][0]>>pnt[2][1])
	{
		int t=-1;
		for(int i=0;i<2;i++)
			for(;i<2;i++)
			{
				a[i][0]=(pnt[i][0]+pnt[i+1][0])/2,a[i][1]=(pnt[i][1]+pnt[i+1][1])/2;
				if (pnt[i][1]!=pnt[i+1][1])
					a[i][2]=(-1)*((pnt[i+1][0]-pnt[i][0])/(pnt[i+1][1]-pnt[i][1]));
				else
					t=i;
			}
		if(t==-1)
		{
			rx=(a[1][1]-a[0][1]+a[0][2]*a[0][0]-a[1][2]*a[1][0])/(a[0][2]-a[1][2]);
			ry=(rx-a[0][0])*a[0][2]+a[0][1];
		}
		else
		{
			rx=a[t][0];
			ry=a[(t+1)%2][2]*(rx-a[(t+1)%2][0])+a[(t+1)%2][1];
		}
		r=sqrt((ry-pnt[0][1])*(ry-pnt[0][1])+(rx-pnt[0][0])*(rx-pnt[0][0]));

		cout.setf(cout.showpoint);
		cout.setf(ios::fixed);
		cout.precision(3);

		if(rx>0)
			cout<<"(x - "<<rx<<")^2 + (y ";
		else
			cout<<"(x + "<<-rx<<")^2 + (y ";
		if(ry>0)
			cout<<"- "<<ry<<")^2 = "<<r<<"^2"<<endl;
		else
			cout<<"+ "<<-ry<<")^2 = "<<r<<"^2"<<endl;
		cout<<"x^2 + y^2 ";
		double c=-2*rx,d=-2*ry,e=rx*rx+ry*ry-r*r;
		if(c<0)
			cout<<"- "<<-c<<"x ";
		else
			cout<<"+ "<<c<<"x ";
		if(d<0)
			cout<<"- "<<-d<<"y ";
		else
			cout<<"+ "<<d<<"y ";
		if(e<0)
			cout<<"- "<<-e<<" = 0";
		else
			cout<<"+ "<<e<<" = 0";
		cout<<endl<<endl;
	}

return 0;
}
