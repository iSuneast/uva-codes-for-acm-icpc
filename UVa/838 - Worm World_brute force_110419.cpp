/*
 * 838 - Worm World
 *
 * brute force...
 * =_=
 * using brute force
 * stop when we have already dfs the answer tree for MaxChkNum times...
 * =_=////
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
#define MAXN 14
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int var[MAXN][MAXN], n, key;
bool vis[1003];
const int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
const int maxChkN=31400;	// =_=
int cnt;

void dfs(const int &x, const int &y, const int &dep) {
	if(++cnt>maxChkN)
		return ;
	if(dep>key)
		key=dep;

	for(int d=0; d<4; ++d) {
		int tx=x+dx[d], ty=y+dy[d];
		if(var[tx][ty]!=-1 && !vis[ var[tx][ty] ]) {
			vis[ var[tx][ty] ]=true;
			dfs(tx, ty, dep+1);
			vis[ var[tx][ty] ]=false;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d", &n);

    	memset(var, -1, sizeof(var));
    	for(int i=1; i<=n; ++i) {
    		for(int j=1; j<=n; ++j) {
    			scanf("%d", &var[i][j]);
    		}
    	}

    	key=1;
    	for(int i=1; i<=n; ++i) {
    		for(int j=1; j<=n; ++j) {
    	    	cnt=0;
    	    	vis[ var[i][j] ]=true;
    	    	dfs(i, j, 1);
    	    	vis[ var[i][j] ]=false;
    		}
    	}

    	printf("%d\n", key);

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

