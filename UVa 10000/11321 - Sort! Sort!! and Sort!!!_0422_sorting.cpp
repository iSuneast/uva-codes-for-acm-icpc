/*
11321 - Sort! Sort!! and Sort!!!

sorting...
����ó���...
��Ϊ�ᳬʱ��...
����Ϲ�Ż�...
���Լ���Ū�ĺ�Ϳ��...
....
�����Ժ�û���ȷ������Ӷ�...
���Ӷ�ȷʵ�ܵ͵Ļ�...
�ͱ�����һ�°�...
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;

int num[MAXN],hash[MAXN],p[MAXN],n,m,i;

int cmp(const int a,const int b)
{
	int ma=a%m,mb=b%m;
	if(ma!=mb)
		return ma<mb;
	if((a&1) && (b&1))
		return a>b;
	else if(a&1)
		return 1;
	else if(b&1)
		return 0;
	return a<b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%d %d\n",n,m);
		if(!n && !m)
			break;
		for(i=0;i<n;++i)
			scanf("%d",num+i);
		sort(num,num+n,cmp);
		for(i=0;i<n;++i)
			printf("%d\n",num[i]);
	}

	return 0;
}
