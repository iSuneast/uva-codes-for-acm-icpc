/*
 * 227 - Puzzle
 *
 * simulation...
 * 其实题目不难的= =
 * 直接模拟就好了。。。
 * 一些出现地方很诡异的break让我wa了好久
 * 要不是代码的逻辑有bug的话，ac还是没什么问题的。。。
 *
 * happy coding～
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<ctime>
#define PUZZLE_SZ 5
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef pair<int,int> pii;

const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int h[128];

struct PUZZLE {
	char p[PUZZLE_SZ+5][PUZZLE_SZ+5];
	pii blk;
	bool fade;

	bool read() {
		for(int i=1; i<=PUZZLE_SZ; ++i) {
			gets(p[i]+1);
			if( strcmp(p[i]+1, "Z")==0 )
				return false;
			for(int j=1; j<=PUZZLE_SZ; ++j) {
				if(p[i][j]==' ')
					blk=make_pair(i, j);
			}
		}
		return true;
	}

	bool valid(const pii &t) {
		return 0<t.first && t.first<=PUZZLE_SZ
			&& 0<t.second && t.second<=PUZZLE_SZ;
	}

	void move() {
		fade=false;
		char buf[1000];

		while(gets(buf)) {		//这段代码起初的bug好多好多阿～～～
			for(int i=0; buf[i]; ++i) {
				if(buf[i]=='0')
					return ;

				if(fade)
					continue;

				int d=h[ (int)buf[i] ];
				if(d==-1)
					continue;

				pii next=make_pair( blk.first+dx[d], blk.second+dy[d] );
				if( !valid(next) )
					fade=true;
				else {
					swap( p[blk.first][blk.second] , p[next.first][next.second] );
					blk=next;
				}
			}
		}
	}

	void out() {
		if(fade)
			puts("This puzzle has no final configuration.");
		else for(int i=1; i<=PUZZLE_SZ; ++i) {
			for(int j=1; j<PUZZLE_SZ; ++j) {
				printf("%c ", p[i][j]);
			}
			printf("%c\n", p[i][ PUZZLE_SZ ]);
		}
	}
}puzzle;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    memset(h, -1, sizeof(h));
    h['A']=0;    h['B']=1;
    h['L']=2;    h['R']=3;
    for(int cas=1; puzzle.read(); ++cas) {
    	if(cas!=1)
    		putchar(10);

    	puzzle.move();
    	printf("Puzzle #%d:\n", cas);
    	puzzle.out();
    }

    return 0;
}

