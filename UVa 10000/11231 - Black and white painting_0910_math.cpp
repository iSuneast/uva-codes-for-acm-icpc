/*
11231 - Black and white painting

math...
try to divide the board into 8*8 small board
and find the law
*/

#include<iostream>
using namespace std;

int calc(int m,int c)
{
	if(c==0)
		return calc(m-1,1-c);
	if(m<8)
		return 0;
	return (m-8)/2+1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int n,m,c;
	while(scanf("%d%d%d",&n,&m,&c)!=EOF && (n||m||c))
	{
		int b=(n-7)/2,a=n-7-b;
		printf("%d\n",a*calc(m,c)+b*calc(m,1-c));
	}

	return 0;
}
