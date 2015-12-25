/*
 * 255 - Correct Move
 *
 * Ad hoc...
 * using an two-dimension two mark the next state generate by KING and QUEEN
 * and simulation as the problem description~
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
#define KING 1
#define QUEEN -1
#define BOTH -3
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

const char key[][33]={
		"Illegal state",
		"Illegal move",
		"Move not allowed",
		"Continue",
		"Stop"
};
int king, queen, next;
pii pos[8*8];
int flag[8][8];
const int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

void init() {
	for(int i=0, p=0; i<8; ++i) {
		for(int j=0; j<8; ++j) {
			pos[p++]=make_pair(i, j);
		}
	}
}

bool valid(int x, int y) {
	return 0<=x && x<8 && 0<=y && y<8;
}

int h(int x, int y) {
	return x*8+y;
}

void queen_mark(int key) {
	for(int d=0; d<4; ++d) {
		int tx=pos[key].first+dx[d];
		int ty=pos[key].second+dy[d];
		while(valid(tx, ty)) {
			if( h(tx,ty)==king )
				break;
			if(!flag[tx][ty])
				flag[tx][ty]=QUEEN;
			else
				flag[tx][ty]=BOTH;
			tx+=dx[d];
			ty+=dy[d];
		}
	}
}

int chk() {
	if(king == queen)
		return 0;

	memset(flag, 0, sizeof(flag));
	for(int d=0; d<4; ++d) {
		int tx=pos[king].first+dx[d];
		int ty=pos[king].second+dy[d];
		if(valid(tx, ty))
			flag[tx][ty]=KING;
	}
	queen_mark(queen);

	int &key=flag[ pos[next].first ][ pos[next].second ];
	if(key==BOTH)
		return 2;
	if(key!=QUEEN)
		return 1;

	memset(flag, 0, sizeof(flag));
	queen_mark(next);
	for(int d=0; d<4; ++d) {
		int tx=pos[king].first+dx[d];
		int ty=pos[king].second+dy[d];
		if(valid(tx, ty) && !flag[tx][ty])
			return 3;
	}

	return 4;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    while(scanf("%d %d %d", &king ,&queen, &next)!=EOF) {
    	puts(key[ chk() ]);
    }

    return 0;
}

