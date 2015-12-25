/*
 * 11936 - The Lazy Lumberjacks
 *
 * Ad hoc...
 * judge whether three segment can form a valid triangle
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
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    int a[3];
    while(dataset--) {
    	scanf("%d %d %d", &a[0], &a[1], &a[2]);
    	sort(a, a+3);
    	if(a[0]+a[1]>a[2])
    		puts("OK");
    	else
    		puts("Wrong!!");
    }

    return 0;
}

