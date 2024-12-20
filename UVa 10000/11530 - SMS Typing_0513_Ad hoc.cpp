/*
11530 - SMS Typing

hash...
直接打表映射即可...
*/

#include<iostream>
#include<string>
using namespace std;

string s;
int hash[128];

void init()
{
	hash['a']=1;
	hash['d']=1;
	hash['g']=1;
	hash['j']=1;
	hash['m']=1;
	hash['p']=1;
	hash['t']=1;
	hash['w']=1;
	hash[' ']=1;

	hash['b']=2;
	hash['e']=2;
	hash['h']=2;
	hash['k']=2;
	hash['n']=2;
	hash['q']=2;
	hash['u']=2;
	hash['x']=2;

	hash['c']=3;
	hash['f']=3;
	hash['i']=3;
	hash['l']=3;
	hash['o']=3;
	hash['r']=3;
	hash['v']=3;
	hash['y']=3;

	hash['s']=4;
	hash['z']=4;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	scanf("%d",&dataset);
	getline(cin,s);
	for(int cas=1;cas<=dataset;++cas)
	{
		getline(cin,s);
		int l=s.length(),key=0;
		for(int i=0;i<l;++i)
			key+=hash[s[i]];
		printf("Case #%d: %d\n",cas,key);
	}

	return 0;
}
