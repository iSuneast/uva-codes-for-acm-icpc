/*
10062 - Tell me the frequencies!

听网站上大牛说...."Also don't print the blank line at the end of output."
恍然开朗....
*/

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

struct asc2
{
	char c;
	int n;
}asc[256];

int cmp(const void *a,const void *b)
{
	struct asc2 *x=(asc2 *)a;
	struct asc2 *y=(asc2 *)b;
	if(x->n!=y->n)
		return x->n-y->n;
	return y->c-x->c;
}

int main()
{
	string str;
	int i,flag=0;
	while(getline(cin,str))
	{
		if(flag)
			cout<<endl;
		memset(asc,0,sizeof(asc));
		for(i=0;i<256;i++)
			asc[i].c=i;
		for(i=0;i<str.length();i++)
			asc[str[i]].n++;
		qsort(asc,256,sizeof(asc[0]),cmp);
		for(i=0;i<256;i++)
			if(asc[i].n)
				printf("%d %d\n",asc[i].c,asc[i].n);
		flag=1;
	}

return 0;
}