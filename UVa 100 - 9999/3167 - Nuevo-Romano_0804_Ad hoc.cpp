/*
3167 - Nuevo-Romano

Ad hoc....
ÔÓÌâ...
ÓÐÄÍÐÄÂýÂýÐ´°É...
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

char s[MAXN];
int a,b;
bool ok;
map<string,int> msi;
map<int,string> mis;
void init();

int digit(char *s)
{
	int l=strlen(s);
	for(int i=0;i<l;++i)
	{
		int j=l-1-i,t=s[i]-'0';
		while(j--)
			t*=10;
		cout<<mis[t];
	}
}

int alpha(char *str)
{
	int key=0;
	vector<int> vi;
	string s(str);
	int l=strlen(str);
	for(int i=0;i<l;++i)
	{
		int j=i+5;
		while(j>l)
			--j;
		while(msi.find(s.substr(i,j-i))==msi.end())
			--j;
		vi.push_back(msi[s.substr(i,j-i)]);
		key+=msi[s.substr(i,j-i)];
		i=j-1;
	}

	int sz=vi.size();
	for(int i=1;i<sz;++i)
		if(vi[i]>vi[i-1])
			ok=false;

	return key;
}

int trans(char *s)
{
	char *token=strtok(s,"O");
	vector<int> vi;
	int key=0;
	while(token)
	{
		vi.push_back(alpha(token));
		token=strtok(NULL,"O");
	}
	int sz=vi.size();
	for(int i=0;i<sz;++i)
		key=key*1000+vi[i];

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	while(scanf("%s",s)!=EOF)
	{
		ok=true;
		int l=0,p=-1;
		while(s[l])
		{
			s[l]=toupper(s[l]);
			if(s[l]=='+')
				p=l;
			++l;
		}

		if(p==-1)
		{
			puts("INVALID");
			continue;
		}

		s[p]=0;
		a=trans(s);
		b=trans(s+p+1);

		if(!ok)
			puts("INVALID");
		else
		{
			vector<int> vi;
			int t=a+b;
			while(t)
			{
				vi.push_back(t%1000);
				t/=1000;
			}

			int sz=vi.size();
			for(int i=sz-1;i>=0;--i)
			{
				if(i>=2 && vi[i]<=3)
					sprintf(s,"%d",vi[i--]*1000);
				else
					sprintf(s,"%d",vi[i]);
				digit(s);
				if(i)
					putchar('O');
			}

			printf("=%d\n",a+b);
		}
	}

	return 0;
}

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

	mis[3000000]="MMMO";
	mis[2000000]="MMO";
	mis[1000000]="MO";

	mis[900000]="CMO";
	mis[800000]="DCCCO";
	mis[700000]="DCCO";
	mis[600000]="DCO";
	mis[500000]="DO";
	mis[400000]="CDO";
	mis[300000]="CCCO";
	mis[200000]="CCO";
	mis[100000]="CO";

	mis[90000]="XCO";
	mis[80000]="LXXXO";
	mis[70000]="LXXO";
	mis[60000]="LXO";
	mis[50000]="LO";
	mis[40000]="XLO";
	mis[30000]="XXXO";
	mis[20000]="XXO";
	mis[10000]="XO";

	mis[9000]="IXO";
	mis[8000]="VIIIO";
	mis[7000]="VIIO";
	mis[6000]="VIO";
	mis[5000]="VO";
	mis[4000]="IVO";

	msi["MMMO"]=3000000;
	msi["MMO"]=2000000;
	msi["MO"]=1000000;

	msi["CMO"]=900000;
	msi["DCCCO"]=800000;
	msi["DCCO"]=700000;
	msi["DCO"]=600000;
	msi["DO"]=500000;
	msi["CDO"]=400000;
	msi["CCCO"]=300000;
	msi["CCO"]=200000;
	msi["CO"]=100000;

	msi["XCO"]=90000;
	msi["LXXXO"]=80000;
	msi["LXXO"]=70000;
	msi["LXO"]=60000;
	msi["LO"]=50000;
	msi["XLO"]=40000;
	msi["XXXO"]=30000;
	msi["XXO"]=20000;
	msi["XO"]=10000;

	msi["IXO"]=9000;
	msi["VIIIO"]=8000;
	msi["VIIO"]=7000;
	msi["VIO"]=6000;
	msi["VO"]=5000;
	msi["IVO"]=4000;
}
