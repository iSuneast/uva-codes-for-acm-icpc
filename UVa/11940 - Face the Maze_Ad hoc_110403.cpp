/*
 * 11940 - Face the Maze
 *
 * Ad hoc...
 * using a dfs function to simulation the process
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
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int n;
bool g[MAXN][MAXN];
pii bgn, end;
char buf[100000];
bool first, got;
const int dr[]={1, 0, 0, -1};
const int dc[]={0, 1, -1, 0};

void init() {
	for(int i=n+1; i>=0; --i) {
		for(int j=n+1; j>=0; --j) {
			g[i][j]=false;
		}
	}
}

bool valid(int r, int c) {
	return 0<r && r<=n && 0<c && c<=n;
}

void dfs(int r, int c) {
	if(got)
		return ;

	g[r][c]=true;
	if(!first)
		putchar(' ');
	printf("(%d,%d)", c, r);
	first=false;

	if(make_pair(r, c)==end) {
		got=true;
		return ;
	}

	pii next;
	for(int d=0; d<4; ++d) {
		next.first=r+dr[d];
		next.second=c+dc[d];
		if(next==end) {
			return dfs(end.first, end.second);
		}
	}

	for(int d=0; d<4; ++d) {
		next.first=r+dr[d];
		next.second=c+dc[d];
		if(got)
			return ;
		if(valid(next.first, next.second) && !g[next.first][next.second]) {
			dfs(next.first, next.second);

			if(got)
				return ;

			putchar(' ');
			printf("(%d,%d)", c, r);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, r, c;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d", &n);
    	gets(buf);
    	init();
    	int p=0;

    	for(char *token=strtok(buf, " "); token; token=strtok(NULL, " "), ++p) {
    		sscanf(token, "(%d,%d)", &c, &r);
    		if(p==0) {
    			bgn=make_pair(r, c);
    		} else if(p==1) {
    			end=make_pair(r, c);
    		} else
        		g[r][c]=true;
    	}

    	first=true;
    	got=false;
    	dfs(bgn.first, bgn.second);
    	putchar(10);
    }

    return 0;
}

