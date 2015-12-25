/*
 * 430 - Swamp County Supervisors
 *
 * dp...
 * knapsack...
 * 花了几个提交来测试数据范围，最终发现通过的票数<10000
 * 而且总共就只有27个人
 * 所以就可以用背包来枚举状态了
 *
 * 对其他n-1个人，枚举出所有可能得到的<=VOTE次选票的组合数
 * 当前这个人的答案就是[ VOTE-vote[i], VOTE] 区间组合数的和
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 10000
#define MAXP 30
using namespace std;

int dp[MAXN], n, ppl[MAXP], bound;
char buf[100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(gets(buf)) {
		char *token = strtok(buf, " ");
		bound = atol(token);
		for( n=0,token=strtok(NULL," "); token; token=strtok(NULL," ")) {
			ppl[n++] = atol(token);
		}

		for(int id=0; id<n; ++id) {
			memset(dp, 0, sizeof(dp));
			dp[0]=1;
			for(int i=0; i<n; ++i) {
				if(i==id)
					continue;
				for(int p=bound; p>=ppl[i]; --p) {
					if(dp[ p-ppl[i] ])
						dp[p] += dp[ p-ppl[i] ];
				}
			}

			int key=0;
			for(int p= bound-ppl[id]; p<bound; ++p) {
				key+=dp[p];
			}

			if(id)
				putchar(' ');
			printf("%d", key);
		}
		putchar(10);
	}

	return 0;
}
