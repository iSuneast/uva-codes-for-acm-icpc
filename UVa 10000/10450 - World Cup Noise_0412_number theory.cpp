/*
10450 - World Cup Noise

fib...
̫������...
�����⾹ȻҲWA��һ��...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,n;
	long long a,b,c;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		a=b=1;
		cin>>n;
		cout<<"Scenario #"<<cas<<":"<<endl;
		for(int i=0;i<n;++i)
		{
			c=b;
			b+=a;
			a=c;
		}
		cout<<b<<endl<<endl;	//��һ������..
	}

return 0;
}
