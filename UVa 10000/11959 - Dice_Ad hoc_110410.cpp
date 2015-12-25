/*
 * 11959 - Dice
 *
 * Ad hoc...
 * we have to consider about 6*4 = 24 cases to got ac
 * make a rotate table is a good idea~
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

const int h[][6]={
		{0,1,2,3,4,5},
		{0,1,3,4,5,2},
		{0,1,4,5,2,3},
		{0,1,5,2,3,4},
		{1,0,2,5,4,3},
		{1,0,5,4,3,2},
		{1,0,4,3,2,5},
		{1,0,3,2,5,4},
		{5,3,0,4,1,2},
		{5,3,4,1,2,0},
		{5,3,1,2,0,4},
		{5,3,2,0,4,1},
		{2,4,1,3,0,5},
		{2,4,3,0,5,1},
		{2,4,0,5,1,3},
		{2,4,5,1,3,0},
		{3,5,1,4,0,2},
		{3,5,4,0,2,1},
		{3,5,0,2,1,4},
		{3,5,2,1,4,0},
		{4,2,0,3,1,5},
		{4,2,3,1,5,0},
		{4,2,1,5,0,3},
		{4,2,5,0,3,1}
};

char a[10], b[10];

bool ok() {
	for(int i=0; i<24; ++i) {
		bool fade=false;
		for(int j=0; j<6; ++j) {
			if(a[ h[i][j] ]!=b[ h[0][j] ]) {
				fade=true;
				break;
			}
		}
		if(!fade)
			return true;
	}

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%s %s", a, b);
    	puts(ok()? "Equal": "Not Equal");
    }

    return 0;
}

