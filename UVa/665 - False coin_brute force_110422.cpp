/*
 * 665 - False coin
 *
 * brute force
 * check every coin, and if it's false, then all the condition is checked OK
 * if at last, there are more than one coin is OK, the answer is also 0
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
#define MAXN 103
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct DATA {
	int l[MAXN/2], r[MAXN/2], sz;
	char op;
	void read() {
		scanf("%d", &sz);
		for(int i=0; i<sz; ++i) {
			scanf("%d", &l[i]);
		}
		for(int i=0; i<sz; ++i) {
			scanf("%d", &r[i]);
		}
		scanf(" %c", &op);
	}

	bool light(int id) {
		for(int i=0; i<sz; ++i) {
			if(l[i]==id) {
				return op=='<';
			}
		}
		for(int i=0; i<sz; ++i) {
			if(r[i]==id) {
				return op=='>';
			}
		}

		return op=='=';
	}

	bool heavy(int id) {
		for(int i=0; i<sz; ++i) {
			if(l[i]==id) {
				return op=='>';
			}
		}
		for(int i=0; i<sz; ++i) {
			if(r[i]==id) {
				return op=='<';
			}
		}

		return op=='=';
	}
}data[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	vector<int> key;
	int n, k;
    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d", &n, &k);
    	for(int i=0; i<k; ++i) {
    		data[i].read();
    	}

    	key.clear();
    	for(int i=1; i<=n; ++i) {
    		bool fade=false;
    		for(int j=0; j<k; ++j) {
    			if(!data[j].light(i)) {
    				fade=true;
    				break;
    			}
    		}

    		if(!fade) {
    			key.push_back(i);
    			continue;
    		}

    		fade=false;
    		for(int j=0; j<k; ++j) {
    			if(!data[j].heavy(i)) {
    				fade=true;
    				break;
    			}
    		}

    		if(!fade) {
    			key.push_back(i);
    		}
    	}

    	int ans=0;
    	if(key.size()==1)
    		ans=key[0];

    	printf("%d\n", ans);

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

