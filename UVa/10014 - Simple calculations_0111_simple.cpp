/*
10014 - Simple calculations
*/

#include<iostream>

using namespace std;

int main()
{
	int t,n,i;
	double a0,an,c[3000],res;
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>n;
		cin>>a0>>an;
		for(i=0;i<n;i++)
			cin>>c[i],res+=(n-i)*c[i];
		res=-2*res;
		res+=n*a0+an;
		printf("%.2f\n",res/(n+1));
		if(t)
			cout<<endl;
	}

return 0;
}