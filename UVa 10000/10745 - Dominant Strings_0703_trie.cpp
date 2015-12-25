/*
10745 - Dominant Strings

trie...
注意到说单词数比较多,但是单词的长度很短
所以可以考虑枚举每个单词的子集构成的新词是否已经存在
复杂度只有O(N*2^LEN),当N很大时,显然复杂度比较低

读入所有单词,排序
对每个单词字母排序后存入一个mirror
用mirror建立一颗字典树

建好字典树后枚举mirror的子集,
然后再字典树里面搜索子集是否存在
存在的话,则这个子集代表的原来单词就不是解

此外要注意一下
如ab,ba这种情况,两个单词的mirror冲突,所以他们谁也不是谁的子集
即两个单词都不是解...
*/

#include<iostream>
#include<algorithm>
#define MAXLEN 13
#define MAXN 15010
using namespace std;

struct TRIE
{
	char c;
	int pos;
	TRIE *child,*sibling;
	TRIE(){c=0;pos=-1;child=sibling=NULL;}
}root;

char mirror[MAXN][MAXLEN],dic[MAXN][MAXLEN],buf[MAXLEN];
int tot=0,l[MAXN];
bool flag[MAXN];

void insert(char *s,int pos)
{
	TRIE *cur=&root;
	int p=0;
	while(s[p])
	{
		if(!cur->child)
		{
			cur->child=new TRIE;
			cur=cur->child;
			cur->c=s[p++];
			continue;
		}
		cur=cur->child;
		while(cur->c!=s[p] && cur->sibling)
			cur=cur->sibling;
		if(cur->c!=s[p])
		{
			cur->sibling=new TRIE;
			cur=cur->sibling;
			cur->c=s[p++];
		}
		else
			++p;
	}
	if(cur->pos!=-1)
		flag[cur->pos]=flag[pos]=true;
	cur->pos=pos;
}

int dfs(char *s)
{
	TRIE *cur=&root;
	int p=0;
	while(s[p])
	{
		if(!cur->child)
			return -1;
		cur=cur->child;
		while(cur->c!=s[p] && cur->sibling)
			cur=cur->sibling;
		if(cur->c!=s[p++])
			return -1;
	}
	return cur->pos;
}

void chk(char *s,int sl)
{
	for(int j=1;j<(1<<sl)-1;++j)
	{
		int len=0;
		for(int k=0;k<sl;++k)
			if((1<<k)&j)
				buf[len++]=s[k];
		buf[len]=0;
		int pos=dfs(buf);
		if(pos!=-1)
			flag[pos]=true;
	}
}

int cmp(const void *a,const void *b)
{
	return strcmp( (char *)a,(char *)b );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%s",dic[tot])!=EOF)
		++tot;
	qsort(dic,tot,sizeof(dic[0]),cmp);

	for(int i=0;i<tot;++i)
	{
		strcpy(mirror[i],dic[i]);
		l[i]=strlen(mirror[i]);
		sort(mirror[i],mirror[i]+l[i]);
		insert(mirror[i],i);
	}

	for(int i=0;i<tot;++i)
		chk(mirror[i],l[i]);

	for(int i=0;i<tot;++i)
		if(!flag[i])
			puts(dic[i]);

	return 0;
}
