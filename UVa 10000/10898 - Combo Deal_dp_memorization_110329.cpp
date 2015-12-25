/*
 * 10898 - Combo Deal
 *
 * dp...
 * memorization~
 * a simple dfs with memorization is quite enough to solve it
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
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

typedef vector<int> vi;

vi combo[8];
int item_n, combo_n;
map< vi, int> dp;
vi price;

int dfs(vi u) {
	if(dp.find(u)!=dp.end())
		return dp[u];
	int key=INF;
	for(int i=0; i<item_n; ++i) {
		if(u[i]) {
			--u[i];
			ChkMin(key, dfs(u)+price[i]);
			++u[i];
		}
	}

	for(int i=0; i<combo_n; ++i) {
		bool fade=false;
		for(int j=0; j<item_n; ++j) {
			u[j] -= combo[i][j];
			if(u[j]<0)
				fade=true;
		}

		if(!fade)
			ChkMin(key, dfs(u)+combo[i][item_n]);

		for(int j=0; j<item_n; ++j) {
			u[j] += combo[i][j];
		}
	}

	if(key==INF)
		key=0;
	return dp[u]=key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int t, q;
	vi cur;
    while(scanf("%d", &item_n)!=EOF) {
    	price.clear();
    	for(int i=0; i<item_n; ++i) {
    		scanf("%d", &t);
    		price.push_back(t);
    	}

    	scanf("%d", &combo_n);
    	for(int i=0; i<combo_n; ++i) {
    		combo[i].clear();
    		for(int j=0; j<=item_n; ++j) {
        		scanf("%d", &t);
        		combo[i].push_back(t);
    		}
    	}

    	dp.clear();
    	scanf("%d", &q);
    	while(q--) {
    		cur.clear();
    		for(int i=0; i<item_n; ++i) {
    			scanf("%d", &t);
    			cur.push_back(t);
    		}
    		printf("%d\n", dfs(cur));
    	}
    }

    return 0;
}

