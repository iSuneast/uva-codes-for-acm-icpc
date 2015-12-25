/*
455 - Periodic Strings
...
string
йт....
*/

#include<iostream>
#include<cstring>

using namespace std;

int n,i,j,l;
char c[100];

int calc()
{
	for(j=i;j<l;j++)
		if(c[j]!=c[j%i])
			return 0;
	cout<<i<<endl;
	return 1;
}

int main()
{
	cin>>n;getchar();
	while(n--)
	{
		getchar();
		gets(c);
		l=strlen(c);
		for(i=1;i<=l;i++)
			if(l%i==0&&calc())
				break;
		if(n)
			putchar('\n');
	}

return 0;
}
