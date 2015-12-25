/*
10303 - How Many Trees?

catalan...
*/

#include<iostream>
using namespace std;
#define MAXLEN 125
#define MOD 100000

unsigned int n[MAXLEN];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10303.txt","w",stdout);

	int m,carry,t,i,j;
	while(cin>>m)
	{
		memset(n,0,sizeof(n));
		n[0]=1;
		m+=2;
		for(i=4;i<=m;i++)
		{
			carry=0;
			t=(4*i-10);
			for(j=0;j<MAXLEN;j++)
			{
				n[j]=n[j]*t+carry;
				carry=n[j]/MOD;
				n[j]%=MOD;
			}
			j=MAXLEN-1;
			while(!n[j])
				--j;
			for(carry=0,t=i-1;j>=0;--j)
			{
				carry=carry*MOD+n[j];
				n[j]=carry/t;
				carry%=t;
			}
		}
		i=MAXLEN-1;
		while(!n[i])
			--i;
		printf("%d",n[i--]);
		for(;i>=0;i--)
			printf("%05d",n[i]);
		putchar('\n');
	}

return 0;
}
