/*
545 - Heads

brute force...
ֱ�ӱ�����...
���Ǿ�������...
key<1.0 ��ʱ��, key*=10 ,Ȼ�� ++λ��
��������ʱ��keyҪ����һ��eps...
*/

#include<iostream>
#define eps 1e-9
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		double key=1.0;
		int cnt=0,n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			key/=2.0;
			while(key<1.0)
			{
				key*=10.0;
				++cnt;
			}
		}
		printf("2^-%d = %.3lfE-%d\n",n,key+eps,cnt);
	}

	return 0;
}
