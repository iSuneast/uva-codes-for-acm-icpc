/*
501 - Black Box

bit...
��״����...
����д����...

�ܲ�����������ݽṹ...
�ȶ�����������,���±�󶨺�����...
һ��ɨ���¼��Ԫ���ź��������±�...
Ȼ����ͷ��βɨ��.
ģ�����Ԫ��...�ö���+��Ͷ�λ��kСԪ��...
���ְ�......
*/

#include<iostream>
#include<algorithm>
#define MAXN 30014
#define lowbit(v) ((v)&(-v))
using namespace std;
typedef pair<int,int> pii;

pii var[MAXN];
int s[MAXN],m,n,num[MAXN],pos[MAXN];
int query[MAXN],t;

void insert(int v)
{
	while(v<=m)
	{
		++s[v];
		v+=lowbit(v);
	}
}

int sum(int v)
{
	int key=0;
	while(v)
	{
		key+=s[v];
		v-=lowbit(v);
	}
	return key;
}

int b_located(int p)
{
	int l=1,r=m,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		int key=sum(mid);
		if(key<p)
			l=mid+1;
		else
			r=mid;
	}
	return r;
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
		memset(query,0,sizeof(query));
		memset(s,0,sizeof(s));

		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&num[i]);
			var[i]=make_pair(num[i],i);
		}
		sort(var+1,var+m+1);
		for(int i=1;i<=m;++i)
			pos[ var[i].second ]=i;

		for(int i=0;i<n;++i)
		{
			scanf("%d",&t);
			++query[t];
		}
		int p=0;
		for(int i=1;i<=m;++i)
		{
			insert(pos[i]);
			while(query[i]--)
				printf("%d\n",var[ b_located(++p) ].first );
		}

		if(dataset)
			putchar('\n');
	}

	return 0;
}
