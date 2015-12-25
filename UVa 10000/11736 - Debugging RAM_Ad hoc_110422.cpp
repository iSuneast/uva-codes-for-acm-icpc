/*
 * 11736 - Debugging RAM
 *
 * Ad hoc...
 * straight forward problem~
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
typedef unsigned long long ULL;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    map<string , ULL> key;
    vector< pair<string, int> > data;
    int b, v, q;
    int sz;
    string var;
    while(cin>>b>>v) {
    	key.clear();
    	data.clear();
    	for(int i=0; i<v; ++i) {
    		cin>>var>>sz;
    		data.push_back( make_pair(var, sz) );
    	}
    	for(int i=0; i<v; ++i) {
    		ULL t=0;
    		for(int j=0; j<(int)data[i].second; ++j) {
    			cin>>var;
    			for(int k=0; k<b; ++k) {
    				t=t*2+var[k]-'0';
    			}
    		}
    		key[data[i].first]=t;
    	}

    	cin>>q;
    	while(q--) {
    		cin>>var;
    		if(key.find(var)==key.end()) {
    			cout<<var<<"="<<endl;
    		} else {
    			cout<<var<<"="<<key[var]<<endl;
    		}
    	}
    }

    return 0;
}

