/*
10334 - Ray Through Glasses

쳲�����...
�Ժ󿴵�1,2,3֮���Ҫ���ҹ��ɵ�...
�ȿ���fib...
�Ҿ����Լ�̫�ɱ���...
*/

#include<iostream>
using namespace std;

int f[5010][1050];
int i=2,n;

void fib()
{
	n+=2;
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
	j=1049;
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
		fib(),cout<<endl;

return 0;
}
