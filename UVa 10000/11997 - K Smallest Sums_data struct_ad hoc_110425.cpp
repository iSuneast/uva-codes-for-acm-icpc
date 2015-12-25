/*
 * 11997 - K Smallest Sums
 *
 * data struct
 * for a n*n array we can do like this:
 * for Row1, we can just sort the integers and got current answer, ANS
 * for Row2, we will still sort the integers
 *
 * ANS && Row2 both has n elements, so we will got n*n sum at last
 * we choose the first n sum as new ANS we got
 * we can reduce the time as this two array are both sorted
 * so we don't have to check all the n*n sum, we just need try the first Nth
 * and break when we can't get a better sum
 *
 * keep tracing, and finally got the answer
 *
 * happy coding
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <set>
#include <ctime>
#define MAXN 753
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
typedef set<int>::iterator sit;

int n, ans[MAXN], var[MAXN], buf[MAXN];
multiset<int> rem;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(scanf("%d", &n)!=EOF) {
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				scanf("%d", &var[j]);
			}
			sort(var, var+n);

			if(!i) {
				for(int j=0; j<n; ++j) {
					ans[j]=var[j];
				}
			} else {
				for(int j=0; j<n; ++j) {
					buf[j]=ans[j];
				}

				rem.clear();
				for(int a=0; a<n; ++a) {
					for(int b=0; b<n; ++b) {
						int t=buf[a]+var[b];
						if((int)rem.size()>n) {
							if(t>=*rem.rbegin())
								break;
							else {
								rem.erase( --rem.end() );
							}
						}
						rem.insert( t );
					}
				}

				int sz=0;
				for(sit it=rem.begin(); it!=rem.end(); ++it) {
					ans[sz++]=*it;
				}
			}
		}

		for(int i=0; i<n; ++i) {
			if(i)
				putchar(' ');
			printf("%d", ans[i]);
		}
		putchar(10);
	}

	return 0;
}


