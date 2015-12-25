/*
 * 11525 - Permutation
 *
 * data struct...
 * Ad hoc...
 * ��֪������ù�Ϊ���ࡣ����
 *
 * ��K�����ĵ�N��permutation
 * ����3���������
 * N = n1 n2 n3
 * S = s1 s2 s3
 * ��ʼ����Ԫ�� X = { 1 2 3 }
 *   n1 n2 n3  s1   s2   s3
 * 0th 1 2 3    0   0    0
 * 1th 1 3 2    0   1    0
 * 2th 2 1 3    1   0    0
 * 3th 2 3 1    1   1    0
 * 4th 3 1 2    2   0    0
 * 5th 3 2 1    2   1    0
 * ���Թ۲쵽������k����n1=(s1+1)th����X����ɾ��n1������(s1+1)����
 * ʣ�µ�k-1������n2=(s2+1)th����X����ɾ��n2������(s2+1)����
 * ������
 *
 * Ҳ����˵��ÿ�����Ǵ�1-K��������ɾ����si+1��������������ǵ�ǰ�Ľ�
 * ɾ����P������������ƽ������ʵ�֣����򵥵㣬д����״����Ϳ����ˡ���
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
