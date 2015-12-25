/*
10008 - What's Cryptanalysis?
*/

#include<iostream>
#include<string>
#include<ctype.h>
#include<cstdlib>

using namespace std;

struct alpha
{
	int n;
	char c;
}c[26]={0};

int cmp_n(const void *a,const void *b)
{
	struct alpha *x=(alpha *)a;
	struct alpha *y=(alpha *)b;
	if(x->n!=y->n)
		return y->n-x->n;
	return x->c-y->c;
}

int main()
{
	int cas,i;
	string str;

	for(i='A';i<='Z';i++)
		c[i-'A'].c=i;
	cin>>cas;getchar();
	while(cas--)
	{
		getline(cin,str);
		for(i=0;i<str.length();i++)
			if(isalpha(str[i]))
				c[toupper(str[i])-'A'].n++;
	}
	qsort(c,26,sizeof(c[0]),cmp_n);
	for(i=0;i<26;i++)
			if(c[i].n)
				printf("%c %d\n",c[i].c,c[i].n);
return 0;
}