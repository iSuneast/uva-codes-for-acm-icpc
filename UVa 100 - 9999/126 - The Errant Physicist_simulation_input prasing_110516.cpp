/*
 * 126 - The Errant Physicist
 *
 * simulation
 * input parsing
 * just hard coding~
 *
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
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct DATA {
	int x, y, a;
	void clear() {
		a = x = y = 0;
	}
	bool operator<(const DATA &t) const {
		return (x == t.x) ? y < t.y : x > t.x;
	}
} cur;

char buf[100];
vector<DATA> a, b;
set<DATA> rem;
typedef set<DATA>::iterator sit;

bool read(vector<DATA> &t) {
	if (!gets(buf + 1) || strcmp(buf + 1, "#") == 0)
		return false;
	t.clear();

	int i = 0;
	if (buf[1] == '+' || buf[1] == '-')
		i = 1;
	else
		buf[0] = '+';

	while (buf[i]) {
		int j = i + 1;
		while (buf[j] && buf[j] != '+' && buf[j] != '-')
			++j;

		cur.clear();
		int p = i + 1;
		if (isdigit(buf[p])) {
			while (isdigit(buf[p])) {
				cur.a = cur.a * 10 + buf[p] - '0';
				++p;
			}
		} else {
			cur.a = 1;
		}

		if (buf[i] == '-')
			cur.a *= -1;
		i = p;

		for (int k = i; k < j;) {
			bool x = (buf[k] == 'x');
			int l = k + 1, v = 0;
			bool flag = (buf[l] != '-');
			if (buf[l] == '+' || buf[l] == '-')
				++l;
			if (isdigit(buf[l])) {
				while (isdigit(buf[l])) {
					v = v * 10 + buf[l] - '0';
					++l;
				}
			} else {
				v = 1;
			}

			if (!flag)
				v *= -1;

			if (x)
				cur.x = v;
			else
				cur.y = v;

			k = l;
		}

		t.push_back(cur);

		i = j;
	}
	return true;
}

void multiply() {
	rem.clear();
	for (int i = 0; i < (int) a.size(); ++i) {
		for (int j = 0; j < (int) b.size(); ++j) {
			cur.a=a[i].a*b[j].a;
			cur.x=a[i].x+b[j].x;
			cur.y=a[i].y+b[j].y;

			sit it=rem.find(cur);
			if(it!=rem.end()) {
				cur.a+=it->a;
				rem.erase(it);
			}
			if(cur.a)
				rem.insert(cur);
		}
	}
}

char ans[2][100];

int fill_in(char *p, int v) {
	if(v==1)
		return 0;
	int add=0;
	sprintf(buf, "%d", v);
	for( ; buf[add]; ++add) {
		p[add]=buf[add];
	}
	return add;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	while (read(a) && read(b)) {
		multiply();

		memset(ans, ' ', sizeof(ans));
		int p=0;
		for(sit it=rem.begin(); it!=rem.end(); ++it) {
			int v=it->a;
			if(v<0) {
				v=-v;
				if(p) {
					ans[1][p+1]='-';
					p+=3;
				} else {
					ans[1][p+1]='-';
					p+=2;
				}
			} else {
				if(p) {
					ans[1][p+1]='+';
					p+=3;
				} else {
					++p;
				}
			}

			if(v==1 && !it->x && !it->y)
				ans[1][p++]='1';
			else
				p+=fill_in(ans[1]+p, v);

			if(it->x) {
				ans[1][p++]='x';
				p+=fill_in(ans[0]+p, it->x);
			}


			if(it->y) {
				ans[1][p++]='y';
				p+=fill_in(ans[0]+p, it->y);
			}
		}

		ans[0][p]=ans[1][p]=0;
		puts(ans[0]+1);
		puts(ans[1]+1);
	}

	return 0;
}

