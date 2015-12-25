/*
 * 11961 - DNA
 *
 * brute force
 * O(2^n) time bit mask subset brute force
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
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int dataset, h[128], key[6], n, k;
    h[0]='A';
    h[1]='C';
    h[2]='G';
    h[3]='T';

    key[0]=1;
    for(int i=1; i<6; ++i) {
    	key[i]=key[i-1]*4;
    }

    char dna[13], ans[13];
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &k);
    	for(int i=0; i<n; ++i) {
    		scanf(" %c", &dna[i]);
    	}
    	dna[n]=ans[n]=0;

    	int all=(1<<(2*n)), cnt=0;

    	for(int i=0; i<all; ++i) {
    		int t=i, d=0;
    		for(int j=n-1; j>=0; --j) {
    			ans[j]=h[ t%4 ];
    			t/=4;
    			if(ans[j]!=dna[j])
    				++d;
    		}

    		if(d<=k) {
    			++cnt;
    		}
    	}

    	printf("%d\n", cnt);
    	for(int i=0; i<all; ++i) {
    		int t=i, d=0;
    		for(int j=n-1; j>=0; --j) {
    			ans[j]=h[ t%4 ];
    			t/=4;
    			if(ans[j]!=dna[j])
    				++d;
    		}

    		if(d<=k) {
    			puts(ans);
    		}
    	}
    }

    return 0;
}

