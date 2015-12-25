/*
 * 11984 - A Change in Thermal Unit
 *
 * Ad hoc...
 * what we just have to do is read in c, d
 * and then output c+5*d/9
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
    double c, d;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%lf %lf", &c, &d);
    	printf("Case %d: %.2lf\n", cas, c+5*d/9);
    }

    return 0;
}
 
