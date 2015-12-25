/*
 * 11569 - Lovely Hint
 *
 * brute force...
 * 直接暴力搜索就可以了。。。
 * 因为最多只有26个字母，并且条件5 × V1 ≤ 4 × V2的剪枝效果是很强的。。。
 * 根本不用担心TLE。。。
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 27
using namespace std;

bool h[MAXN];
char buf[300];
int key[MAXN], var[MAXN], n;

void dfs(int s,int dep) {
	key[dep]++;
	for(int p=s+1; p<n; ++p) {
		if(var[p]*4>=5*var[s]) {
			dfs(p, dep+1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d", &dataset);	gets(buf);
	while(dataset--) {
		gets(buf);
		memset(h,0,sizeof(h));
		for(int i=0; buf[i]; ++i) {
			if( isupper(buf[i]) )
				h[ buf[i]-'A'+1 ]=true;
		}

		n=0;
		var[n++]=0;
		memset(key,0,sizeof(key));
		for(int i=1; i<MAXN; ++i) {
			if(h[i])
				var[n++]=i;
		}

		dfs(0,0);
		for(int i=MAXN-1; i>0; --i) {
			if(key[i]) {
				printf("%d %d\n", i, key[i]);
				break;
			}
		}
	}

	return 0;
}
