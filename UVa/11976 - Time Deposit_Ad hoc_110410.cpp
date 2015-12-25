/*
 * 11976 - Time Deposit
 *
 * Ad hoc...
 * time calculate
 * because the time duration is quite small
 * we can use a flag[] array to mark the weekdays
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
#define MAXN 18667
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)	a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)	a=b;}

int date[MAXN];
int days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool flag[MAXN];

bool leap(int y) {
	return y%4==0;
}

void init() {
	int y=1975, m=1, d=1;
	for(int i=0; i<MAXN; ++i) {
		date[i]=y*10000+m*100+d;

		++d;
		if(d>days[m]) {
			d=1;
			++m;
			if(m>12) {
				m=1;
				++y;
				days[2]=leap(y)? 29: 28;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    init();

    int dataset, y, m, d, n;
    char op;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d", &n);

    	for(int i=0; i<MAXN; ++i) {
    		int t=(i+3)%7;
    		if(!t)
    			t=7;
    		if(t<=5)
    			flag[i]=true;
    		else
    			flag[i]=false;
    	}

    	for(int i=0; i<n; ++i) {
        	scanf("%d%*c%d%*c%d %c", &y, &m, &d, &op);
        	int p=lower_bound( date, date+MAXN, y*10000+m*100+d )-date;
        	if(op=='H')
        		flag[p]=false;
        	else
        		flag[p]=true;
    	}

    	scanf("%d%*c%d%*c%d", &y, &m, &d);
    	int s=lower_bound( date, date+MAXN, y*10000+m*100+d )-date;
    	scanf("%d%*c%d%*c%d", &y, &m, &d);
    	int e=lower_bound( date, date+MAXN, y*10000+m*100+d )-date;

    	int key=0;
    	for(int i=s; i<=e; ++i) {
    		if(flag[i])
    			++key;
    	}

    	printf("Case %d: %d\n", cas, key);
    }

    return 0;
}

