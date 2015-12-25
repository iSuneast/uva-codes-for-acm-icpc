/*
 * 11951 - Area
 *
 * dp...
 * max 2D sub-Matrix sum
 * classical O(n^3) dynamic programming problem~
 *
 * happy coding~
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int sum[MAXN][MAXN], var[MAXN][MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n, m, k;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d %d", &n, &m, &k);

    	memset(var, 0, sizeof(var));
    	memset(sum, 0, sizeof(sum));
    	for(int i=1; i<=n; ++i) {
    		for(int j=1; j<=m; ++j) {
    			scanf("%d", &var[i][j]);
				sum[i][j]=sum[i-1][j]+var[i][j];
    		}
    	}

    	int key=0, area=0;
    	for(int s=1; s<=n; ++s) {
    		for(int e=s; e<=n; ++e) {

    			for(int i=1; i<=m; ++i) {
    				dp[i]=sum[e][i]-sum[s-1][i];
    			}

    			int l=0, zoro=0, a=1, cur=0;
    			for(int i=1; i<=m; ++i) {
    				zoro+=dp[i];
    				while( zoro>k ) {
    					zoro-=dp[a++];
    				}

    				if(i-a+1>l) {
    					l=i-a+1;
    					cur=zoro;
    				} else if( i-a+1==l ) {
    					cur=min(cur, zoro);
    				}
    			}

    			l=l*(e-s+1);
    			if(l>area) {
    				area=l;
    				key=cur;
    			} else if(l==area) {
    				key=min(key, cur);
    			}
    		}
    	}

    	printf("Case #%d: %d %d\n", cas, area, key);
    }

    return 0;
}

