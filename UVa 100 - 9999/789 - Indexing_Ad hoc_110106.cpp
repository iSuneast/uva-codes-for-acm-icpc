/*
 * 789 - Indexing
 * 
 * Ad hoc..
 * a simple string processing problem...
 * there is only one test case...
 * 
 * happy coding...
 */

#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#define MAXN 10000
using namespace std;

struct INDEX
{
	string s;
	vector<int> pos;
	bool operator<(const INDEX &t)const
	{
		return s<t.s;
	}
}idx[MAXN];

string s,buf;
char key;
map<string,int> msi;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    getline(cin,s);
    key=s[0];
    int n=0,p;
    for(int line=1; getline(cin,s); ++line)
    {
    	stringstream sin(s);
    	while(sin>>buf)
    	{
    		if(buf[0]!=key)
    			continue;
    		
    		for(int i=0;i<buf.length();++i)
    		{
    			if(!isalpha(buf[i]))
    				buf=buf.substr(0,i);
    		}
    		
    		if(msi.find(buf)==msi.end())
    		{
    			p=n;
    			idx[n].s=buf;
    			msi[buf]=n++;
    		}
    		else
    			p=msi[buf];
    		int sz=idx[p].pos.size();
    		if(!sz || idx[p].pos[sz-1]!=line)
    			idx[p].pos.push_back(line);
    	}
    }
    	
	sort(idx,idx+n);
	for(int i=0;i<n;++i)
	{
		cout<<idx[i].s;
		for(int j=0;j<idx[i].pos.size();++j)
			cout<<" "<<idx[i].pos[j];
		cout<<endl;
	}

    return 0;
}

