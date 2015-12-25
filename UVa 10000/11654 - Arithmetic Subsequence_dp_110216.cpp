/*
 * 11654 - Arithmetic Subsequence
 *
 * dp...
 * �����ˡ�����
 * Ӧ�������˰ɡ�������ô���Ե�dpģ�;�Ȼû�п����� =_=
 * for i: 0->n
 *    for j: i-1->0
 *       dp[i][j]=1
 *       for k: j-1->0
 *          ����var[k]-var[j] == var[j]-var[i]
 *          ��dp[i][j]+=dp[j][k]
 * �����ˡ�����
 * ��~
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 255
#define MOD 10000007
using namespace std;

int var[MAXN], n, dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d", &n);
		for(int i=0; i<n; ++i) {
			scanf("%d", &var[i]);
		}

		memset(dp, 0, sizeof(dp));
		int key=n;
		for(int i=0; i<n; ++i) {
			for(int j=i-1; j>=0; --j) {
				dp[i][j]=1;
				for(int k=j-1; k>=0; --k) {
					if(var[k]-var[j]==var[j]-var[i])
						dp[i][j] = (dp[i][j]+dp[j][k])%MOD;
				}
				key = ( key+dp[i][j] )%MOD;
			}
		}

		printf("Case %d: %d\n", cas, key);
	}

	return 0;
}
