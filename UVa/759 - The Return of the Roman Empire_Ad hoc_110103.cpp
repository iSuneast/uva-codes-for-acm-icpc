/*
 * 759 - The Return of the Roman Empire
 * 
 * Ad hoc...
 * keep getting WA for so mannnnnnnny times...
 * Oooooooops...
 * quite an easy problem indeed...
 * to many silly mistakes...
 * ..........
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

string s;
map<string,int> msi;

void init()
{
	msi["I"]=1;
	msi["II"]=2;
	msi["III"]=3;
	msi["IV"]=4;
	msi["V"]=5;
	msi["VI"]=6;
	msi["VII"]=7;
	msi["VIII"]=8;
	msi["IX"]=9;
	
	msi["X"]=10;
	msi["XX"]=20;
	msi["XXX"]=30;
	msi["XL"]=40;
	msi["L"]=50;
	msi["LX"]=60;
	msi["LXX"]=70;
	msi["LXXX"]=80;
	msi["XC"]=90;
	
	msi["C"]=100;
	msi["CC"]=200;
	msi["CCC"]=300;
	msi["CD"]=400;
	msi["D"]=500;
	msi["DC"]=600;
	msi["DCC"]=700;
	msi["DCCC"]=800;
	msi["CM"]=900;
	
	msi["M"]=1000;
	msi["MM"]=2000;
	msi["MMM"]=3000;	
}

int length(int n)
{
	int key=0;
	for(;n;n/=10)
		++key;
	return key;
}

int process()
{
	int key=0,pre=10000,t,l=s.length();
	for(int i=0,j;i<l;++i)
	{
		for(j=4;j>0;--j)
		{
			if(i+j>l)
				continue;
			if(msi.find(s.substr(i,j))!=msi.end())
			{
				t=msi[ s.substr(i,j) ];
				if(t>=pre || length(t)==length(pre))
					return -1;
				break;
			}
		}
		
		if(!j)
			return -1;
		i+=j-1;
		key+=t;
		pre=t;
	}
	
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    init();
    while(getline(cin,s))
    {
    	int key=process();
    	if(key==-1)
    		puts("This is not a valid number");
    	else
    		printf("%d\n",key);
    }

    return 0;
}

