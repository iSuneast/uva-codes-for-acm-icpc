/*
895 - Word Problem

hash...
strings...
估计是我想多了...
这题应该是没有那么复杂的吧...
除了求哈希值以外还要求字符串的子集...
不知道算不算DP哈...
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 1010
#define BASE 8
using namespace std;

char dic[MAXN][15];
char buf[MAXN],tmp[15],sss[255];
bool hash[2097200];

int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}

void init(int cnt)
{
	memset(sss,0,sizeof(sss));
	int p=1;
	for(int i=0;i<cnt;++i)
		if(!sss[buf[i]])
			sss[buf[i]]=p++;
	memset(hash,0,sizeof(hash));
}

int h(char *a,int l)
{
	int key=0;
	for(int i=0;i<l;++i)
		key=key*8+sss[a[i]];
	if(hash[key])
		return true;
	hash[key]=true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int cnt=0;
	while(gets(dic[cnt]) && dic[cnt][0]!='#')
	{
		sort(dic[cnt],dic[cnt]+strlen(dic[cnt]));
		++cnt;
	}
	qsort(dic,cnt,sizeof(dic[cnt]),cmp);
	while(gets(buf) && buf[0]!='#')
	{
		int l=strlen(buf),p=0,key=0;
		for(int i=0;i<l;++i)
			if(buf[i]!=' ')
				buf[p++]=buf[i];
		buf[p]=0;
		sort(buf,buf+p);
		init(p);
		int tot=1<<p;
		for(int i=1;i<tot;++i)
		{
			int len=0;
			for(int j=0;j<p;++j)
				if((1<<j)&i)
					tmp[len++]=buf[j];
			tmp[len]=0;
			if(h(tmp,len))
				continue;
			char *p=(char *)bsearch(tmp,dic,cnt,sizeof(dic[cnt]),cmp);
			if(p!=NULL)
			{
				int pos=(p-dic[0])/sizeof(dic[cnt]),t;
				t=pos;
				while(t<cnt && !strcmp(tmp,dic[t]))
					++t,++key;
				t=pos-1;
				while(t>=0 && !strcmp(tmp,dic[t]))
					--t,++key;
			}
		}
		printf("%d\n",key);
	}

	return 0;
}
