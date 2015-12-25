/*
 * 10085 - The most distant state
 *
 * graph theory...
 * bfs...
 * eight puzzle~
 *
 * fairy simple problem...
 * you just need to extend every possible state using bfs
 * and choose the last node you got
 *
 * happy coding~
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAX_PER 362880
#define MAX_NODE 986410
#define MAX_STATE MAX_PER*4
#define MAXN 9
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

struct STATE {
	int v[MAXN];
	void read() {
		for(int i=0; i<MAXN; ++i) {
			scanf("%d", &v[i]);
		}
	}
	void output() {
		for(int i=0; i<3; ++i) {
			printf("%d %d %d\n", v[i*3], v[i*3+1], v[i*3+2]);
		}
	}
}state[MAX_PER], ori;
vector< pair<int, char> > edge[MAX_PER];

struct TRIE {
	TRIE *son[9];
	int code;
	void clear() {
		memset(son, 0, sizeof(son));
	}
}node[MAX_NODE];
int tot, buf[MAXN], pos;
bool flag[MAXN];

void insert() {
	TRIE *cur=&node[0];
	int p=0;
	while(p<MAXN) {
		if(!cur->son[ buf[p] ]) {
			node[tot].clear();
			cur->son[ buf[p] ]=&node[tot++];
		}
		state[pos].v[p]=buf[p];
		cur=cur->son[ buf[p++] ];
	}
	cur->code=pos++;
}

void dfs(int dep) {
	if(dep==MAXN) {
		return insert();
	} else for(int i=0; i<MAXN; ++i) {
		if(!flag[i]) {
			flag[i]=true;
			buf[dep]=i;
			dfs(dep+1);
			flag[i]=false;
		}
	}
}

int encode(STATE &s) {
	TRIE *cur=&node[0];
	int p=0;
	while(p<MAXN) {
		cur=cur->son[ s.v[p++] ];
	}
	return cur->code;
}

void trie(TRIE *cur, int dep,int p) {
	if(dep==MAXN) {
		int r=p/3, c=p%3;
		STATE &tmp=state[cur->code];
		if(r) {
			swap(tmp.v[p], tmp.v[p-3]);
			edge[cur->code].push_back( make_pair(encode(tmp), 'U') );
			swap(tmp.v[p], tmp.v[p-3]);
		}
		if(c) {
			swap(tmp.v[p], tmp.v[p-1]);
			edge[cur->code].push_back( make_pair(encode(tmp), 'L') );
			swap(tmp.v[p], tmp.v[p-1]);
		}
		if(r!=2) {
			swap(tmp.v[p], tmp.v[p+3]);
			edge[cur->code].push_back( make_pair(encode(tmp), 'D') );
			swap(tmp.v[p], tmp.v[p+3]);
		}
		if(c!=2) {
			swap(tmp.v[p], tmp.v[p+1]);
			edge[cur->code].push_back( make_pair(encode(tmp), 'R') );
			swap(tmp.v[p], tmp.v[p+1]);
		}
	} else for(int i=0; i<MAXN; ++i) {
		if(cur->son[i]) {
			trie(cur->son[i], dep+1, i==0? dep: p);
		}
	}
}

void init() {
	pos=0;
	node[0].clear();
	tot=1;
	memset(flag, 0, sizeof(flag));
	dfs(0);

	trie(&node[0], 0, -1);
}

bool fade[MAX_PER];
int fa[MAX_PER], q[MAX_PER], dis[MAX_PER];
char op[MAX_PER];
int bgn;

int bfs() {
	int front=0, rear=0;
	memset(fade, 0, sizeof(fade));
	q[rear++]=bgn=encode(ori);
	fade[bgn]=true;
	dis[bgn]=0;

	while(front<rear) {
		int &u=q[front++];
		for(int i=0; i<(int)edge[u].size(); ++i) {
			int &v=edge[u][i].first;
			if(!fade[v]) {
				fade[v]=true;
				dis[v]=dis[u]+1;
				fa[v]=u;
				op[v]=edge[u][i].second;
				q[rear++]=v;
			}
		}
	}

	return q[rear-1];
}

void rout(int p) {
	if(p==bgn)
		return ;
	rout(fa[p]);
	putchar(op[p]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    int dataset;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	ori.read();
    	printf("Puzzle #%d\n", cas);
    	int key=bfs();
    	state[key].output() ;
    	rout(key);
    	putchar(10);
    }

    return 0;
}

