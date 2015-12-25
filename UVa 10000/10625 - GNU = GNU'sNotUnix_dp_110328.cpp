/*
 * 10625 - GNU = GNU'sNotUnix
 *
 * dp...
 * 按规则一层一层往下递推即可~
 * 不知道为什么wa了一次~
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
#define MAXN 10003
#define MAX_LEN 103
#define LOW 0
#define UP 127
using namespace std;
const int INF=0x3f3f3f3f;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

char op[128][MAX_LEN], buf[MAX_LEN], key;
int n, len[128], dep;
ULL dp[MAXN][128];

void process() {
	memset(dp[0], 0, sizeof(dp[0]));
	for(int i=0; buf[i]; ++i) {
		dp[0][ (int)buf[i] ]++;
	}

	for(int i=0; i<dep; ++i) {
		for(int j=LOW; j<=UP; ++j) {
			dp[i+1][j]=0;
		}

		for(int j=LOW; j<=UP; ++j) {
			if(!len[j]) {
				dp[i+1][j] += dp[i][j];
			} else for(int k=0; k<len[j]; ++k) {
				dp[i+1][ (int)op[j][k] ] += dp[i][j];
			}
		}
	}

	cout<< dp[dep][ (int)key ] <<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    char ori[3];
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d", &n);

    	memset(len, 0, sizeof(len));
    	for(int i=0; i<n; ++i) {
    		scanf("%s", buf);
    		strcpy( op[(int)buf[0]], buf+3 );
    		len[(int)buf[0]] = strlen(buf+3);
    	}

    	int q;
    	scanf("%d", &q);
    	while(q--) {
    		scanf("%s %s %d", buf, ori, &dep);
    		key=ori[0];
    		process();
    	}
    }

    return 0;
}

