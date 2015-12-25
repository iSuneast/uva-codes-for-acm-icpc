/*
11029 - Leading and Trailing

math...
Ϊʲô�ĳ�longlong�͹���...

ans=n^k=10^(log10(n^k))
	��t=log10(n^k)=k*log10(n)=t(С������)+t(��������)
ans=10^(k*log10(n))=10^t=10^(t(С))*10^(t(��))
����10^(t(��))=10000...������ʱʡ��
���10^(t(С))*100���ǽ���...
*/

#include<iostream>
#include<cmath>
#define MOD 1000
using namespace std;

int pow_mod(int n,int k)
{
	if(!k)
		return 1;
	int key=pow_mod(n,k>>1);
	key=key*key%MOD;
	if(k&1)
		key=key*n%MOD;
	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		long long n,k;
		cin>>n>>k;
		double log_ans=log10(1.0*n)*k;
		log_ans-=floor(log_ans);

		printf("%03d...%03d\n",(int)floor(pow(10.0,log_ans)*100),pow_mod(n%MOD,k));
	}

	return 0;
}
