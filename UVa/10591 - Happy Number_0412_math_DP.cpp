/*
10591 - Happy Number

math...
DP打表优化...
*/

#include<iostream>
#define MAXN 1000
using namespace std;

int hash[MAXN];

int calc(int n)
{
	int t,s=0;
	while(n)
	{
		t=n%10;
		s+=t*t;
		n/=10;
	}
	if(hash[s])
		return hash[s];
	return hash[s]=calc(s);
}

int main()
{
//	freopen("in.txt","r",stdin);

	hash[1]=1;
	hash[4]=-1;
	int dataset,n;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>n;
		if(calc(n)==1)
			cout<<"Case #"<<cas<<": "<<n<<" is a Happy number."<<endl;
		else
			cout<<"Case #"<<cas<<": "<<n<<" is an Unhappy number."<<endl;
	}

	return 0;
}
