/*
 * 452 - Project Scheduling
 *
 * topo-sort
 * in fact, we just need to find the farthest path
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
#define MAXN 26
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char buf[100], adj[100];
bool g[MAXN][MAXN], ext[MAXN];
int d[MAXN], dis[MAXN], t[MAXN], q[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset;
    scanf("%d", &dataset);	gets(buf);	gets(buf);
    while(dataset--) {
    	memset(g, 0, sizeof(g));
    	memset(d, 0, sizeof(d));
    	memset(dis, 0, sizeof(dis));
    	memset(ext, 0, sizeof(ext));
    	while(gets(buf) && buf[0]) {
    		char *token=strtok(buf, " ");
    		char c=token[0];	token=strtok(NULL, " ");
    		t[c-'A']=atol(token);	token=strtok(NULL, " ");
    		ext[c-'A']=true;
    		if(token) {
    			for(int i=0; token[i]; ++i) {
    				g[token[i]-'A'][c-'A']=true;
    				d[c-'A']++;
    	    		ext[token[i]-'A']=true;
    			}
    		}
    	}

    	int sz=0;
    	for(int i=0; i<MAXN; ++i) {
    		if(ext[i] && !d[i]) {
    			q[sz++]=i;
    			dis[i]=t[i];
    		}
    	}

    	int bgn=0, key=0;
    	while(bgn<sz) {
    		int u=q[bgn++];
    		key=max(key, dis[u]);
    		for(int v=0; v<MAXN; ++v) {
    			if(g[u][v]) {
    				--d[v];
    				dis[v]=max(dis[v], dis[u]+t[v]);
    				if(!d[v]) {
    					q[sz++]=v;
    				}
    			}
    		}
    	}

    	printf("%d\n", key);

    	if(dataset)
    		putchar(10);
    }

    return 0;
}

