/*
10029 - Edit Step Ladders

DP...
DAG�ϵ��·...

��ͼ����
cat --> cat,`at,c`t,ca`,`cat,c`at,ca`t,cat`...
����Щֵ�����ϣ��...
�������ַ���Ҳ�ǲ�ȡ���ƵĲ���...
���ֳ�ͻ�Ļ�..ֱ�ӿ�ɢ�н��...
���ֿ������ӵ�����ߵĻ�...
�ѱ���������...ͬʱ��idx��pos��ϢΪ��ǰ��...
������ĵ�·��һ������...
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
		key=(s[i]-token+key*26)%MAXSZ;	//�������ÿ��ȡģ.��ֹ���
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
			idx[var][i].second=cnt;		//��Ϊ��ǰ��λ��,��ĵ�·��һ������.
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
