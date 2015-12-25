/*
 * 10578 - The Game of 31
 *
 * game theory...
 * 博弈题。。。
 * 有傻×BUG害我wa了好多次~
 *
 * 学到一种牛掰的状态表示方法
 * 因为每种牌至多4张，可以用三位二进制来保存
 * 有6种牌，所以只要用 6种*3位/种=18位 二进制数即可把当前状态保存下来
 * 如：111126666
 * 4个1 -> 100
 * 1个2 -> 001
 * 4个6 -> 100
 * 即 111126666 -> 100 000 000 000 001 100
 * 同理   356656 ->  011 010 000 001 000 000
 *
 * 这样的话，就可以用记忆化搜索来保存解了
 *
 * 如果从状态S出发，使用一个数n，满足
 * sum(s)+n<=31，则n可以加入当前状态，得到新的状态T
 * 如果得不到新的状态T，则当前状态必胜
 * 如果得到的所有T状态必胜，则当前必败
 * 否则只要有一个T状态为败点，当前必胜
 *
 * happy coding~
 */

#include<iostream>
#define MAXN (1<<19)
using namespace std;

char dp[MAXN], n[7];

int encode(const int &t)
{
	return 1<<( (t-1)*3 );
}

void ChkMin(char &a, const int &t)
{
	if(a>t)
		a=t;
}

int dfs(int state,int sum, int dep)
{
	if(dp[state] != -1)
		return dp[state];

	bool yes[2]={};
	for(int i=1;i<=6;++i)
	{
		if(sum+i>31)
			break;
		if(n[i])
		{
			--n[i];
			yes[ dfs( state+encode(i), sum+i, dep+1 ) ]=true;
			++n[i];
		}
	}

	if(yes[ dep%2 ])
		dp[state]=dep%2;
	else
		dp[state]=(dep+1)%2;

	return dp[state];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	for(char s[30]; gets(s); )
	{
		for(int i=1; i<=6; ++i)
		{
			n[i]=4;
		}

		int state=0, sum=0, len=strlen(s);
		for(int i=0; i<len; ++i)
		{
			n[ s[i]-'0' ]--;
			state += encode(s[i]-'0');
			sum+=s[i]-'0';
			if(sum>31)
			{
				dp[state]=i%2;	// pre win
				break;
			}
		}

		printf("%s %c\n", s, dfs(state, sum, len+1)?'A':'B');
	}

	return 0;
}
