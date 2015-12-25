/*
 * 10227 - Forests
 *
 * Ad hoc
 * count how many different sets
 * an empty should also be processed
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
#define MAXN 100
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

set<int> ppl[MAXN];
set< set<int> > key;
int p, t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int a, b;
    char buf[30];
    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d", &p, &t);
    	for(int i=1; i<=p; ++i) {
    		ppl[i].clear();
    	}

    	gets(buf);
    	while(gets(buf) && buf[0]) {
    		sscanf(buf, "%d %d", &a, &b);
    		ppl[a].insert(b);
    	}

    	key.clear();
    	for(int i=1; i<=p; ++i) {
			key.insert( ppl[i] );
    	}

    	printf("%d\n", key.size());

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

