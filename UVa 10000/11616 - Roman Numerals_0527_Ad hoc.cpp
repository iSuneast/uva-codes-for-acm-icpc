/*
11616 - Roman Numerals

Ad hoc...
直接map打表映射即可...
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

string s;
int l;
map<int,string> mis;
map<string,int> msi;

void init()
{
	mis[3000]="MMM";
	mis[2000]="MM";
	mis[1000]="M";

	mis[900]="CM";
	mis[800]="DCCC";
	mis[700]="DCC";
	mis[600]="DC";
	mis[500]="D";
	mis[400]="CD";
	mis[300]="CCC";
	mis[200]="CC";
	mis[100]="C";

	mis[90]="XC";
	mis[80]="LXXX";
	mis[70]="LXX";
	mis[60]="LX";
	mis[50]="L";
	mis[40]="XL";
	mis[30]="XXX";
	mis[20]="XX";
	mis[10]="X";

	mis[9]="IX";
	mis[8]="VIII";
	mis[7]="VII";
	mis[6]="VI";
	mis[5]="V";
	mis[4]="IV";
	mis[3]="III";
	mis[2]="II";
	mis[1]="I";

	msi["MMM"]=3000;
	msi["MM"]=2000;
	msi["M"]=1000;

	msi["CM"]=900;
	msi["DCCC"]=800;
	msi["DCC"]=700;
	msi["DC"]=600;
	msi["D"]=500;
	msi["CD"]=400;
	msi["CCC"]=300;
	msi["CC"]=200;
	msi["C"]=100;

	msi["XC"]=90;
	msi["LXXX"]=80;
	msi["LXX"]=70;
	msi["LX"]=60;
	msi["L"]=50;
	msi["XL"]=40;
	msi["XXX"]=30;
	msi["XX"]=20;
	msi["X"]=10;

	msi["IX"]=9;
	msi["VIII"]=8;
	msi["VII"]=7;
	msi["VI"]=6;
	msi["V"]=5;
	msi["IV"]=4;
	msi["III"]=3;
	msi["II"]=2;
	msi["I"]=1;
}

void digit()
{
	for(int i=0;i<l;++i)
	{
		int j=l-1-i,t=s[i]-'0';
		while(j--)
			t*=10;
		cout<<mis[t];
	}
}

void alpha()
{
	int key=0;
	for(int i=0;i<l;++i)
	{
		int j=i+4;
		while(j>l)
			--j;
		while(msi.find(s.substr(i,j-i))==msi.end())
			--j;
		key+=msi[s.substr(i,j-i)];
		i=j-1;
	}
	cout<<key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(cin>>s)
	{
		l=s.length();
		if(isdigit(s[0]))
			digit();
		else
			alpha();
		cout<<endl;
	}

	return 0;
}
