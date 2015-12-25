/*
 * 879 - Circuit Nets
 *
 * union find set
 * count the number of disjoint sets
 *
 * happy coding~
 */

#include <iostream>
#include <sstream>
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

int fa[MAXN];

int find(int p) {
	return p==fa[p]? p: fa[p]=find(fa[p]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    string buf;
    int dataset;
    int a, b, n;
    cin>>dataset;
    while(dataset--) {
    	cin>>n;
    	for(int i=1; i<=n; ++i) {
    		fa[i]=i;
    	}
    	getline(cin, buf);
    	int key=n;
    	while(getline(cin, buf) && buf!="") {
    		stringstream sin(buf);
    		while(sin>>a>>b) {
    			a=find(a);
    			b=find(b);
    			if(a!=b) {
    				--key;
    				fa[a]=b;
    			}
    		}
    	}

    	printf("%d\n", key);

    	if(dataset)
    		cout<<endl;
    }



    return 0;
}

