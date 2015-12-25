/*
 * 10666 - The Eurocup is Here!
 *
 * Ad hoc...
 * obviously, we can't solved it using straight forward brute force
 *
 * according to the problem, we can build a graph below
 * 0 -> 1
 * | -> 2 -> 3
 * | -> 4 -> 5
 *      | -> 6 -> 7
 *
 * a -> b means that, S(a)<S(b)
 * so have a greedy think, for team_1, we can got
 * best = 2  # after 0
 * worst = 8 # the last
 * for team_2, almost the same
 * best = 2  # after 0
 * worst = 7 # just before 3
 * ...
 *
 * Yes, the same idea with Topological-Sort
 *
 * for X, we need to count
 *
 * pessimistic classification:
 * the ROUND id he lose (begin with 0)  # the index of the right-most 1 in binary
 *         # 3 = (11)_2 round(3)=0
 *         # 4 = (100)_2 round(4)=2
 *         ....
 * there are at most (1<<round) teams worse than current, so
 * the final answer is = (1<<N)-(1<<round)+1
 *
 * optimistic classification:
 * the team better than him   # the bits of "1" in binary
 *         # better than 2 = (10)_2 ,  1 teams
 *         # better than 3 = (11)_2 ,  2 teams
 *         # better than 4 = (100)_2 , 1 teams
 *         ...
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
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, N, X;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d", &N, &X);

    	int round;
    	for(round=0; round<N; ++round) {
    		if(X&(1<<round)) {
    			break;
    		}
    	}

    	int key=1;
    	for(int i=0; i<N; ++i) {
    		if(X&(1<<i))
    			++key;
    	}

    	printf("%d %d\n", key, (1<<N)-(1<<round)+1);
    }

    return 0;
}

