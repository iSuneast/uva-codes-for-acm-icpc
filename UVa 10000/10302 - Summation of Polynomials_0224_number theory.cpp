/*
10302 - Summation of Polynomials
*/

#include<iostream>

using namespace std;

long long key[50010];

long long calc(long long n)
{
	if(key[n])
		return key[n];
	else
		return key[n]=calc(n-1)+n*n*n;
}

int main()
{
//	freopen("in.txt","r",stdin);

	memset(key,0,sizeof(key));
	key[1]=1;
	long long n;
	while(cin>>n)
		cout<<calc(n)<<endl;

return 0;
}
