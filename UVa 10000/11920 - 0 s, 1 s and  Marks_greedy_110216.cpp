/*
 * 11920 - 0 s, 1 s and ? Marks
 *
 * greedy...
 *
 * b-search and greedy
 *
 * if the digits before && after "?" is different, we can change the sequence to
 * *0?1*     -> *0?1*      still don't know
 * *0??1*    -> *0101*     ans>=1
 * *0???1*   -> *01001*    ans>=2
 * *0????1*  -> *010101*   ans>=1
 * ....
 * else if they are the same, "0" is consider here, the same to "1"
 * *0?0*     -> *010*      ans>=1
 * *0??0*    -> *0110*     ans>=2
 * *0???0*   -> *01010*    ans>=1
 * *0????0*  -> *010110*   ans>=2
 * ...
 * but how to solve the "0?1" sequence ?
 * my method is b-search and greedy...
 * if I can merge '?' with previous sequence, I will greedy merge them
 * else I have to merge '?' with successive sequence...
 *
 * now, the answer is obvious after some observe...
 *
 * just code it and got AC...
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 1003
using namespace std;

char s[MAXN];
int cnt[MAXN];

bool checked(int key, int n) {
	int add=0, pre=-1;
	for(int i=0; i<n; ++i) {
		if(s[i]!='?') {
			if(s[i]==pre)
				add+=cnt[i];
			else
				add=cnt[i];
			pre=s[i];
		} else {
			if(add+cnt[i]<=key) {
				add += cnt[i];
			}
			else {
				add=cnt[i];
				pre=s[i+1];
			}
		}

		if(add>key)
			return false;
	}

	return true;
}

int b_located(int n, int end) {
	int bgn=1;
	while(bgn<=end) {
		int mid=(bgn+end)>>1;
		if( checked(mid, n) )
			end=mid-1;
		else
			bgn=mid+1;
	}

	return bgn;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d", &dataset);	gets(s);
	for(int cas=1; cas<=dataset; ++cas) {
		gets(s);
		int len=strlen(s), p=0;
		for(int i=0; i<len; ++i) {
			if(!p) {
				cnt[p]=1;
				s[p++]=s[i];
			} else {
				if(s[i]==s[p-1]) {
					cnt[p-1]++;
				} else {
					cnt[p]=1;
					s[p++]=s[i];
				}
			}
		}

		int key=1;
		for(int i=0; i<p; ++i) {
			if(s[i]=='?') {
				bool same=true;
				if(i>0 && i+1<p && s[i-1]!=s[i+1])
					same=false;
				if(same) {
					s[i]=1-(s[i]-'0')+'0';
					if(cnt[i]&1 || i==0 || i+1==p)
						cnt[i]=0;
					else {
						cnt[i]=0;
						key = 2;
					}
				} else {
					if(cnt[i]&1) {
						if(cnt[i]!=1) {
							cnt[i]=0;
							key=2;
						}
					} else
						cnt[i]=0;
				}
			}
		}

		printf("Case %d: %d\n", cas, max(key, b_located(p, len)) );
	}

	return 0;
}

/*
O(n^2) DP method , TLE

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int dp[MAXN][2][MAXN], len;
bool inq[MAXN][2][MAXN];
char str[MAXN];

void ChkMin(int &a,const int &t)
{
	if(a>t)
		a=t;
}

struct DATA
{
	int dep,cnt;
	bool one;
	DATA(){}
	DATA(const int &_d,const bool &_o,const int &_c):dep(_d),cnt(_c),one(_o){}
};
queue<DATA> q;

void update(const int &ans, const int &dep,const bool &one, const int &cnt)
{
	if(ans<dp[dep][one][cnt])
	{
		dp[dep][one][cnt]=ans;
		if(!inq[dep][one][cnt] && dep<=len)
			q.push( DATA(dep, one, cnt) );
	}
}

void spfa()
{
	memset(dp,0x3f,sizeof(dp));
	q.push( DATA(0,false,0) );
	q.push( DATA(0,true,0) );
	inq[0][0][0]=inq[0][1][0]=true;
	dp[0][0][0]=dp[0][1][0]=0;

	while(!q.empty())
	{
		DATA pre=q.front();	q.pop();	inq[pre.dep][pre.one][pre.cnt]=false;
		int dep=pre.dep+1, ans=dp[pre.dep][pre.one][pre.cnt];

		if(pre.one)
		{
			if(str[dep]!='0')
				update(max(ans, pre.cnt+1), dep, 1, pre.cnt+1);
			if(str[dep]!='1')
				update(max(ans, 1), dep, 0, 1);
		}
		else
		{
			if(str[dep]!='0')
				update(max(ans, 1), dep, 1, 1);
			if(str[dep]!='1')
				update(max(ans, pre.cnt+1), dep, 0, pre.cnt+1);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;

	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas)
	{
		scanf("%s", str+1);
		len=strlen(str+1);

		spfa();
		int key=INF;
		for(int n=0; n<=len; ++n)
		{
			ChkMin(key, min(dp[len][0][n] , dp[len][1][n]));
		}

		printf("Case %d: %d\n", cas, key);
	}

	return 0;
}

 */
