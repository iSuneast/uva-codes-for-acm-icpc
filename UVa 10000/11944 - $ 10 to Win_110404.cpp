/*
 * 11944 - $ 10 to Win?
 *
 * simulation~
 * just simulate as the problem description
 *
 * notice of these two sentence:
 * "The multiplier is always rounded to three digits after the decimal point."
 * "The amount won is always rounded to next value integer if the amounts won contains cents"
 *
 * no more tricks
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

    int dataset;
    char buf[100];
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	LL final;
    	int n, t;
    	double rate;
    	scanf("%lld %d", &final, &n);
    	for(int i=0; i<n; ++i) {
    		scanf("%d", &t);

    		if(t>0) {
    			sprintf(buf, "%.3lf", t/100.0);
    		} else {
    			sprintf(buf, "%.3lf", 100.0/(-t));
    		}
    		sscanf(buf, "%lf", &rate);

    		final = ceil(final*(1+rate));

        	if(final>=1000000)
        		final=1000000;
    	}

    	printf("%d $", cas);
    	if(final<1000) {
    		printf("%lld.00\n", final);
    	} else {
        	vector<int> vi;
        	while(final) {
        		vi.push_back(final%1000);
        		final/=1000;
        	}
        	int sz=vi.size();
        	printf("%d", vi[sz-1]);
        	for(int i=sz-2; i>=0; --i) {
        		printf(",%03d", vi[i]);
        	}
        	printf(".00\n");
    	}
    }

    return 0;
}

