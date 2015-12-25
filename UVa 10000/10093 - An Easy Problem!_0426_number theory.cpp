/*
10093 - An Easy Problem!

number theory...
神奇的数论...
神奇的代码...

如果一个m进制的数能被m-1整除,则这个数的个个数字之和一定可以被m-1整除...
*/

#include<iostream>
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

string var;

int hash(char c)
{
	if(isdigit(c))
		return c-'0';
	else if(isupper(c))
		return c-'A'+10;
	else if(islower(c))
		return c-'a'+36;		//这里是加36..不是加26...
	else
		return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>var)
	{
		int key=0,base=2,l=var.length(),h,i;
		for(i=0;i<l;++i)
		{
			h=hash(var[i]);
			base=max(base,h+1);
			key+=h;
		}
		bool got=false;
		for(;base<=62;++base)
			if(key%(base-1)==0)
			{
				got=true;
				break;
			}
		if(got)
			cout<<base<<endl;
		else
			puts("such number is impossible!");
	}

	return 0;
}
