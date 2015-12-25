/*
 * 726 - Decode
 * 
 * Ad hoc...
 * simulation...
 * just code as the problem description...
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MAXN 26
using namespace std;

struct CHAR
{
	char c;
	int freq;
	bool operator<(const CHAR &t)const
	{
		if(freq==t.freq)
			return c<t.c;
		return freq>t.freq;
	}
}char_map[MAXN],encode[MAXN];

vector<string> vs;
string s;
char h[128];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
	for(int i=0;i<MAXN;++i)
	{
		char_map[i].freq=0;
		char_map[i].c=i;
		encode[i].freq=0;
		encode[i].c=i;
	}
	
	for(int i=0;i<128;++i)
	{
		h[i]=i;
	}
	
    while(getline(cin,s) && s!="")
    {
    	for(int i=0,l=s.length();i<l;++i)
    	{
    		if(isalpha(s[i]))
    			char_map[tolower(s[i])-'a'].freq++;
    	}
    }
	sort(char_map,char_map+MAXN);
	
    while(getline(cin,s))
    {
    	for(int i=0,l=s.length();i<l;++i)
    	{
    		if(isalpha(s[i]))
    			encode[tolower(s[i])-'a'].freq++;
    	}
    	vs.push_back(s);
    }
    sort(encode,encode+MAXN);
    
    for(int i=0;i<MAXN;++i)
    {
    	h[ encode[i].c+'a' ] = char_map[i].c+'a';
    	h[ encode[i].c+'A' ] = char_map[i].c+'A';
    }
    
	for(int i=0;i!=vs.size();++i)
	{
		for(int j=0;j<vs[i].length();++j)
			putchar( h[ vs[i][j] ] );
		putchar(10);
	}

    return 0;
}

