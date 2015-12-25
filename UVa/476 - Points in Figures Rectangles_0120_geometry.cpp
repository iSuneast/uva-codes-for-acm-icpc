/*
476 - Points in Figures: Rectangles
...
托看错题目的福...
WA了两次...
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
	freopen("in.txt","r",stdin);
	double a[11][2],b[11][2],x,y;
	int n=0,i,cas=1,flag;
	while(getchar()=='r')
	{
		cin>>a[n][0]>>a[n][1]>>b[n][0]>>b[n][1],getchar();
		if(a[n][0]>b[n][0])
			exc(&a[n][0],&b[n][0]);
		if(a[n][1]<b[n][1])
			exc(&a[n][1],&b[n][1]);
		n++;
	}
	while(cin>>x>>y&&(x!=9999.9||y!=9999.9))
	{
		flag=1;;
		for(i=0;i<n;i++)
			if(x>a[i][0]&&y<a[i][1]&&x<b[i][0]&&y>b[i][1])
				cout<<"Point "<<cas<<" is contained in figure "<<i+1<<endl,flag=0;
		if(flag)
			cout<<"Point "<<cas<<" is not contained in any figure"<<endl;
		cas++;
	}

return 0;
}
