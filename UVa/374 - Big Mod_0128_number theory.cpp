/*
374 - Big Mod
*/

#include<iostream>

using namespace std;

int pow_mod(int b,int p,int m)
{
	if(!p)
		return 1;
	long long x=pow_mod(b,p/2,m);
	long long ans=x*x%m;
	if(p%2)
		ans=ans*b%m;
	return (int)ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int b,p,m;
	while(cin>>b>>p>>m)
		cout<<pow_mod(b,p,m)<<endl;

return 0;
}
