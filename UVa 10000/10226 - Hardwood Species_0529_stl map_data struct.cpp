/*
10226 - Hardwood Species

ds...
本来应该是靠数据结构的...
肯定是要用平衡二叉树来做的...
没想到用map就可以直接过了...
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 10010
using namespace std;

struct BST
{
	char name[33];
	int cnt;
	bool operator<(const BST &t)const
	{
		return strcmp(name,t.name)<0;
	}
}bst[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);	gets(bst[0].name);	gets(bst[0].name);
	while(dataset--)
	{
		int cnt=0,tot=0,key;
		map<string,int> msi;
		for(int i=0;i<MAXN;++i)
			bst[i].cnt=0;
		while(gets(bst[cnt].name) && bst[cnt].name[0])
		{
			++tot;
			key=0;
			if(msi.find(bst[cnt].name)==msi.end())
				msi[ bst[cnt].name ]=cnt,key=1;
			bst[ msi[ bst[cnt].name ] ].cnt++;
			cnt+=key;
		}
		sort(bst,bst+cnt);
		for(int i=0;i<cnt;++i)
			printf("%s %.4lf\n",bst[i].name,bst[i].cnt*100.0/tot);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
