/*
902 - Password Search

Ad hoc...
brute force..
the input string maybe quite long...
so you'd better use a huge size array to handle to input...

just enum every string with length==required length
then check the most frequent string will done...
*/

#include<iostream>
#include<map>
#define SZ 26
#define MAXN 10000000
using namespace std;

char s[MAXN];
int cnt[MAXN],tot,sz;
long long data[MAXN];

void dfs(long long key,int dep)
{
	if(!dep)
		return ;
	dfs(key/SZ,dep-1);
	putchar(key%SZ+'a');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d%s",&sz,s)!=EOF)
	{
		int l=strlen(s);
		map<long long,int> mli;
		tot=0;
		for(int i=0;i+sz<=l;++i)
		{
			long long h=0;
			for(int j=i;j<i+sz;++j)
				h=h*SZ+s[j]-'a';

			if(mli.find(h)==mli.end())
			{
				data[tot]=h;
				cnt[tot]=0;
				mli[h]=tot++;
			}

			cnt[ mli[h] ]++;
		}

		int p=0;
		for(int i=1;i<tot;++i)
		{
			if(cnt[i]>cnt[p])
				p=i;
		}

		dfs( data[p],sz );
		putchar(10);
	}

	return 0;
}
