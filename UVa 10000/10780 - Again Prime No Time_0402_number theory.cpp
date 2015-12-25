/*
10780 - Again Prime? No Time.

number theory..
thanks very much to zoro && overpower
*/

#include<iostream>
#define min(a,b) ((a)<(b))?(a):(b)
#define MAXN 10000
using namespace std;

int n,m,prime[MAXN],tab[2][MAXN];

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,i,j,cnt=0,cas=1;

	prime[cnt++]=2;
	for(i=3;i<MAXN;i+=2)		//素数表
		if(!prime[i])
		{
			prime[cnt++]=i;
			for(j=i;j<MAXN;j+=i)
				prime[j]=1;
		}

	cin>>dataset;
	while(dataset--)
	{
		cin>>n>>m;
		memset(tab,0,sizeof(tab));
		int more=0,key=1e8,ans;
		for(i=0;i<cnt && n!=1;++i)	//对n分解质因数
		{
			while(n%prime[i]==0)
			{
				n/=prime[i];
				tab[0][more]=prime[i];
				tab[1][more]++;
			}
			if(tab[0][more])
				++more;
		}

		for(i=0;i<more;++i)		//求解m!里面n的质因数的个数
		{
			ans=0;
			j=tab[0][i];
			while(m/j)
			{
				ans+=m/j;
				j=j*tab[0][i];
			}
			key=min(ans/tab[1][i],key);
		}

		cout<<"Case "<<cas++<<":"<<endl;
		if(key)
			cout<<key<<endl;
		else
			cout<<"Impossible to divide"<<endl;
	}

	return 0;
}
