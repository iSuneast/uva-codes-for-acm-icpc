/*
106 - Fermat vs. Pythagoras

number theory...
simple math...
����1300ms,�չ�...

���������...
��������̫�����Ƿ�����...

��Ŀ�ܺ����,���������������Ҳ������= =..
���۵���Ŀ��������...
�����֪ʶ����,����ǰ�����·���...

�� a^2+b^2=c^2����������...
�� x=m*m-n*n ,y=2*m*n ,z=m*m+n*n
���ʱֻ��Ҫ����������x,y,z������m,n����...
�����ɹ�...
*/

#include<iostream>
#define MAXN 1000001
using namespace std;
int flag[MAXN];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n,i,j,x,y,z;
	while(cin>>n)
	{
		int key=0,cnt=n;
		memset(flag,0,sizeof(flag));
		for(i=1;i*i<=n;++i)
			for(j=1;j<i;++j)
			{
				x=i*i-j*j;
				y=2*i*j;
				z=i*i+j*j;
				if(z>n)
					continue;
				for(int k=1;k*z<=n;++k)		//������б���.
					flag[x*k]=flag[y*k]=flag[z*k]=1;
				if(gcd(x,y)!=1 || gcd(x,z)!=1 || gcd(y,z)!=1)
					continue;
				++key;
			}
		for(i=1;i<=n;++i)
			if(flag[i])
				--cnt;
		cout<<key<<' '<<cnt<<endl;
	}
	return 0;
}
