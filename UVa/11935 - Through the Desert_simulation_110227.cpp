/*
 * 11935 - Through the Desert
 *
 * simulation～
 * simulation as the problem description～
 *
 * happy coding～
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int consumption, pos;
	char op[30];

	while(scanf("%d %*s %*s %d", &pos, &consumption)!=EOF && consumption) {
		double cost=0, key=0;
		int cur, leak=0;
		while(scanf("%d%s", &cur, op)!=EOF) {
			cost += (cur-pos)/100.0*consumption;
			cost += (cur-pos)*leak;

			key=max(key, cost);

			if(op[0]=='F') {
				scanf("%*s %d", &consumption);
			} else if(op[0]=='L') {
				++leak;
			} else if(op[0]=='G' && op[1]=='a') {
				scanf("%*s");
				cost=0;
			} else if(op[0]=='M') {
				leak=0;
			} else
				break;

			pos=cur;
		}

		printf("%.3lf\n", key);
	}

	return 0;
}

