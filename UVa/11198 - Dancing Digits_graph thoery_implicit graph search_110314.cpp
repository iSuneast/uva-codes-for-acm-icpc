/*
 * 11198 - Dancing Digits
 *
 * graph thoery...
 * bfs...
 * implicit graph search...
 *
 * "Each time, a male digit can ask a female digit to dance with him,
 *  or a female digit can ask a male digit to dance with her,
 *   as long as their sum is a prime."
 *
 * this sentence confused me at first sight
 * then I figure out that it means
 * {1, 2, 4, 5, 6, -7, -3, 8} -> {1, 2, -3, 4, 5, 6, -7, 8}
 * {1, 2, 4, 5, 6, -7, -3, 8} -> {1, 2, 4, -3, 5, 6, -7, 8}
 * these two transform is valid, while
 * {1, 2, 4, 5, 6, -7, -3, 8} -> {1, 2, 4, 5, -3, 6, -7, 8}
 * 				is invalid, because -3 can dance with either 5 or 6
 * {1, 2, 4, 5, 6, -7, -3, 8} -> {1, 4, 2, 5, -3, 6, -7, 8}
 * 				is invalid, because 2 and 5 are both male
 *
 * yes, complete a graph theory problem to find the shortest path between two states
 * using normal bfs method is quite enough to solve this
 *
 * happy coding~
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
#define MAXN 40321
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct STATE {
	int v[8];
	bool operator<(const STATE &t) const {
		for(int i=0; i<8; ++i) {
			if(v[i]!=t.v[i])
				return v[i]<t.v[i];
		}
		return false;
	}
	bool read() {
		if(scanf("%d", &v[0])==EOF || v[0]==0)
			return false;
		for(int i=1; i<8; ++i) {
			scanf("%d", &v[i]);
		}
		return true;
	}
}state, key[MAXN];
map<STATE, int> mapping;
int idx, dis[MAXN];
bool flag[8], isprime[20];

void dfs(int dep) {
	if(dep==8) {
		key[idx]=state;
		mapping[state]=idx++;
	} else for(int i=0; i<8; ++i) {
		if(!flag[i]) {
			state.v[dep]=i;
			flag[i]=true;
			dfs(dep+1);
			flag[i]=false;
		}
	}
}

queue<int> q;
int modify;

void add(const int &v) {
	if(dis[v]!=INF)
		return ;
	dis[v]=modify;
	q.push(v);
}

void dance_r2l(STATE buf, const int &i, const int &j) {
	int t=buf.v[i];
	for(int k=i; k>j; --k) {
		buf.v[k]=buf.v[k-1];
	}
	buf.v[j+1]=t;
	add(mapping[buf]);
	swap(buf.v[j], buf.v[j+1]);
	add(mapping[buf]);
}

void dance_l2r(STATE buf, const int &i, const int &j) {
	int t=buf.v[i];
	for(int k=i; k<j; ++k) {
		buf.v[k]=buf.v[k+1];
	}
	buf.v[j-1]=t;

	add(mapping[buf]);
	swap(buf.v[j], buf.v[j-1]);
	add( mapping[buf]);
}

int bfs() {
	memset(dis, 0x3f, sizeof(dis));
	int u=mapping[state];

	while(!q.empty())
		q.pop();

	q.push(u);	dis[u]=0;
	while(!q.empty()) {
		if(dis[0]!=INF)
			return dis[0];
		u=q.front();	q.pop();
		STATE &cur=key[u];
		modify=dis[u]+1;
		for(int i=0; i<8; ++i) {
			if(!flag[ cur.v[i] ])
				continue;
			for(int j=0; j<8; ++j) {
				if(flag[ cur.v[j] ] || !isprime[ cur.v[i]+cur.v[j]+2 ])
					continue;
				if(i>j) {
					dance_r2l(cur, i, j);
					dance_l2r(cur, j, i);
				}
				else {
					dance_r2l(cur, j, i);
					dance_l2r(cur, i, j);
				}
			}
		}
	}

	return -1;
}

void init() {
	idx=0;
	memset(flag, 0, sizeof(flag));
	dfs(0);

	memset(isprime, 0, sizeof(isprime));
	isprime[2]=isprime[3]=isprime[5]=isprime[7]=isprime[11]=isprime[13]=true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();

	int cas=1;
	while(state.read()) {
		for(int i=0; i<8; ++i) {
			if(state.v[i]<0) {
				state.v[i]=-state.v[i]-1;
				flag[ state.v[i] ]=true;
			} else {
				--state.v[i];
				flag[ state.v[i] ]=false;
			}
		}
		printf("Case %d: %d\n", cas++, bfs());
	}

	return 0;
}
