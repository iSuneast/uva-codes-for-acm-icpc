/*
377 - Cowculations

Ad hoc...
base conversion...
四进制问题...
该怎么做就怎么做...
*/

#include<iostream>
#define MAXN 15
using namespace std;

int hash[128];

void init()
{
	hash['V']=0;
	hash['U']=1;
	hash['C']=2;
	hash['D']=3;
}

int integer(char *s)
{
	int var=0,p=0;
	while(s[p])
		var=var*4+hash[ s[p++] ];
	return var;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	puts("COWCULATIONS OUTPUT");
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		char a[MAXN],b[MAXN],c[MAXN],op[MAXN];
		scanf("%s%s",a,b);
		int x=integer(a),y=integer(b),k=3;
		while(k--)
		{
			scanf("%s",op);
			if(op[0]=='A')
				y+=x;
			else if(op[0]=='R')
				y/=4;
			else if(op[0]=='L')
				y*=4;
		}

		scanf("%s",c);
		if(y==integer(c))
			puts("YES");
		else
			puts("NO");
	}
	puts("END OF OUTPUT");

	return 0;
}
