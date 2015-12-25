/*
 * 10993 - Ignoring Digits
 *
 * bfs
 * there are at most n candidate answer :
 *  {0<= TmpAnswer%n < n}
 *
 * so a simple bfs function will do
 * don't push the TmpAnswer into the queue which TmpAnswer%n has already exist
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
#define MAXN 100001
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

char f[11];
bool flag[10], res[MAXN];
string dig[10];
int n;

void bfs() {
	memset(res, 0, sizeof(res));

	typedef pair<string, int> NODE;
	queue< NODE > q;
	for(int i=1; i<10; ++i) {
		if(flag[i]) {
			int t=i%n;
			if(!t) {
				printf("%d\n", i);
				return ;
			}
			q.push( make_pair(dig[i], t) );
			res[t]=true;
		}
	}

	while(!q.empty()) {
		NODE cur=q.front();	q.pop();
		int r=cur.second;
		for(int i=0; i<10; ++i) {
			if(!flag[i])
				continue;
			int t=(r*10+i)%n;

			if(!t) {
				cout<<cur.first<<i<<endl;
				return ;
			}

			if(res[t])
				continue;

			res[t]=true;
			q.push(make_pair( cur.first+dig[i], t));
		}
	}

	puts("impossible");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    dig[0]="0";
    for(int i=1; i<10; ++i) {
    	dig[i]=dig[0];
    	dig[i][0]='0'+i;
    }

    while(scanf("%s %d", f, &n)!=EOF && strcmp(f, "0") && n!=0) {
    	memset(flag, 0, sizeof(flag));
    	for(int i=0; f[i]; ++i) {
    		flag[(int)(f[i]-'0')]=true;
    	}

    	bfs();
    }

    return 0;
}

