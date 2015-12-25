/*
10579 - Fibonacci Numbers

number theory...
Bign.
*/

#include<iostream>
#define MAXN 1050
using namespace std;

int f[5010][MAXN];
int i=2,n;

void fib()
{
	int j,k,carry;
	for(;i<=n;i++)
	{
		carry=0;
		j=1049;
		while(!f[i-1][j])
			j--;
		for(k=0;k<=j;k++)
		{
			f[i][k]=f[i-1][k]+f[i-2][k]+carry;
			if(f[i][k]>=10)
			{
				f[i][k]%=10;
				carry=1;
			}
			else
				carry=0;
		}
		f[i][k]=carry;
	}
	j=MAXN-1;
	while(!f[n][j])
		j--;
	do
	cout<<f[n][j];
	while(j--);
}

int main()
{
//	freopen("in.txt","r",stdin);

	memset(f,0,sizeof(f));
	f[1][0]=1;
	while(cin>>n)
		if(n)
			fib(),cout<<endl;
		else
			cout<<0<<endl;

return 0;
}
