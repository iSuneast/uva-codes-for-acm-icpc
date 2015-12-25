/*
401 - Palindromes
*/

#include<iostream>
#include<string>
#include<ctype.h>
#include<cmath>

using namespace std;

char rev[128]={0};
int len,pa,mir,l,both;
string str0,str;

void init()
{
	rev['A']='A';
	rev['E']='3';
	rev['H']='H';
	rev['I']='I';
	rev['J']='L';
	rev['L']='J';

	rev['M']='M';
	rev['O']='O';
	rev['S']='2';
	rev['T']='T';
	rev['U']='U';
	rev['V']='V';
	rev['W']='W';
	rev['X']='X';

	rev['Y']='Y';
	rev['Z']='5';
	rev['1']='1';
	rev['2']='S';
	rev['3']='E';
	rev['5']='Z';
	rev['8']='8';
}

int main()
{
	int i;
	init();

	while(getline(cin,str0))
	{
		str=str0;
		pa=mir=both=0;
		len=str.length();
		for(i=0;i<len;i++)
		{
			if(str[i]=='0')
				str[i]='O';
		}

		l=(int)floor((double)len/2);

		for(i=0;i<l;i++)
		{
			if(str[i]==str[len-1-i])
			{
				pa++;
				if(str[i]==rev[str[i]])
					both++,mir++;
			}
			else if(rev[str[i]]==str[len-1-i])
				mir++;
			else
				break;
		}
		pa*=2;
		both*=2;
		mir*=2;
		if(len%2)
		{
			pa++;
			if(str[i]==rev[str[i]])
				both++,mir++;
		}
		if(both==len)
			cout<<str0<<" -- is a mirrored palindrome."<<endl<<endl;
		else if(pa==len)
			cout<<str0<<" -- is a regular palindrome."<<endl<<endl;
		else if(mir==len)
			cout<<str0<<" -- is a mirrored string."<<endl<<endl;
		else
			cout<<str0<<" -- is not a palindrome."<<endl<<endl;
	}

return 0;
}