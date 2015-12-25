/*
 * 222 - Budget Travel
 *
 * dp...
 * use map<double, double> { ( remain_oil, current_cost ) } to store the state
 * then standard straight forward Dynamic Programming will do
 *
 * "The amount paid at each stop is rounded to the nearest cent"
 * be careful of the precision
 *
 * "The second is the price (in cents) per gallon of gasoline sold at that station."
 * we should transform the price to dollars, price/=100.0
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
#define MAXN 60
#define GOOD 2.0
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

double dist, cap, mile, ori;
map<double, double> dp[2];
int n;
char buf[20];

double format(double t) {
	sprintf(buf, "%.2lf", t);
	sscanf(buf, "%lf", &t);
	return t;
}

double process() {
	int cur=1, pre=0;
	double pos, cost, arrive=0;

	scanf("%lf %lf %lf %d", &cap, &mile, &ori, &n);
	dp[cur].clear();
	dp[cur][cap]=ori;

	for(int i=0; i<=n; ++i) {
		swap(cur, pre);
		dp[cur].clear();

		if(i<n) {
			scanf("%lf %lf", &pos, &cost);
			cost/=100.0;
		} else {
			pos=dist;
			cost=INF;
		}

		double used = (pos-arrive)/mile;
		arrive=pos;

		for(map<double, double>::iterator mit=dp[pre].begin(); mit!=dp[pre].end(); ++mit) {
			double oil = mit->first - used;
			if(oil<0)
				continue;

			dp[cur][oil] = mit->second;		// no oil add

			if(oil*2>cap)
				continue;

			dp[cur][cap] = format(mit->second + GOOD + (cap-oil)*cost);		// full oil
		}
	}

	double key=-1;
	for(map<double, double>::iterator mit=dp[cur].begin(); mit!=dp[cur].end(); ++mit) {
		if(key==-1)
			key=mit->second;
		else
			key=min(key, mit->second);
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    for(int cas=1; scanf("%lf", &dist)!=EOF && dist>=0; ++cas) {
    	printf("Data Set #%d\n", cas);
    	printf("minimum cost = $%.2lf\n", process());
    }

    return 0;
}

