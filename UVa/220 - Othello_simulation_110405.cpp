/*
 * 220 - Othello
 *
 * simulation...
 * just do as the problem description~
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
#define MAXN 10
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const int dr[]={-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[]={-1, 0, 1, -1, 1, -1, 0, 1};

struct BOARD {
	char g[MAXN][MAXN];
	char color;
	void read() {
		memset(g, 0, sizeof(g));
		for(int i=1; i<=8; ++i) {
			scanf("%s", g[i]+1);
		}
	}

	void output() {
		for(int i=1; i<=8; ++i) {
			puts(g[i]+1);
		}
	}

	void move(int er, int ec) {
		if(!chk(er, ec)) {
			color = (color=='W')? 'B': 'W';
		}
		char key = (color=='W')? 'B': 'W';

		g[er][ec]=color;
		for(int d=0; d<8; ++d) {
			int tr=er+dr[d];
			int tc=ec+dc[d], mid=0;
			while(g[tr][tc]==key) {
				++mid;
				tr+=dr[d];
				tc+=dc[d];
			}

			if(mid && g[tr][tc]==color) {
				tr=er+dr[d];
				tc=ec+dc[d];
				while(g[tr][tc]==key) {
					g[tr][tc]=color;
					tr+=dr[d];
					tc+=dc[d];
				}
			}
		}

		int w=0, b=0;
		for(int i=1; i<=8; ++i) {
			for(int j=1; j<=8; ++j) {
				if(g[i][j]=='W')
					++w;
				else if(g[i][j]=='B')
					++b;
			}
		}

		color = key;
		printf("Black - %2d White - %2d\n", b, w);
	}

	bool chk(int er, int ec) {
		char key = (color=='W')? 'B': 'W';

		for(int d=0; d<8; ++d) {
			int tr=er+dr[d];
			int tc=ec+dc[d], mid=0;
			while(g[tr][tc]==key) {
				++mid;
				tr+=dr[d];
				tc+=dc[d];
			}

			if(mid && g[tr][tc]==color) {
				return true;
			}
		}

		return false;
	}

	void generate() {
		bool first=true;
		for(int i=1; i<=8; ++i) {
			for(int j=1; j<=8; ++j) {
				if(g[i][j]=='-' && chk(i, j)) {
					if(!first)
						putchar(' ');
					first=false;
					printf("(%d,%d)", i, j);
				}
			}
		}

		if(first)
			puts("No legal move.");
		else
			putchar(10);
	}
}final;

char op[10];

void simulation() {
	scanf("%s", op);
	final.color = op[0];

	while(scanf("%s", op)!=EOF) {
		if(op[0]=='L') {
			final.generate();
		} else if(op[0]=='M') {
			final.move(op[1]-'0', op[2]-'0');
		} else {
			final.output();
			return ;
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
    	final.read();
    	simulation();

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

