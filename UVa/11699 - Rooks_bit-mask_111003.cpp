/*
 * 11699 - Rooks
 *
 * bit-mask
 * ֱ��ö����Щ��һ��Ҫ�ţ�a��
 * Ȼ��û�зŵ��кϲ���������+��->���ϲ����У�
 * ͳ�ƺϲ���������Ҫ�ŵĶ�������b
 * ȡa��b��ļ���
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN 15
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char g[MAXN+3][MAXN+3];
int var[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while(gets(g[0]) && strcmp(g[0], "END")) {
		for(int i=0; i<MAXN; ++i) {
			if(i)
				gets(g[i]);
			var[i]=0;
			for(int j=0; j<MAXN; ++j) {
				if(g[i][j]=='#') {
					var[i]|=(1<<j);
				}
			}
		}
		int key=MAXN;
		for(int i=0; i<(1<<MAXN); ++i) {
			int a=0, b=0, c=0;
			for(int j=0; j<MAXN; ++j) {
				if((1<<j)&i) {
					++a;
				} else {
					b|=var[j];
				}
			}
			for(int j=0; j<MAXN; ++j) {
				if((1<<j)&b)
					++c;
			}
			key=min(key, max(a, c));
		}
		printf("%d\n", key);
	}

	return 0;
}
