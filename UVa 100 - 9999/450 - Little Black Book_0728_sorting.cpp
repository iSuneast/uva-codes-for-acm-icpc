/*
450 - Little Black Book

sorting...
小心一下输入数据里面的空格就可以了...
数据范围没给,所以数组今年开大一点
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 100000
using namespace std;

struct DATA
{
	string title,first,last,add,home,work,box;
	int p;
	bool operator<(const DATA &t)const
	{
		return last<t.last;
	}
}data[MAXN];
int n;
string s,depart[15];

void del(string &t)
{
	int l=t.length();
	while(l--)
		if(t[l]=='$')
			t[l]=' ';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	cin>>n;getline(cin,s);
	int tot=0;
	for(int k=0;k<n;++k)
	{
		bool first=true;
		while(getline(cin,s) && s!="")
		{
			if(first)
			{
				depart[k]=s;
				first=false;
			}
			else
			{
				int l=s.length();
				for(int i=0;i<l;++i)
					if(s[i]==',')
						s[i]=' ';
					else if(s[i]==' ')
						s[i]='$';
				stringstream sin(s);
				sin>>data[tot].title>>data[tot].first>>data[tot].last
					>>data[tot].add>>data[tot].home>>data[tot].work>>data[tot].box;
				del(data[tot].title);
				del(data[tot].first);
				del(data[tot].last);
				del(data[tot].add);
				del(data[tot].home);
				del(data[tot].work);
				del(data[tot].box);
				data[tot++].p=k;
			}
		}
	}
	sort(data,data+tot);

	for(int i=0;i<tot;++i)
	{
		puts("----------------------------------------");
		cout<<data[i].title<<" "<<data[i].first<<" "<<data[i].last<<endl;
		cout<<data[i].add<<endl;
		cout<<"Department: "<<depart[ data[i].p ]<<endl;
		cout<<"Home Phone: "<<data[i].home<<endl;
		cout<<"Work Phone: "<<data[i].work<<endl;
		cout<<"Campus Box: "<<data[i].box<<endl;
	}

	return 0;
}
