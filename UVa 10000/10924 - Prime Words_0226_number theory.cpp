/*
10924 - Prime Words
*/

#include<iostream>
#include<string>

using namespace std;

char hash[128];
int prime[1200];

void init()
{
	int i;
	for(i='a';i<='z';i++)
		hash[i]=i-'a'+1;
	for(i='A';i<='Z';i++)
		hash[i]=i-'A'+27;
	memset(prime,-1,sizeof(prime));
	prime[0]=0;
	for(i=2;i<1200;i++)
		for(int j=i*i;j<1200;j+=i)
			prime[j]=0;
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	string s;
	while(getline(cin,s))
	{
		int key=0;
		string::iterator siter=s.begin();
		while(siter != s.end())
			key+=hash[*siter++];
		if(prime[key])
			cout<<"It is a prime word."<<endl;
		else
			cout<<"It is not a prime word."<<endl;
	}


return 0;
}
