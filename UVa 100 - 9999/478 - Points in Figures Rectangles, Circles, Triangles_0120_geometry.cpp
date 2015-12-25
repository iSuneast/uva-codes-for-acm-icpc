/*
478 - Points in Figures: Rectangles, Circles, Triangles

geometry
*/

#include<iostream>

using namespace std;

double a[11][2],b[11][2],c[11][2],x,y;
int i,cas=1,flag[11]={0},pflag,n=0;
char t;

void exc(double *a,double *b)
{
	double t;
	t=*a;
	*a=*b;
	*b=t;
}

double s(double a0,double b0,double a1,double b1,double a2,double b2)
{
	return a0*b1+a1*b2+a2*b0-a0*b2-a1*b0-a2*b1;
}

int inside(int n)
{
	double s0=s(x,y,a[n][0],a[n][1],b[n][0],b[n][1]);
	double s1=s(x,y,b[n][0],b[n][1],c[n][0],c[n][1]);
	double s2=s(x,y,c[n][0],c[n][1],a[n][0],a[n][1]);
	double sn=s(a[n][0],a[n][1],b[n][0],b[n][1],c[n][0],c[n][1]);
	if(s1<0)
		s1=-s1;
	if(s2<0)
		s2=-s2;
	if(s0<0)
		s0=-s0;
	if(sn<0)
		sn=-sn;
	return s0+s1+s2-sn<1e-9;
}

int main()
{
	freopen("in.txt","r",stdin);
	while(t=getchar())
		if(t=='r')
		{
			cin>>a[n][0]>>a[n][1]>>b[n][0]>>b[n][1],getchar();
			if(a[n][0]>b[n][0])
				exc(&a[n][0],&b[n][0]);
			if(a[n][1]<b[n][1])
				exc(&a[n][1],&b[n][1]);
			flag[n]=1,n++;
		}
		else if(t=='c')
			cin>>a[n][0]>>a[n][1]>>b[n][0],getchar(),n++;
		else if(t=='t')
			cin>>a[n][0]>>a[n][1]>>b[n][0]>>b[n][1]>>c[n][0]>>c[n][1],getchar(),flag[n]=2,n++;
		else
			break;
	while(cin>>x>>y&&(x!=9999.9||y!=9999.9))
	{
		pflag=1;
		for(i=0;i<n;i++)
			if(flag[i]==1)
			{
				if(x>a[i][0]&&y<a[i][1]&&x<b[i][0]&&y>b[i][1])
					cout<<"Point "<<cas<<" is contained in figure "<<i+1<<endl,pflag=0;
			}
			else if(flag[i]==2)
			{
				if(inside(i))
					cout<<"Point "<<cas<<" is contained in figure "<<i+1<<endl,pflag=0;
			}
			else if((x-a[i][0])*(x-a[i][0])+(y-a[i][1])*(y-a[i][1])<b[i][0]*b[i][0])
					cout<<"Point "<<cas<<" is contained in figure "<<i+1<<endl,pflag=0;
		if(pflag)
			cout<<"Point "<<cas<<" is not contained in any figure"<<endl;
		cas++;
	}

return 0;
}
