/*
10029 - Edit Step Ladders

DP...
DAG上的最长路...

建图过程
cat --> cat,`at,c`t,ca`,`cat,c`at,ca`t,cat`...
将这些值存入哈希表...
对其他字符串也是采取类似的操作...
发现冲突的话..直接开散列解决...
发现可以连接的有向边的话...
把边连接起来...同时置idx的pos信息为当前边...
这样求的的路径一定更长...
*/

#include<iostream>
#include<string>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 25010
#define MAXSZ 875011
#define token '`'
using namespace std;
typedef pair<string,int> psi;

vector<int> dag[MAXN];
vector<psi> idx[MAXSZ];
int cnt,dis[MAXN];

int hash(string s)
{
	int key=0,l=s.length();
	for(int i=0;i<l;++i)
		key=(s[i]-token+key*26)%MAXSZ;	//运算过程每步取模.防止溢出
	return key%MAXSZ;
}

void insert(string s)
{
	int var=hash(s);
	cout<<s<<endl;
	int sz=idx[var].size();
	for(int i=0;i<sz;++i)
		if(idx[var][i].first==s)
		{
			dag[cnt].push_back(idx[var][i].second);
			idx[var][i].second=cnt;		//改为当前的位置,求的的路径一定更长.
			return ;
		}
	idx[var].push_back(make_pair(s,cnt));
}

int dp(int p)
{
	if(dis[p])
		return dis[p];
	dis[p]=1;
	int sz=dag[p].size();
	for(int i=0;i<sz;++i)
	{
		int t=dp(dag[p][i]);
		dis[p]=max(dis[p],t+1);
	}
	return dis[p];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string buf;
	char c;
	int i;
	while(cin>>buf)
	{
		insert(buf);
		int l=buf.length();
		for(i=0;i<l;++i)
		{
			c=buf[i];
			buf[i]=token;
			insert(buf);
			buf[i]=c;
		}
		if(l!=16)
			for(i=0;i<=l;++i)
				insert((buf.substr(0,i)+token+buf.substr(i,l)));
		++cnt;
	}
	int key=0;
	for(i=0;i<=cnt;++i)
	{
		if(!dis[i])
			dp(i);
		key=max(key,dis[i]);
	}
	cout<<key<<endl;

	return 0;
}
