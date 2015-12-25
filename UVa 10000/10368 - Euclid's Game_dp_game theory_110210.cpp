/*
 * 10368 - Euclid's Game
 *
 * DP...
 * game theory
 * 简单的博弈, DP一下就好了
 * 对于p0=(a,b), 可以发现本质上最后一定转移到p1=(b, a%b)
 * 如果p0与p1互为P/N点
 *
 * 并且如果对于p0点  a/b>1 的话, 先手必胜
 * 如果p1为P点, 则 p0可以转移至 p1'=(a%b+b, b), 则p1'为N点, p0为P点
 * 如果p1为N点, 则 p0可以转移至 p1=(b, a%b), 则p0依旧为P点
 *
 * 用map<pair,bool> 来保存状态, 记忆化搜索即可~
 *
 * happy coding~
 */

#include<cstdio>
#include<map>
using namespace std;

typedef pair<int,int> pii;
map<pii,bool> mpb;

bool dp(const int &a,const int &b)
{
	if(!b)
		return true;
	if(mpb.find( make_pair(a,b) )!=mpb.end())
		return mpb[ make_pair(a,b) ];
	int rem=a%b;
	if(b+rem!=a || !rem)
		return mpb[ make_pair(a,b) ]=true;
	return mpb[ make_pair(a,b) ]=!dp(b,rem);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int a,b; scanf("%d%d",&a,&b)!=EOF && (a||b); )
	{
		mpb.clear();
		if(a<b)
			swap(a,b);
		puts(dp(a,b)?"Stan wins":"Ollie wins");
	}

	return 0;
}
