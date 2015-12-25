/*
 * 11581 - Grid Successors
 *
 * Ad hoc...
 * 总共只有2^9种情况，直接预处理出后继即可
 * 然后直接while扫描一遍看一下后继结点有几个答案就是几个
 * 000
 * 000
 * 000 不算后继结点，所以有无穷解，答案-1
 *
 * happy coding~
 */

#include<iostream>
#define MAXN (1<<9)
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

struct MATRIX {
	bool r[3][3];
	int v;

	void read() {
		char s[4];
		v = 0;
		for(int i=0; i<3; ++i) {
			scanf("%s", s);
			for(int j=0; j<3; ++j) {
				r[i][j] = s[j]-'0';
				v = v*2 + r[i][j];
			}
		}
	}

	MATRIX(){}
	MATRIX(const int _v):v(_v) {
		for(int i=2; i>=0; --i) {
			for(int j=2; j>=0; --j) {
				r[i][j] = v&1;
				v>>=1;
			}
		}
	}

	MATRIX f() {
		MATRIX t;
		t.v = 0;
		for(int i=0; i<3; ++i) {
			for(int j=0;j<3;++j) {
				int s=0, tx, ty;
				for(int d=0; d<4; ++d) {
					tx = i+dx[d], ty = j+dy[d];
					if(0<=tx && tx<3 && 0<=ty && ty<3)
						s+=r[tx][ty];
				}
				t.r[i][j] = s%2;
				t.v = t.v*2 + t.r[i][j];
			}
		}

		return t;
	}
}ori;

bool flag[MAXN];
int next[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int i=0; i<MAXN; ++i) {
		next[i] = MATRIX(i).f().v;
	}

	int dataset;
	scanf("%d", &dataset);
	while(dataset--) {
		ori.read();

		memset(flag,0,sizeof(flag));
		int p=ori.v, key=-1;
		while(!flag[p]) {
			flag[p]=true;
			p=next[p];
			++key;
		}
		printf("%d\n", key-1);
	}

	return 0;
}
