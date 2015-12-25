/*
11512 - GATTACA

string...
trie...
还不会后缀数组...
直接用字典树...
用所有后缀建一棵字典树..
求出最长且出现次数最多lcp即可...
*/

#include<iostream>
#define MAXN 4000003
#define MAXL 1003 
using namespace std;

struct TRIE
{
	TRIE *child[4];
	int cnt;
}trie[MAXN],root;
int h[128],tot,ans,len;
char str[MAXL],key[MAXL],buf[MAXL];

void clear(TRIE *cur)
{
	memset(cur->child,0,sizeof(cur->child));
	cur->cnt=0;
}

void insert(int s)
{
	TRIE *cur=&root;
	int st=s;
	while(str[s])
	{
		int p=h[ str[s] ];
		if(!cur->child[p])
		{
			cur->child[p]=&trie[tot++];
			clear(cur->child[p]);
		}
		cur=cur->child[p];
		++cur->cnt;
		if(cur->cnt>1)
		{
			int l=s-st+1;
			if(l>len)
			{
				len=l;
				ans=cur->cnt;
				strncpy(key,str+st,l);
			}
			else if(l==len)
			{
				strncpy(buf,str+st,l);
				buf[l]=key[l]=0;
				if(strcmp(key,buf)>0)
				{
					strcpy(key,buf);
					ans=cur->cnt;
				}
				else if(strcmp(key,buf)==0)
					ans=max(ans,cur->cnt);
			}
		}
		++s;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	h['A']=0;h['C']=1;h['G']=2;h['T']=3;
	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		clear(&root);	tot=0;

		scanf("%s",str);
		int l=strlen(str);
		ans=0;	len=0;
		for(int i=0;i<l;++i)
			insert(i);

		key[len]=0;
		if(ans>1)
			printf("%s %d\n",key,ans);
		else
			puts("No repetitions found!");
	}

	return 0;
}
