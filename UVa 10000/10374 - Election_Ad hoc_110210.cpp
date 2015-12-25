/*
 * 10374 - Election
 *
 * Ad hoc...
 * ӳ��һ��, ͳ�ƾͿ�����...
 * ��map�Ļ�, �ͺܼ���..
 *
 * ����, ��������...��ȻWA��һ��, Ȼ��������Ϊn,m�����ж���Ŀո�...
 * ���ݲ��淶��= =
 *
 * happy coding~
 */

#include<iostream>
#include<cstdio>
#include<map>
#define MAXN 23
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, cnt[MAXN], n, m;
	char name[100], party[MAXN][100];

	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);	gets(name);
		map<string,int> msi;
		for(int i=0;i<n;++i)
		{
			gets(name);  msi[name]=i;
			gets(party[i]);
			cnt[i]=0;
		}

		scanf("%d",&m);	gets(name);
		while(m--)
		{
			gets(name);
			if(msi.find(name)!=msi.end())
				++cnt[ msi[name] ];
		}

		int key=-1,p;
		bool ok=false;
		for(int i=0;i<n;++i)
		{
			if(cnt[i]>key)
			{
				key=cnt[p=i];
				ok=true;
			}
			else if(cnt[i]==key)
				ok=false;
		}

		if(ok)
			puts(party[p]);
		else
			puts("tie");

		if(dataset)
			putchar(10);
	}

	return 0;
}
