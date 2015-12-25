/*
 * 11127 - Triple-Free Binary Strings
 * 
 * brute force...
 * I can't find any good method...
 * so just brute force with silly pruning...
 * 
 * my code runs to long and nearly got TLE...
 * 
 * happy coding...
 */

#include<cstdio>
#define MAXN 35
using namespace std;

int n,key;
char s[MAXN];

bool chk(int dep)
{
	for(int l=dep/3; l>=1; --l)
	{
		for(int b=0;b+l*3<=dep;++b)
		{
			bool fade=false;
			for(int i=b;i<b+l;++i)
			{
				if(s[i]!=s[i+l] || s[i]!=s[i+l+l])
				{
					fade=true;
					break;
				}
			}
			if(!fade)
				return false;
		}
	}
	return true;
}

void yes()
{
	++key;
}

void dfs(int dep)
{
	if(!chk(dep))
		return ;
	
	if(dep==n)
		return yes();
	
	if(s[dep]!='*')
		return dfs(dep+1);
	s[dep]='0';
	dfs(dep+1);
	s[dep]='1';
	dfs(dep+1);	
	
	s[dep]='*';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1; scanf("%d",&n)!=EOF && n; ++cas)
    {
    	scanf("%s",s);
    	key=0;
    	dfs(0);
    	printf("Case %d: %d\n",cas, key);
    }
    
    return 0;
}

