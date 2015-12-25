/*
10450 - World Cup Noise

fib...
太丢脸了...
这种题竟然也WA了一次...
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
		cout<<b<<endl<<endl;	//多一个换行..
	}

return 0;
}
