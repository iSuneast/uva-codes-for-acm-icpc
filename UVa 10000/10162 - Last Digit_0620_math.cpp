/*
10162 - Last Digit

math...
n^n其实是有循环状态的...
(n+100)^(n+100)%10==n^n%10
所以只要枚举到100就可以了..
*/

#include<iostream>
#include<string>
#define MAXN 101
using namespace std;

int key[MAXN],hash[10][2];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	hash[0][0]=hash[0][1]=0;
	hash[1][0]=hash[1][1]=1;
	hash[2][0]=4;	hash[2][1]=6;
	hash[3][0]=7;	hash[3][1]=3;
	hash[4][0]=hash[4][1]=6;
	hash[5][0]=hash[5][1]=5;
	hash[6][0]=hash[6][1]=6;
	hash[7][0]=3;	hash[7][1]=7;
	hash[8][0]=6;	hash[8][1]=4;
	hash[9][0]=hash[9][1]=9;

	memset(key,0,sizeof(key));
	for(int i=1;i<MAXN;++i)
		key[i]=(key[i-1]+hash[ i%10 ][ (i/10)&1 ])%10;

	string s;
	while(cin>>s && s!="0")
	{
		if(s.length()>2)
			s=s.substr(s.length()-2,2);
		cout<<key[ atoi(s.c_str()) ]<<endl;
	}

	return 0;
}
