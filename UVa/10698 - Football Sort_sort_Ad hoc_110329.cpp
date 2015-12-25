/*
 * 10698 - Football Sort
 *
 * Ad hoc...
 * sort
 * at first, I don't quite understand the sentence in the problem description
 * "percentage of earned points, when available."
 * it means we can at most got 3 points in a played
 * so, the value is points/(3*played)*100
 *
 * a huge trick exist, but I miss it = =
 * when searching for the exact meaning of the sentence above, I suddenly notice that
 * "the teams appear in order of classification, or alphabetically"
 * "alphabetically" ? yes?
 * not "lexicographic order"
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
#define MAXN 30
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

struct TEAM {
	char name[18], low[18];
	int points, played, scored, suffered, difference;
	void read() {
		scanf("%s", name);
		for(int i=strlen(name); i>=0; --i) {
			low[i]=tolower(name[i]);
		}
		points=0, played=0, scored=0, suffered=0;
		difference=0;
	}

	void modify(int add, int s, int l) {
		points += add;
		++played;
		scored += s;
		suffered += l;
		difference=scored-suffered;
	}

	bool operator<(const TEAM &t) const {
		if( points == t.points ) {
			if(difference == t.difference) {
				if( scored == t.scored )
					return strcmp(low, t.low)<0;
				return scored > t.scored;
			}
			return difference > t.difference;
		}
		return points > t.points;
	}

	bool operator==(const TEAM &t) const {
		return points == t.points
			&& difference == t.difference
			&& scored == t.scored;
	}

}team[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int T, G;
    char a[18], b[18];
    int sa, sb, ida, idb, adda, addb;
    bool first=true;
    while(scanf("%d %d", &T, &G)!=EOF && (T || G)) {
    	if(!first)
    		putchar(10);
    	first=false;

    	map<string, int> msi;
    	for(int i=0; i<T; ++i) {
    		team[i].read();
    		msi[ team[i].name ]=i;
    	}

    	while(G--) {
    		scanf("%s %d %*s %d %s", a, &sa, &sb, b);
    		ida = msi[a];
    		idb = msi[b];
    		if(sa > sb) {
    			adda = 3;
    			addb = 0;
    		} else if( sa < sb ) {
    			adda = 0;
    			addb = 3;
    		} else
    			adda = addb = 1;

    		team[ ida ].modify(adda, sa, sb);
    		team[ idb ].modify(addb, sb, sa);
    	}

    	sort(team, team+T);
    	for(int i=0; i<T; ++i) {
    		if(i && team[i]==team[i-1])
    			printf("   ");
   			else
    			printf("%2d.", i+1);

			printf("%16s%4d%4d%4d%4d%4d",
					team[i].name, team[i].points,
					team[i].played, team[i].scored,
					team[i].suffered, team[i].difference);
			if(!team[i].played)
				puts("    N/A");
			else
				printf("%7.2lf\n", team[i].points/(team[i].played*3.0)*100.0);
    	}
    }

    return 0;
}

