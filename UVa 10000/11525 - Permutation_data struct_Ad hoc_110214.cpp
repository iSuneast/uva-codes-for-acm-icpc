/*
 * 11525 - Permutation
 *
 * data struct...
 * Ad hoc...
 * 不知道这题该归为哪类。。。
 *
 * 求K个数的第N个permutation
 * 考虑3个数的情况
 * N = n1 n2 n3
 * S = s1 s2 s3
 * 初始集合元素 X = { 1 2 3 }
 *   n1 n2 n3  s1   s2   s3
 * 0th 1 2 3    0   0    0
 * 1th 1 3 2    0   1    0
 * 2th 2 1 3    1   0    0
 * 3th 2 3 1    1   1    0
 * 4th 3 1 2    2   0    0
 * 5th 3 2 1    2   1    0
 * 可以观察到，对于k个数n1=(s1+1)th，从X里面删除n1，即第(s1+1)个数
 * 剩下的k-1个数，n2=(s2+1)th，从X里面删除n2，即第(s2+1)个数
 * 。。。
 *
 * 也就是说，每次我们从1-K的序列中删除第si+1个数，这个数就是当前的解
 * 删除第P个数，可以用平衡树来实现，更简单点，写个树状数组就可以了。。
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 50001
#define lowbit(p) (p&(-p))
using namespace std;

int s[MAXN], n;

void insert(int p,int d) {
	for(; p<=n ;p+=lowbit(p)) {
		s[p]+=d;
	}
}

int sum(int p) {
	int key=0;
	for( ; p; p-=lowbit(p)) {
		key+=s[p];
	}
	return key;
}

int b_located(int p) {
	int bgn=1, end=n;
	while(bgn<=end) {
		int mid=(bgn+end)>>1, t=sum(mid);
		if(t<p)
			bgn=mid+1;
		else
			end=mid-1;
	}
	return bgn;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, t;
	scanf("%d", &dataset);
	while(dataset--) {
		scanf("%d", &n);
		memset(s,0,sizeof(s));
		for(int i=1; i<=n; ++i) {
			insert(i,1);
		}

		for(int i=0; i<n; ++i) {
			scanf("%d", &t);
			if(i)
				putchar(' ');
			int key=b_located(t+1);
			printf("%d", key);
			insert(key, -1);
		}
		putchar(10);
	}

	return 0;
}
