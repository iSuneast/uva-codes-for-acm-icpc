/*
148 - Anagram checker

graph theory...
������...����ͼ�۰�...
��¼������,Ȼ�������ַ����Ϳ�����

����Ҫע��˵
�������Ľ⴮�����ĵ��ʲ��ܺ�ԭ����ȫ��ͬ..
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#define MAXN 2010
#define ALPHA 30
using namespace std;

string dic[MAXN],s,buf;
int tot=0,len[MAXN],hash[ALPHA],ans[ALPHA];

bool chk()
{
	for(int i=0;i<ALPHA;++i)
		if(hash[i])
			return false;
	return true;
}

void dfs(int cur,int dep)
{
	if(chk())
	{
		string key=dic[ ans[0] ];
		for(int i=1;i<dep;++i)
			key+=" "+dic[ ans[i] ];
		if(key!=buf)
			cout<<s<<" = "<<key<<endl;
	}
	else for(int i=cur;i<tot;++i)
	{
		int cnt[ALPHA]={0};
		bool bk=false;
		for(int j=0;j<len[i] && !bk;++j)
		{
			int p=dic[i][j]-'A';
			if(cnt[p]>=hash[p])
				bk=true;
			else
				++cnt[p];
		}
		if(!bk)
		{
			for(int j=0;j<len[i];++j)
				--hash[ dic[i][j]-'A' ];
			ans[dep]=i;
			dfs(i+1,dep+1);
			for(int j=0;j<len[i];++j)
				++hash[ dic[i][j]-'A' ];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>dic[tot] && dic[tot]!="#")
		++tot;

	for(int i=0;i<tot;++i)
		len[i]=dic[i].length();

	getline(cin,s);

	while(getline(cin,s) && s!="#")
	{
		stringstream sin(s);
		string tmp[ALPHA];
		int cnt=0;
		while(sin>>tmp[cnt])
			++cnt;
		sort(tmp,tmp+cnt);
		buf=tmp[0];
		for(int i=1;i<cnt;++i)
			buf+=" "+tmp[i];

		int l=s.length();
		memset(hash,0,sizeof(hash));
		for(int i=0;i<l;++i)
			if(isalpha(s[i]))
				++hash[ s[i]-'A' ];
		dfs(0,0);
	}

	return 0;
}
