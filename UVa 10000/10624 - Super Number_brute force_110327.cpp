/*
 * 10624 - Super Number
 *
 * brute force...
 * a straight forward brute force method with simple pruning will do
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
#define MAXN 33
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int n, m, key[MAXN];
bool got;

void dfs(int dep) {
	if(dep==m+1) {
		got=true;
	} else {
		if(dep<n) {
			for(int i=0; i<10; ++i) {
				key[dep]=i;
				dfs(dep+1);
				if(got)
					return ;
			}
		} else {
			int mod=0;
			for(int i=1; i<dep; ++i) {
				mod=(mod*10+key[i])%dep;
			}

			for(int i=0; i<10; ++i) {
				if((mod*10+i)%dep==0) {
					key[dep]=i;
					dfs(dep+1);
					if(got)
						return ;
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &m);
    	got=false;

    	printf("Case %d: ", cas);
    	for(int i=1; i<10; ++i) {
    		key[1]=i;
        	dfs(2);
        	if(got) {
        		for(int j=1; j<=m; ++j) {
        			printf("%d", key[j]);
        		}
        		putchar(10);
        		break;
        	}
    	}

    	if(!got)
    		puts("-1");
    }

    return 0;
}

