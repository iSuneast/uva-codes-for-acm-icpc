/*
 * 11988 - Broken Keyboard (a.k.a. Beiju Text)
 *
 * data struct
 * deque
 * we have to simulation the operation
 * and the deque is a fine data struct
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
#define MAXN 100003
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

string str;
deque<string> key;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while(getline(cin ,str)) {
    	str+="$";
    	key.clear();
    	int p=1;
    	for(int i=0, st=0, len=str.length(); i<len; ++i) {
    		if(str[i]=='[') {
    			if(st!=-1) {
    				if(p==-1) {
    					key.push_front( str.substr(st, i-st) );
    				} else {
    					key.push_back( str.substr(st, i-st) );
    				}
    			}

    			p=-1;
    			st=-1;
    		} else if(str[i]==']') {
    			if(st!=-1) {
    				if(p==-1) {
    					key.push_front( str.substr(st, i-st) );
    				} else {
    					key.push_back( str.substr(st, i-st) );
    				}
    			}

    			p=1;
    			st=-1;
    		} else if(str[i]=='$') {
    			if(st!=-1) {
    				if(p==-1) {
    					key.push_front( str.substr(st, i-st) );
    				} else {
    					key.push_back( str.substr(st, i-st) );
    				}
    			}
    		} else {
    			if(st==-1)
    				st=i;
    		}
    	}

    	for(int i=0, sz=key.size(); i<sz; ++i) {
    		cout<<key[i];
    	}
    	cout<<endl;
    }

    return 0;
}

