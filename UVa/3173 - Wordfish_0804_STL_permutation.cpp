/*
3173 - Wordfish

STL...
permutation...
��prev_permutation,next_permutation���ǰ��10������
ȡ����Ԫ��ASCII��ֵ��С����������...
ע��߽����...
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define MAXN
#define INF 0x3f3f3f3f
#define eps 1e-9
using namespace std;

char dic[25][25];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(gets(dic[11]))
	{
		int l=strlen(dic[11]),p,key=0,s,e;
		for(s=10;s;--s)
		{
			strcpy(dic[s],dic[s+1]);
			if(!prev_permutation(dic[s],dic[s]+l))
				break;
		}

		for(e=12;e<=21;++e)
		{
			strcpy(dic[e],dic[e-1]);
			if(!next_permutation(dic[e],dic[e]+l))
				break;
		}

		for(int i=s;i<=e;++i)
		{
			int d=INF;
			for(int j=1;j<l;++j)
				d=min(d,abs(dic[i][j]-dic[i][j-1]));
			if(d>key)
			{
				key=d;
				p=i;
			}
		}

		printf("%s%d\n",dic[p],key);
	}

	return 0;
}
