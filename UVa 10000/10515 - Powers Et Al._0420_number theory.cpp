/*
10515 - Powers Et Al.

number theory...
就是传说中的规律很明显的题目...
一定要有信心把hash表手工打好...
*/

#include<iostream>
#include<string>
using namespace std;

int hash[10][4];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	
	hash[0][0]=hash[0][1]=hash[0][2]=hash[0][3]=0;
	hash[1][0]=hash[1][1]=hash[1][2]=hash[1][3]=1;
	hash[2][0]=2;hash[2][1]=4;hash[2][2]=8;hash[2][3]=6;
	hash[3][0]=3;hash[3][1]=9;hash[3][2]=7;hash[3][3]=1;
	hash[4][0]=4;hash[4][1]=6;hash[4][2]=4;hash[4][3]=6;
	hash[5][0]=hash[5][1]=hash[5][2]=hash[5][3]=5;
	hash[6][0]=hash[6][1]=hash[6][2]=hash[6][3]=6;
	hash[7][0]=7;hash[7][1]=9;hash[7][2]=3;hash[7][3]=1;
	hash[8][0]=8;hash[8][1]=4;hash[8][2]=2;hash[8][3]=6;
	hash[9][0]=9;hash[9][1]=1;hash[9][2]=9;hash[9][3]=1;
	string n,m;
	while(cin>>n>>m && (n!="0" || m!="0"))
	{
		if(m=="0")
		{
			cout<<1<<endl;
			continue;
		}
		int var_n=n[n.length()-1]-'0';
		int var_m=0;
		int l=m.length(),i,key=1;
		for(i=0;i<l;++i)
			var_m=(var_m*10+m[i]-'0')%4;
		cout<<hash[var_n][(var_m+3)%4]<<endl;
	}

	return 0;
}
