/*
 * 430 - Swamp County Supervisors
 *
 * dp...
 * knapsack...
 * ���˼����ύ���������ݷ�Χ�����շ���ͨ����Ʊ��<10000
 * �����ܹ���ֻ��27����
 * ���ԾͿ����ñ�����ö��״̬��
 *
 * ������n-1���ˣ�ö�ٳ����п��ܵõ���<=VOTE��ѡƱ�������
 * ��ǰ����˵Ĵ𰸾���[ VOTE-vote[i], VOTE] ����������ĺ�
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
