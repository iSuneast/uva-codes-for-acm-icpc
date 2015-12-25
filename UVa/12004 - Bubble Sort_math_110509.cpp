/*
 * 12004 - Bubble Sort
 *
 * math
 * generate the first few answers
 * and find a law
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
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

int findSwaps(int n, int a[]) {
	int count = 0, i, j, temp, b[100000];
	for (i = 0; i < n; i++) {
		b[i] = a[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (b[j] > b[j + 1]) {
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				count++;
			}
		}
	}
	return count;
}

const int N=8;
int v[N+1], n, tot;
LL sum;
bool flag[N+1];

void dfs(int dep) {
	if(dep==n) {
		tot++;
		sum+=findSwaps(n, v);
	} else for(int i=0; i<n; ++i) {
		if(!flag[i]) {
			flag[i]=true;
			v[dep]=i;
			dfs(dep+1);
			flag[i]=false;
		}
	}
}

LL gcd(LL a, LL b) {
	return b==0? a: gcd(b, a%b);
}

void generate() {
	for(n=1; n<=N; ++n) {
		tot=0;
		sum=0;
		dfs(0);

		LL t=gcd(sum, tot);
		cout<<sum/t<<"  "<<tot/t<<endl;
	}
}

LL a[MAXN], b[MAXN];

void init() {
	a[0]=0;
	b[0]=0;
	for(int i=1; i<MAXN; ++i) {
		a[i]=a[i-1]+i-1;
		b[i]=2;
	}
	for(int i=1; i<MAXN; ++i) {
		if(a[i]%2==0) {
			a[i]/=2;
			b[i]=0;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

//	generate();
	init();
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d", &n);
		if(!b[n])
			printf("Case %d: %lld\n", cas, a[n]);
		else
			printf("Case %d: %lld/%lld\n", cas, a[n], b[n]);
	}

	return 0;
}


