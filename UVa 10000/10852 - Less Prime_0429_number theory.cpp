/*
10852 - Less Prime

number theory...
��������...
�����ת��һ��ģ��..
����ͱ�úܼ���...
��һ��x<n,��xΪ����ʹ��n-p*x���...
p����p*x �� n < (p+1)*x...

���Ա���ö��,���Ʋ��ᳬʱ...
������һ�¾ͻᷢ��.
n-p*x���,��p*x<=n<(p+1)*x,��Ȼ��n%x���...
��ֻ������С��x,����2*x>n����
*/

#include<iostream>
#define MAXN 10010
using namespace std;

int prime[MAXN],cnt;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		if(prime[i]!=0)
			continue;
		prime[cnt++]=i;
		for(int j=i+i;j<MAXN;j+=i)
			prime[j]=-1;
	}
	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n;
		cin>>n;
		for(int i=0;i<cnt;++i)
			if(prime[i]*2>n)
			{
				cout<<prime[i]<<endl;
				break;
			}
	}

	return 0;
}
