/*
10139 - Factovisors

number theory.
����WA�ú����డ...
*/

#include<iostream>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 46350
using namespace std;

int n,m,prime[MAXN],tab[2][MAXN];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10139.txt","w",stdout);

	int i,j,cnt=0;

	prime[cnt++]=2;
	for(i=3;i<MAXN;i+=2)
		if(!prime[i])
		{
			prime[cnt++]=i;
			for(j=i;j<MAXN;j+=i)
				prime[j]=1;
		}

	while(cin>>n>>m)
	{
		if(!m)		//m=0�������.�޷�����
		{
			cout<<"0 does not divide "<<n<<"!"<<endl;
			continue;
		}
		else if(m==1 || m<=n)	//m=1 || m<=n һ����������.
		{
			cout<<m<<" divides "<<n<<"!"<<endl;
			continue;
		}
		memset(tab,0,sizeof(tab));
		int more=0,key=1e8,ans=m;	//ans��ʵ����ʽʹ��֮ǰ,����������ʱ����
		for(i=0;i<cnt && m!=1 && m;++i)
		{
			while(m%prime[i]==0)
			{
				m/=prime[i];
				tab[0][more]=prime[i];
				tab[1][more]++;
			}
			if(tab[0][more])
				++more;
		}
		if(m!=1 && m>n)		//���������m����,��m!=1��˵��mΪ������,����n�Ƚ�һ�´�С
		{
			cout<<ans<<" does not divide "<<n<<"!"<<endl;
			continue;
		}
		m=ans;
		for(i=0;i<more;++i)
		{
			ans=0;
			j=tab[0][i];
			while(n/j)
			{
				ans+=n/j;
				j=j*tab[0][i];
			}
			key=min(ans/tab[1][i],key);
		}

		if(key && more)	//�п���˵more=0
			cout<<m<<" divides "<<n<<"!"<<endl;
		else
			cout<<m<<" does not divide "<<n<<"!"<<endl;
	}

	return 0;
}
