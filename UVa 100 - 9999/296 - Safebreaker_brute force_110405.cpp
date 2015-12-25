/*
 * 296 - Safebreaker
 *
 * brute force...
 * classical guess number game
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
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct DATA {
	int a, b;
	char var[5];
}data[MAXN];
int n;

bool chk(int buf) {
	char var[5];
	sprintf(var, "%04d", buf);
	for(int i=0; i<n; ++i) {
		int flag[2][10]={};
		int a=0, b=0;
		for(int j=0; j<4; ++j) {
			if(var[j]==data[i].var[j]) {
				++a;
			} else {
				flag[0][ var[j]-'0' ]++;
				flag[1][ data[i].var[j]-'0' ]++;
			}
		}

		for(int k=0; k<10; ++k) {
			b+=min(flag[0][k], flag[1][k]);
		}

		if(a!=data[i].a || b!=data[i].b)
			return false;
	}

	return true;
}

void process() {
	int key=-1;
	for(int i=0; i<10000; ++i) {
		if(chk(i)) {
			if(key!=-1) {
				puts("indeterminate");
				return ;
			}
			key=i;
		}
	}

	if(key==-1)
		puts("impossible");
	else
		printf("%04d\n", key);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d", &n);
    	for(int i=0; i<n; ++i) {
    		scanf("%s %d%*c%d", data[i].var, &data[i].a, &data[i].b);
    	}

    	process();
    }

    return 0;
}

