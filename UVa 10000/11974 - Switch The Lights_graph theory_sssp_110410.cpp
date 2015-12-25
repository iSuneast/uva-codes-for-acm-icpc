/*
 * 11974 - Switch The Lights
 *
 * graph theory
 * in fact, this problem is a single source shortest path problem(SSSP)
 * or implicit graph search
 * using bit mask to handle current state, and sssp is quite enough
 *
 * happy coding
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
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int dis[1<<15], n, m;
struct SWITCH {
	int v[15];
	void read() {
		for(int i=0; i<n; ++i) {
			scanf("%d", &v[i]);
		}
	}
}sw[MAXN];

bool inq[1<<15];

void spfa() {
	memset(dis, 0x3f, sizeof(dis));
	int u=(1<<n)-1;
	queue<int> q;
	q.push(u);	inq[u]=true;	dis[u]=0;
	while(!q.empty()) {
		u=q.front();	q.pop();	inq[u]=false;
		for(int i=0; i<m; ++i) {
			int v=u;
			for(int j=0; j<n; ++j) {
				if(sw[i].v[j]) {
					v^=(1<<j);
				}
			}

			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				if(!inq[v]) {
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}

	if(dis[0]!=INF)
		printf("%d\n", dis[0]);
	else
		puts("IMPOSSIBLE");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &m);
    	for(int i=0; i<m; ++i) {
    		sw[i].read();
    	}

    	printf("Case %d: ", cas);
    	spfa();
    }

    return 0;
}

