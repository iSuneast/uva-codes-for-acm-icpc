/*
10789 - Prime Frequency

number theory..
顺便加了点hash实现进去...
问题就变得很简单啦...
*/

#include<iostream>
#include<string>
#define MAXN 2010
using namespace std;
int prime[MAXN],hash[256];

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j;
	prime[0]=prime[1]=1;
	for(i=2;i<MAXN;++i)
		for(j=i*2;j<MAXN;j+=i)
			prime[j]=1;
	int dataset;
	string str;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>str;
		j=str.length();
		memset(hash,0,sizeof(hash));
		for(i=0;i<j;++i)
			++hash[str[i]];
		bool got=false;
		cout<<"Case "<<cas<<": ";
		for(i=0;i<256;++i)
			if(!prime[hash[i]])
			{
				cout<<(char)i;
				got=true;
			}
		if(!got)
			cout<<"empty";
		cout<<endl;
	}

	return 0;
}
