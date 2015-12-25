/*
4677 - Interleaved Periodic String

Ad hoc..
string...
其实只有
'1''0'
'1'
'0'
''
四种情况...
*/

#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<ctime>
#define MAXN
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

char s[20],s1[20],s2[20];
bool inside(int j,int i)
{
	return (1<<j)&i;
}

int kmp(char *s,int l)
{
	for(int i=1;i<=l;++i)
		if(l%i==0)
		{
			bool bk=false;
			for(int j=0;j<i && !bk;++j)
				for(int k=i;k<l && !bk;k+=i)
					if(s[j]!=s[k])
						bk=true;
			if(!bk)
				return i;
		}
		return l;
}

int main()
{

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",s);
		int l=strlen(s);
		int p1,p2,p=INF;
		for(int i=0;i<(1<<l);++i)
		{
			p1=p2=0;
			for(int j=0;j<l;++j)
				if(inside(j,i))
					s1[p1++]=s[j];
				else
					s2[p2++]=s[j];
			p=min(p,kmp(s1,p1)+kmp(s2,p2));
		}
		printf("%d\n",p);
	}

	return 0;
}
