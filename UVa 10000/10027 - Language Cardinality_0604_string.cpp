/*
10027 - Language Cardinality

string...
tricky真多啊..

input:
"a"
"a"->"aa"
如果不特判的话就会TLE...

其它的就没有什么好说的了...
直接STL的string做就可以了
*/

#include<iostream>
#include<sstream>
#include<string>
#include<set>
#define MAXN 1010
using namespace std;

string dic[MAXN],buf,st,tar;
int len[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	getline(cin,buf);getline(cin,buf);
	while(dataset--)
	{
		getline(cin,dic[0]);
		dic[0]=dic[0].substr(1,dic[0].length()-2);
		set<string> ss;
		ss.insert(dic[0]);
		len[0]=dic[0].length();
		int cnt=1;

		while(getline(cin,buf) && buf!="")
		{
			int l=buf.length(),l2;
			for(int i=1;i<l-1;++i)
				if(buf[i]=='"')
					buf[i]=' ';
			stringstream sin(buf);
			sin>>st>>tar;
			sin>>tar;
			st=st.substr(1,l=st.length()-1);
			tar=tar.substr(0,l2=tar.length()-1);
			if(st!=tar)
			for(int i=0;i<=l2-l;++i)
				if(st==tar.substr(i,l2))
				{
					cnt=MAXN;
					break;
				}

			if(cnt<=1000 && l)
			for(int i=0;i<cnt;++i)
			{
				for(int j=0;j<=len[i]-l;++j)
				{
					if(dic[i].substr(j,l)==st)
					{
						string tmp=dic[i];
						tmp=tmp.erase(j,l).insert(j,tar);
						if(ss.find(tmp)==ss.end())
						{
							len[cnt]=tmp.length();
							dic[cnt++]=tmp;
							ss.insert(tmp);
						}
						if(cnt>1000)
							break;
					}
					if(cnt>1000)
						break;
				}
				if(cnt>1000)
					break;
			}
		}
		if(cnt>1000)
			puts("Too many.");
		else
			printf("%d\n",cnt);
		if(dataset)
			putchar('\n');
	}

	return 0;
}
