/*
477 - Points in Figures: Rectangles and Circles
*/

#include<iostream>

using namespace std;

void exc(double *a,double *b)
{
	double t;
	t=*a;
	*a=*b;
	*b=t;
}

int main()
{
	double a[11][2],b[11][2],x,y;
	int i,cas=1,flag[11]={0},pflag,n=0;
	char t;
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
		else
			break;
	while(cin>>x>>y&&(x!=9999.9||y!=9999.9))
	{
		pflag=1;
		for(i=0;i<n;i++)
			if(flag[i])
			{
				if(x>a[i][0]&&y<a[i][1]&&x<b[i][0]&&y>b[i][1])
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
