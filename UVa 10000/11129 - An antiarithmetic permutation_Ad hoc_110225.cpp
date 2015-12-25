/*
 * 11129 - An antiarithmetic permutation
 *
 * Ad hoc...
 * 首先，必须能观察到一点，odd even even 或者 even odd odd是不可能构成等差数列的
 * 所以可以把，序列按照奇偶分成两个部分
 * 如果把奇数写成二进制的格式 odd = ...???1
 * 同理，把偶数写成二进制的格式 even = ...???0
 * 于是，我们发现，奇偶其实只是根据二进制的最后一位来区分的
 *
 * 对于奇数部分， odd = ...?1 由上述可知，?必为0或者1，于是又可以继续分组了。。。
 * 偶数同理
 * 分完后，如果把具体的分法画出来会发现其实就是一颗二叉树
 * n = 5 的二叉树，表示如下
 *
 *         ROOT
 *      ===========
 *      0         1
 *    ------    ------
 *    0    1    0    1
 *  -----
 *  0   1
 * 所以，构造得到一种答案的二进制为
 * { 000, 100 , 10 , 01 , 11 } -> { 0, 4, 2, 1, 3 }
 *
 * 构造的复杂度O(NlogN)
 * 如果用dfs的话，代码长度不会超过20行的 = =
 *
 * happy coding~
 */

#include<cstdio>

int n;

void dfs(int v,int dep) {
	if(v>=n)
		return ;
	else if((1<<dep)>=n) {
		printf(" %d", v);
		return ;
	}

	dfs(v, dep+1);
	dfs(v+(1<<dep), dep+1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    while(scanf("%d", &n)!=EOF && n) {
    	printf("%d:", n);
    	dfs(0,0);
    	putchar(10);
    }

    return 0;
}

