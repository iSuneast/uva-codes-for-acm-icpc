/*
 * 11953 - Battleships
 *
 * flood fill
 * consider '@' and 'x' as a part of a ship
 * count the number of '@' and 'x' in a connected component
 * if a connected component has '@', ++answer
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

char g[MAXN][MAXN];
int a, b;

void dfs(int x, int y) {
	if(g[x][y]=='@') {
		++a;
	} else if(g[x][y]=='x') {
		++b;
	} else
		return ;
	g[x][y]='.';

	dfs(x+1, y);
	dfs(x, y+1);
	dfs(x-1, y);
	dfs(x, y-1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, n;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d", &n);

    	memset(g, 0, sizeof(g));
    	for(int i=1; i<=n; ++i) {
    		scanf("%s", g[i]+1);
    	}

    	int key=0;
    	for(int i=1; i<=n; ++i) {
    		for(int j=1; j<=n; ++j) {
    			if(g[i][j]!='.') {
    				a=b=0;
    				dfs(i, j);
    				if(b)
    					++key;
    			}
    		}
    	}

    	printf("Case %d: %d\n", cas, key);
    }

    return 0;
}

