/*
 * 10646 - What is the Card?
 *
 * simulation...
 * no trick
 * but please read the problem description carefully
 * "Initially there is a pile consisting of 52 cards with card faces down."
 * what's the meaning of "faces down"?
 *
 * have a short think, and got ac
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
#define MAXN 52
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct CARD {
	char v[3];
	int key;
	void read() {
		scanf("%s", v);
		if('2'<=v[0] && v[0]<='9')
			key=v[0]-'2';
		else
			key=10;
	}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
        deque<CARD> a;
        deque<CARD> b;
        CARD t;

        for(int i=0; i<27; ++i) {
        	t.read();
        	b.push_front(t);
        }

        for(int i=0; i<25; ++i) {
        	t.read();
        	a.push_front(t);
        }

        int y=0;
        for(int op=0; op<3; ++op) {
        	y += b.front().key;
        	int d = 10 - b.front().key + 1;
        	while(d--) {
        		b.pop_front();
        	}
        }

        printf("Case %d: ", cas);
        if((int)b.size()>=y) {
        	puts(b[ b.size()-y ].v);
        } else {
        	puts(a[ a.size()+b.size()-y ].v);
        }
    }

    return 0;
}

