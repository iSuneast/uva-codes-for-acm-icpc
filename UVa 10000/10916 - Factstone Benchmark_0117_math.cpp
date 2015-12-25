/*
10916 - Factstone Benchmark
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double y,i;
	while(cin>>y&&y)
	{
		i=1;
		y=(long)(y-1960)/10;
		y=(2<<((long)y+1))*log(2.0);
		while(y>=0)
			y-=log(i++);
		cout<<i-2<<endl;
	}

return 0;
}