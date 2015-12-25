/*
10393 - The One-Handed Typist

Ad hoc..

u have to read the problem description more careful next time.
*
* The words in the list should be distinct and 
* occur in alphabetical order. 
*
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int h[128];
vector<string> key;

void init()
{
	h['q']=h['a']=h['z']=1;
	h['w']=h['s']=h['x']=2;
	h['e']=h['d']=h['c']=3;
	h['r']=h['f']=h['v']=h['t']=h['g']=h['b']=4;
	h['y']=h['h']=h['n']=h['m']=h['j']=h['u']=7;
	h['i']=h['k']=8;
	h['o']=h['l']=9;
	h['p']=10;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int p,len,f,n;
	bool bk[13];
	char str[54];
	while(scanf("%d%d",&f,&n)!=EOF)
	{
		memset(bk,0,sizeof(bk));
		while(f--)
		{
			scanf("%d",&p);
			bk[p]=true;
		}

		len=0;
		key.clear();
		set<string> ss;
		while(n--)
		{
			scanf("%s",str);
			if(ss.find(str)==ss.end())
				ss.insert(str);
			else
				continue;

			int l=0;
			bool fade=false;
			for(;str[l] && !fade;++l)
				if(bk[ h[ str[l] ] ])
					fade=true;
			if(!fade)
			{
				if(l>len)
				{
					len=l;
					key.clear();
					key.push_back(str);
				}
				else if(l==len)
					key.push_back(str);
			}
		}

		printf("%d\n",key.size());
		sort(key.begin(),key.end());
		for(int i=0;i<key.size();++i)
			cout<<key[i]<<endl;
	}

	return 0;
}
