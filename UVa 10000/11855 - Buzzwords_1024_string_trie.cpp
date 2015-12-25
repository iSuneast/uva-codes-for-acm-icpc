/*
11855 - Buzzwords

string...
TRIE...

build a TRIE use substring(s,e) 0<=s<e<=l
and just calc how many times it appears
total time O(n^2)
*/

#include<iostream>
#define MAXN 1003
using namespace std;

char str[MAXN];
int l;

void format()
{
	l=0;
	for(int i=0;str[i];++i)
	{
		if(str[i]!=' ')
			str[l++]=str[i];
	}
	str[l]=0;
}

struct TRIE
{
	char c;
	int cnt;
	TRIE *sibling,*son;
}root,data[1000000];
int key[MAXN],pos;

TRIE *NewNode()
{
	data[pos].son=data[pos].sibling=NULL;
	data[pos].cnt=0;
	return &data[pos++];
}

void insert(int s,int e)
{
	TRIE *cur=&root;
	int dep=1;
	for(;s<=e;++s,++dep)
	{
		if(!cur->son)
		{
			cur->son=NewNode();
			cur=cur->son;
		}
		else
		{
			cur=cur->son;
			while(cur->sibling)
			{
				if(cur->c!=str[s])
					cur=cur->sibling;
				else
					break;
			}

			if(cur->c!=str[s])
			{
				cur->sibling=NewNode();
				cur=cur->sibling;
			}
		}

		cur->c=str[s];
		key[dep]=max(key[dep],++cur->cnt);
	}
}

void process()
{
	memset(key,0,sizeof(key));
	root.sibling=root.son=0;
	pos=0;

	for(int i=0;i<l;++i)
		insert(i,l-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(gets(str) && str[0])
	{
		format();
		process();
		for(int i=1;i<=l;++i)
		{
			if(key[i]>1)
				printf("%d\n",key[i]);
			else
			{
				putchar(10);
				break;
			}
		}
	}

	return 0;
}
