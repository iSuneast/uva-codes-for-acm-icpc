/*
10217 - A Dinner with Schwarzenegger!!!

math...
概率论的题
p(1)=1/n
p(2)=[ 1-p(1) ]*1/n
p(3)=[ 1-p(1)-p(2) ]*2/n
....
p(x)=[ 1-sum(1,x-1) ]*(x-1)/n
=>	sum(1,x-1)=1-n*p(x)/(x-1)
sum(1,x)=sum(1,x-1)+p(x)
=>
x=sqrt(n+0.25)-0.5.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double n;
	while(cin>>n)
		printf("%.2lf %.0lf\n",sqrt(n+0.25)-0.5,floor( sqrt(n+0.25)-0.5 )+1);

	return 0;
}
