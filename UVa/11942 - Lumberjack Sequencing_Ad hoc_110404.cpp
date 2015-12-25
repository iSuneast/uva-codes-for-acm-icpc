/*
 * 11942 - Lumberjack Sequencing
 *
 * Ad hoc...
 * O(N) scan in the sequence will do
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
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    puts("Lumberjacks:");
    while(dataset--) {
    	int big=1, small=1, pre=-INF, cur;
    	scanf("%d", &cur);
    	for(int i=1; i<10; ++i) {
    		pre=cur;
    		scanf("%d", &cur);
    		if(cur>=pre)
    			++big;
    		if(cur<=pre)
    			++small;
    	}

    	puts(big==10 || small==10? "Ordered": "Unordered");
    }

    return 0;
}

