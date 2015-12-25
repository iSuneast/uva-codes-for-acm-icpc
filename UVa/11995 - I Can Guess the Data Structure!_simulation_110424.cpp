/*
 * 11995 - I Can Guess the Data Structure!
 *
 * simulation
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
#define MAXN 1003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

const char key[][100]={
		"stack",
		"queue",
		"priority queue",
		"impossible",
		"not sure"
};

pii op[MAXN];
int n;

bool chkStack() {
	stack<int> st;
	for(int i=0; i<n; ++i) {
		if(op[i].first==1) {
			st.push(op[i].second);
		} else {
			if(st.empty() || st.top()!=op[i].second)
				return false;
			st.pop();
		}
	}
	return true;
}

bool chkQueue() {
	queue<int> q;
	for(int i=0; i<n; ++i) {
		if(op[i].first==1) {
			q.push(op[i].second);
		} else {
			if(q.empty() || q.front()!=op[i].second)
				return false;
			q.pop();
		}
	}
	return true;
}

bool chkPriorityQueue() {
	priority_queue<int> q;
	for(int i=0; i<n; ++i) {
		if(op[i].first==1) {
			q.push(op[i].second);
		} else {
			if(q.empty() || q.top()!=op[i].second)
				return false;
			q.pop();
		}
	}
	return true;
}

int process() {
	vector<int> ans;
	if(chkStack()) {
		ans.push_back(0);
	}
	if(chkQueue()) {
		ans.push_back(1);
	}
	if(chkPriorityQueue()) {
		ans.push_back(2);
	}

	if(ans.size()>1)
		return 4;
	else if(ans.size()==1)
		return ans[0];
	else
		return 3;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while(scanf("%d", &n)!=EOF) {
    	for(int i=0; i<n; ++i) {
    		scanf("%d %d", &op[i].first, &op[i].second);
    	}
    	puts(key[ process() ]);
    }


    return 0;
}

