/*
 * 676 - Horse Step Maze
 *
 * graph theory
 * dfs
 *
 * Wow, this problem is really my nightmare
 *
 * "If the number of steps is over 50000 print `more than 50000 steps'."
 * at first, I miss this sentence and got a dozen of WA...
 *
 * I try to store the answer as ANSWER[size++]=(...)
 * then I check size>50000, but it's quite wrong
 * because the horse only go sz-1 steps!
 * so I have to change it like this size-1>50000
 * poor :(
 *
 * "Print a blank line between datasets."
 * at last, another dozen of WA because of this sentence...
 * maybe UVa online judge is a little to strict about PE and WA
 *
 * finally got ac...
 *
 * maybe next time, I need to be more careful about a simple problem
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
#define MAXN 13
#define MAX_STEP 50000
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const int dr[]={-1, 1, 1, -1};
const int dc[]={1, 1, -1, -1};
bool g[MAXN][MAXN], got, first;
pii st, end, key[MAX_STEP*10];
int sz;

bool dfs(int r, int c) {
	if(sz>MAX_STEP || got || r<1 || c<1 || r>9 || c>9 || g[r][c])
		return false;
	g[r][c]=true;
	key[++sz]=make_pair(r, c);

	if(r==end.first && c==end.second) {
		got=true;
		return false;
	}

	for(int d=0; d<4; ++d) {
		int tr=r+dr[d], tc=c+dc[d];
		if(dfs(tr, tc)) {
			if(sz>MAX_STEP || got)
				return false;
			key[++sz]=make_pair(r, c);
		}
	}

	g[r][c]=false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf(" %*c%d%*c%d%*c", &st.first, &st.second);
    	scanf(" %*c%d%*c%d%*c", &end.first, &end.second);

    	if((st.first+st.second)%2 != (end.first+end.second)%2) {
    		puts("fail");
    	} else {
    		got=false;
    		sz=-1;
        	memset(g, 0, sizeof(g));
        	dfs(st.first, st.second);
        	if(sz>MAX_STEP) {
        		puts("more than 50000 steps");
        	} else {
        		printf("(%d,%d)", key[0].first, key[0].second);
        		for(int i=1; i<=sz; ++i) {
            		printf(", (%d,%d)", key[i].first, key[i].second);
        		}
        		putchar(10);
        	}
    	}

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

