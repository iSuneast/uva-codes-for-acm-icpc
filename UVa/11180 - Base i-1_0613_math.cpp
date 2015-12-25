/*
11180 - Base i-1

math...
a+bi=(c+di)*(i-1)+e
=>
	c=(-a+b+e)/2
	d=(-a-a+e)/2
*/

#include<iostream>
using namespace std;

void print(int a,int b)
{
	if(!a && !b)
		return ;
	if(abs(a+b)&1)
	{
		print((-a+b+1)/2,(-a-b+1)/2);
		putchar('1');
	}
	else
	{
		print((-a+b)/2,(-a-b)/2);
		putchar('0');
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("Case #%d: ",cas);
		if(!a && !b)
			putchar('0');
		else
			print(a,b);
		putchar('\n');
	}

	return 0;
}
