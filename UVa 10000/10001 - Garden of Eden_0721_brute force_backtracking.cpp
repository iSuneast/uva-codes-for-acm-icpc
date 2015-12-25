/*
10001 - Garden of Eden

brute force...
backtracking...
直接暴力回溯就可以了...
不过是枚举前两个细胞的状态,然后根据目标状态和递推公式继续往下枚举
最后如果可以枚举到原状态
需要特别检查一下得到的前驱状态是否和原状态相同
*/

#include<iostream>
#define MAXN 36
using namespace std;
typedef long long ll;

int trans[2][2][2],l;
char cur[MAXN],s[MAXN];
bool got;

bool chk()
{
	for(int i=0;i<l;++i)
		if(cur[i]!=s[i])
			return true;
	return false;
}

void dfs(int dep)
{
	if(got)
		return ;
	if(dep==l)
	{
		if(cur[l-1]==cur[0] && chk()
			&& trans[ cur[l-2] ][ cur[0] ][ cur[1] ]==s[0]-'0' )
			got=true;
		return ;
	}

	if(!dep)
	{
		for(int i=0;i<4;++i)
		{
			cur[0]=i/2,cur[1]=i%2;
			dfs(dep+2);
		}
	}
	else
	{
		cur[dep]=0;
		if( trans[ cur[dep-2] ][ cur[dep-1] ][ cur[dep] ]==s[dep-1]-'0' )
			dfs(dep+1);
		cur[dep]=1;
		if( trans[ cur[dep-2] ][ cur[dep-1] ][ cur[dep] ]==s[dep-1]-'0' )
			dfs(dep+1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,id;
	while(cin>>id>>n>>s)
	{
		l=n;
		s[l]=s[0];	s[++l]=0;
		for(int i=0;i<8;++i)
		{
			int l=(i&(1<<2))?1:0,m=(i&(1<<1))?1:0,r=(i&1)?1:0,f=((1<<i)&id)?1:0;
			trans[l][m][r]=f;
		}

		got=false;
		dfs(0);

		if(got)
			puts("REACHABLE");
		else
			puts("GARDEN OF EDEN");
	}

	return 0;
}

/*
0 4 1111
204 5 10101
255 6 000000
154 16 1000000000000000
255 6 000001
255 6 111111
204 32 00000000000000000000000000000000
204 32 00000000000000000000000000000001
90 5 10110
90 5 10001
*/