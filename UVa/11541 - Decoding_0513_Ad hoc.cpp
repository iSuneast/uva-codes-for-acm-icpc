/*
11541 - Decoding

Ad hoc...
*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	string s;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>s;
		printf("Case %d: ",cas);
		int var;
		char c;
		stringstream sin(s);
		while(sin>>c>>var)
		{
			for(int i=0;i<var;++i)
				putchar(c);
		}
		putchar('\n');
	}

	return 0;
}
