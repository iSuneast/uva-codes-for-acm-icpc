/*
10049 - Self-describing Sequence

dp...
��ʵ����һ�����ֲ�����Ŀ...
����ÿ��i��f(i)ֵ
ȷ����ǰi�ĳ�ʼλ��
Ȼ���ÿ��ѯ�ʶ��ֲ��Ҽ���...
*/

#include<iostream>
#include<algorithm>
#define MAXN 673366
using namespace std;

int f[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	f[1]=1;	f[2]=2;
	for(int i=3;i<MAXN;++i)
	{
		f[i]=lower_bound(f+1,f+i,i)-f;
		f[i]+=f[i-1]-1;
	}

	int n;
	while(scanf("%d",&n)!=EOF && n)
		printf("%d\n",upper_bound(f+1,f+MAXN,n)-f-1);

	return 0;
}
