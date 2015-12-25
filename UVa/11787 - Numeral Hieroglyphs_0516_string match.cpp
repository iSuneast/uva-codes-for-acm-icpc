/*
11787 - Numeral Hieroglyphs

string...
简单的字符串映射的题目.
*/

#include<iostream>
#define MAXN 128
using namespace std;

int hash[MAXN],var[MAXN];
const char lis[]="BUSPFTM";

void init()
{
	hash['B']=1;
	hash['U']=10;
	hash['S']=100;
	hash['P']=1000;
	hash['F']=10000;
	hash['T']=100000;
	hash['M']=1000000;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	string s;
	scanf("%d",&dataset);
	while(dataset--)
	{
		cin>>s;
		int l=s.length(),cur=1000000;
		memset(var,0,sizeof(var));
		bool error=false;
		for(int i=0;i<l;++i)
			if(cur>=hash[ s[i] ])
			{
				cur=hash[ s[i] ];
				++var[ s[i] ];
			}
			else
			{
				error=true;
				break;
			}
			if(error)
			{
				error=false;
				cur=0;
				memset(var,0,sizeof(var));
				for(int i=0;i<l;++i)
				{
					if(cur<=hash[ s[i] ])
					{
						cur=hash[ s[i] ];
						++var[ s[i] ];
					}
					else
					{
						error=true;
						break;
					}
				}
			}
			int key=0;
			if(!error)
				for(int i=0;i<=6;++i)
				{
					if(var[ lis[i] ]>9)
					{
						error=true;
						break;
					}
					key+=hash[ lis[i] ]*var[ lis[i] ];
				}
				if(error)
					puts("error");
				else
					printf("%d\n",key);
	}

	return 0;
}
