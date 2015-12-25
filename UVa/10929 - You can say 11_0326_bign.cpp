/*
10929 - You can say 11

Bign...
*/

#include<iostream>
#include<cstring>
#define MAXLEN 1010
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char bign[MAXLEN];
	while(gets(bign) && strcmp(bign,"0"))
	{
		int remain=0,l=strlen(bign)-1;
		for(;l>=0;--l)
			remain=(remain*10+bign[l]-'0')%11;
		cout<<bign<<" is "
			<<(remain==0?"":"not ")
			<<"a multiple of 11."<<endl;;
	}

return 0;
}
