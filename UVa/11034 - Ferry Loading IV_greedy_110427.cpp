/*
 * 11034 - Ferry Loading IV
 *
 * greedy
 * using 2 queue to handle the cars
 * and at each time load as more cars as possible
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
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
	int l, m, v;
	char dir[10];
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d", &l, &m);
    	l*=100;

    	queue<int> q[2];
    	for(int i=0; i<m; ++i) {
    		scanf("%d %s", &v, dir);
    		if(dir[0]=='l') {
    			q[0].push(v);
    		} else {
    			q[1].push(v);
    		}
    	}

    	int key=0;
    	for(bool right=false; !q[0].empty() || !q[1].empty(); right=!right) {
			int len=0;
    		while(!q[right].empty() && q[right].front()+len<=l) {
    			len+=q[right].front();
    			q[right].pop();
    		}
    		++key;
    	}

    	printf("%d\n", key);
    }

    return 0;
}

