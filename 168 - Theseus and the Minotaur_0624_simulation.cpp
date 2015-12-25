/*
168 - Theseus and the Minotaur

simulation...
题目描述不很清楚的模拟题...
我之前以为"Minotaur checks the exits from a cavern in alphabetical order"
然后按字典序给出口排序,竟然wa
后来才知道,根本就没有那回事,直接按照链表出现顺序访问的

给定的两个人的位置一定是相邻的...
不然的话,这题的解就完全和第二个人无关了...

读入数据那边比较麻烦..
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#define MAXN 30
using namespace std;

vector<int> edge[MAXN];
bool flag[MAXN];
int sz[MAXN];
string s;
int k,cur,pre;

void input()
{
	int l=s.length(),cnt=0;
	for(int i=0;i<l;++i)
		if(s[i]==';' || s[i]=='.')
		{
			s[i]=' ';
			++cnt;
		}
	for(int i=0;i<MAXN;++i)
	{
		edge[i].clear();
		flag[i]=0;
	}

	stringstream sin(s);
	string buf;
	memset(sz,0,sizeof(sz));
	for(int i=0;i<cnt;++i)
	{
		sin>>buf;
		int p=buf[0]-'A';
		buf=buf.substr(2,buf.length()-2);
		sz[p]=buf.length();

		for(int i=0;i<sz[p];++i)
			edge[p].push_back(buf[i]-'A');
	}
	char c;
	sin>>c;	cur=c-'A';
	sin>>c>>k;	pre=c-'A';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(getline(cin,s) && s!="#")
	{
		input();

		memset(flag,0,sizeof(flag));
		bool bk=false;
		while(!bk)
		{
			int p=k;
			while(p)
			{
				bk=true;
				for(int i=0;i<sz[cur];++i)
				{
					int v=edge[cur][i];
					if(!flag[v] && v!=pre)
					{
						pre=cur;
						cur=v;
						bk=false;
						break;
					}
				}
				if(bk)	break;

				if(p==1)
				{
					cout<<(char)(pre+'A')<<" ";
					flag[pre]=true;
				}

				--p;
			}
			if(bk)
				cout<<"/"<<(char)(cur+'A')<<endl;
		}
	}

	return 0;
}

/*
-------sample input-------
A:DBC. A B 20
A:BC;B:A;C:D;D:A. A B 19 
A:B;B:AC;C:B. B B 1
A:B;B:BCA;C:D;D:C. B A 3 
#
-------output-------
/D
/B
B /A
C /D
*/