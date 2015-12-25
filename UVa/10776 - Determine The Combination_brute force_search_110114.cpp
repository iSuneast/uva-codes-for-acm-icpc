/*
 * 10776 - Determine The Combination
 * 
 * search...
 * we need to store the string like 
 * cnt['a'] = cntA, cnt['b'] = cntB ...
 * when search we can select i 'a' i->[1,cntA]
 * and then go to next char
 * if we have select r chars, it's the answer we found
 * 
 * according to 
 * "You can assume there are at most 1000 different ones."
 * so don't worry about TLE, if your code is smart enough
 * 
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
#define MAXN 33
using namespace std;

char s[MAXN],buf[MAXN],key[MAXN];
int r,cnt[MAXN];
set<string> ss;

void dfs(int p,int dep)
{
	if(dep==r)
		ss.insert(key);
	else for(int i=p;i<26;++i)
	{
		if(!cnt[i])
			continue;
		for(int t=1;dep+t<=r && t<=cnt[i];++t)
		{
			key[dep+t-1]=i+'a';
			dfs(i+1,dep+t);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    while(scanf("%s%d",s,&r)!=EOF)
    {
    	memset(cnt,0,sizeof(cnt));
    	for(int i=0;s[i];++i)
    	{
    		cnt[ s[i]-'a' ]++;
    	}
    	
    	ss.clear();
    	key[r]=0;
    	dfs(0,0);
    	for(set<string>::iterator sit=ss.begin(); sit!=ss.end(); ++sit)
    		cout<<*sit<<endl;
    }

    return 0;
}

