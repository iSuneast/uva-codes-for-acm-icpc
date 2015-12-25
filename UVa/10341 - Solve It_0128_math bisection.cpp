/*
10341 - Solve It
*/

#include<iostream>
#include<cmath>

#define eps 0.00000000001 

using namespace std;

double p,q,r,s,t,u;

double calc(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main()
{
//	freopen("in.txt","r",stdin);
	double sx,ex,mx,sres,eres,mres;
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		if(p||q||r||s||t||u)
		{
			sx=0,mx=0.5,ex=1;
			sres=calc(sx);
			eres=calc(ex);
			mres=calc(mx);
			if((sres>eps&&eres>eps)||(sres<-eps&&eres<-eps))
			{
				cout<<"No solution"<<endl;
				continue;
			}
			if(fabs(sres)<eps)
			{
				cout<<"0.0000"<<endl;
				continue;
			}
			if(fabs(eres)<eps)
			{
				cout<<"1.0000"<<endl;
				continue;
			}
			while(1)
			{
				if(fabs(mres)<eps)
				{
					printf("%.4lf\n",mx);
					break;
				}
				else if((sres<-eps&&mres>eps)||(sres>eps&&mres<-eps))
					ex=mx,mx=(sx+ex)/2;
				else if((eres<-eps&&mres>eps)||(eres>eps&&mres<-eps))
					sx=mx,mx=(sx+ex)/2;
				else
				{
					cout<<"No solution"<<endl;
					break;
				}
				sres=calc(sx);
				eres=calc(ex);
				mres=calc(mx);
			}
		}
		else
			cout<<"0.0000"<<endl;			//here,Ë­ËµµÄ...No solution?
	}


return 0;
}
