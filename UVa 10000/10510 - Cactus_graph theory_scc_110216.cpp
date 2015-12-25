/*
 * 10510 - Cactus
 *
 * graph theory...
 * scc...
 *
 * Cactus����
 *   @ it is strongly connected �ȼ��ͼ�ǲ���scc
 *   @ each edge is part of exactly one directed simple cycle
 *        ÿ����ֻ�ܳ�����һ���򵥻����棬�������㿪ʼdfs
 *        ����������dep[],low[]�ֱ��ʾ
 *           ���u����ȣ��Լ�uͨ���ӽڵ�����ܷ��ص������
 *        ��color[]����ǽ���״̬
 *           -1�ڵݹ�ջ�У�0δ���ʣ�1��������
 *        ���u���Ե���v��
 *           color[v]=-1 ��low[u]=min(dep[v])
 *           color[v]=1  ��low[u]=min(low[v])
 *           color[v]=0  ����v
 *           �������dep[v]>dep[u]+1����˵��(u,v)��ǰ��ߣ��޽�
 *        ����ж���1��v���㣬low[v]<dep[u]����˵����u�����ж�������ߣ��޽�
 *
 * �������£�ͼ�Ǹ�scc����sccͼ���治��ǰ��ߣ���ÿ�����������ֻ��һ������ߡ�����
 *
 * happy coding~
 */

#include<iostream>
#include<vector>
#define MAXN 10003
using namespace std;

vector<int> edge[MAXN];
int n, m, topo[MAXN*2], tot;
int vis[MAXN];

void dfs_chk(int u) {
	vis[u]=true;
	for(int sz=edge[u].size(), i=0; i<sz; ++i) {
		if(!vis[ edge[u][i] ])
			dfs_chk( edge[u][i] );
	}
	topo[--tot]=u;
}

int scc() {
	memset(vis, 0, sizeof(vis));
	tot=n;
	for(int i=0; i<n; ++i) {
		if(!vis[i])
			dfs_chk(i);
	}

	memset(vis, 0, sizeof(vis));
	tot=2*n;
	int cc=0;
	for(int i=n-1; i>=0; --i) {
		if(!vis[ topo[i] ]) {
			dfs_chk(topo[i]);
			++cc;
		}
	}

	return cc;
}

int low[MAXN], dep[MAXN], rev[MAXN];
bool fade;

void ChkMin(int &a, const int &t) {
	if(a>t)
		a=t;
}

bool dfs(int u,int depth) {
	vis[u]=-1;
	low[u]=dep[u]=depth;
	for(int sz=edge[u].size(), i=0; i<sz; ++i) {
		int v=edge[u][i];

		if(!vis[v] && !dfs(v, depth+1) )
			return false;
		if(dep[v] > dep[u]+1)
			return false;
		if(low[v]<depth) {
			if(!rev[u])
				rev[u]=true;
			else
				return false;
		}

		if(vis[v]==1)
			ChkMin(low[u], low[v]);
		else
			ChkMin(low[u], dep[v]);
	}

	vis[u]=1;
	return true;
}

bool Cactus() {
	if( scc()!=1 )
		return false;

	memset(vis, 0, sizeof(vis));
	memset(rev, 0, sizeof(rev));
	return dfs(0, 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	while(dataset--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; ++i) {
			edge[i].clear();
		}
		for(int u, v; m--; ) {
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}

		puts(Cactus()? "YES": "NO");
	}

	return 0;
}
