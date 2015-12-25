/*
10745 - Dominant Strings

trie...
ע�⵽˵�������Ƚ϶�,���ǵ��ʵĳ��Ⱥܶ�
���Կ��Կ���ö��ÿ�����ʵ��Ӽ����ɵ��´��Ƿ��Ѿ�����
���Ӷ�ֻ��O(N*2^LEN),��N�ܴ�ʱ,��Ȼ���ӶȱȽϵ�

�������е���,����
��ÿ��������ĸ��������һ��mirror
��mirror����һ���ֵ���

�����ֵ�����ö��mirror���Ӽ�,
Ȼ�����ֵ������������Ӽ��Ƿ����
���ڵĻ�,������Ӽ������ԭ�����ʾͲ��ǽ�

����Ҫע��һ��
��ab,ba�������,�������ʵ�mirror��ͻ,��������˭Ҳ����˭���Ӽ�
���������ʶ����ǽ�...
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
