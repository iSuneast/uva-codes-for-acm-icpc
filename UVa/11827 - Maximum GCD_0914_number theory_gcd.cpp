/*
11827 - Maximum GCD

number theory...
gcd...
there is something wrong with judge's data
so you'd better use string to read line
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 103
using namespace std;

int var[MAXN];
string buf;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);	getline(cin,buf);
	while(dataset--)
	{
		int key=1,m=0;
		getline(cin,buf);
		stringstream sin(buf);
		while(sin>>var[m])
			++m;
		
		for(int i=0;i<m;++i)
			for(int j=i+1;j<m;++j)
				key=max(key,gcd(var[i],var[j]));

		printf("%d\n",key);
	}

	return 0;
}
