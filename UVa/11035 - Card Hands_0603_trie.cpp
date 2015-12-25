/*
11035 - Card Hands

trie...
直接开数组会暴内存...
所以只能用链表开动态的.
鉴于本题为[52]的多叉树.
但是会有很多没用的节点占用了大部分的空间
所以考虑用左儿子右兄弟来表示节点间的关系.
以时间换空间...
*/

#include<iostream>
#define MAX_CARDS 53
#define CARRY 13
using namespace std;

char card[MAX_CARDS],buf[5];
char mapping[128];
int n,p,len;

void init()
{
	mapping['A']=0;
	mapping['2']=1;
	mapping['3']=2;
	mapping['4']=3;
	mapping['5']=4;
	mapping['6']=5;
	mapping['7']=6;
	mapping['8']=7;
	mapping['9']=8;

	mapping['J']=10;
	mapping['Q']=11;
	mapping['K']=12;

	mapping['C']=0;
	mapping['D']=1;
	mapping['H']=2;
	mapping['S']=3;
}

struct TRIE
{
	TRIE *child,*sibling;
	char c;
	TRIE() {child=NULL;sibling=NULL;c=-1;}
}root;

void insert(char *s,int l)
{
	TRIE *cur=&root;
	while(l--)
	{
		if(cur->child==NULL)
		{
			cur->child=new TRIE;
			++p;
			cur=cur->child;
			cur->c=s[l];
			continue;
		}
		cur=cur->child;
		while(cur->c!=s[l])
		{
			if(cur->sibling==NULL)
			{
				cur->sibling=new TRIE;
				++p;
				cur=cur->sibling;
				cur->c=s[l];
				break;
			}
			cur=cur->sibling;
		}
	}
}

void free_all()
{
	root.child=NULL;
	root.sibling=NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	while(scanf("%d",&n)!=EOF && n)
	{
		free_all();
		for(int i=0;i<n;++i)
		{
			scanf("%d",&len);
			for(int j=0;j<len;++j)
			{
				scanf("%s",buf);
				if(!buf[2])
					card[j]=mapping[ buf[0] ]+CARRY*mapping[ buf[1] ];
				else
					card[j]=9+CARRY*mapping[ buf[2] ];
			}
			insert(card,len);
		}
		printf("%d\n",p);
		p=0;
	}

	return 0;
}

