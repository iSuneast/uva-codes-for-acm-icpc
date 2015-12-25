#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define LOWBIT(v) ((v)&(-(v)))

#define MAXN 1003
using namespace std;

struct Data {
	int b, j;
	bool operator<(const Data &t) const {
		return max(b+j, b+t.b+t.j) < max(t.b+t.j, t.b+b+j);
		/*
		max(b+j, b+t.b+t.j) < max(t.b+t.j, t.b+b+j) [1]

		[1]等价于
		b+j < max(t.b+t.j, t.b+b+j) 为真
		&&
	    b+t.b+t.j < max(t.b+t.j, t.b+b+j)
		
		[1]简化为
		b+t.b+t.j < max(t.b+t.j, t.b+b+j) [2]

		[2]等价于
		b+t.b+t.j < t.b+t.j 为假
		||
		b+t.b+t.j < t.b+b+j
		
		[2]简化为
		b+t.b+t.j < t.b+b+j [3]

		[3]简化为
		t.j < j
		 */
	}
}data[MAXN];
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	for(int cas=1; ; ++cas) {
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		for(int i=0; i<n; ++i) {
			scanf("%d %d", &data[i].b, &data[i].j);
		}
		sort(data, data+n);
		int key = 0;
		for(int i=0, cur=0; i<n; ++i) {
			key = max(cur+data[i].b+data[i].j, key);
			cur += data[i].b;
		}
		printf("Case %d: %d\n", cas, key);
	}

	return 0;
}
