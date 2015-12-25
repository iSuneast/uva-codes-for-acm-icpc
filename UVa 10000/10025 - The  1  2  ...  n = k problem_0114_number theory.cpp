/*
10025 - The ? 1 ? 2 ? ... ? n = k problem
*/

/*
main里面的----i---为接二次方程求根得出.....
方程为 (1+n)*n/2>=i..........

根据 (1+i)*i/2......求和......得到1+...+n的和序列...
令				SUM1=1+2+.....+ANS+.....+i;
令				SUM2=1+2+.....-ANS+.....+i;
则可以得到.....SUM2-SUM1=2*ANS........

根据对称性....n....与....-n....的取值是一样的...
*/

#include<iostream>
#include<cmath>

using namespace std;

long n,t,i;

int not_match(int i)
{
	return ((1+i)*i/2-n)%2;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		n=abs(n);
		i=(long)ceil((-1.0+sqrt(1.0+8*n))/2);
		while(not_match(i))
			i++;
		if(!n)
			i=3;
		cout<<i<<endl;
		if(t)
			cout<<endl;
	}

return 0;
}