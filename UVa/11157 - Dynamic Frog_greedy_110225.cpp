/*
 * 11157 - Dynamic Frog
 *
 * greedy...
 * 贪心的想法不好想阿。。。
 * 如果二分答案+最大流也可以吧，不过貌似复杂了点。。。
 *
 * 由于跳的过程中，SMALL至多经过1次，BIG至多经过2次
 * 所以，可以把每个BIG石头分解成2个SMALL石头
 * 按石头的位置升序排列
 * 现在，每块石头至多只能走一次，所以我们选择两条交错的路径，即：
 * STONE_1 STONE_2 STONE_3 STONE_4 STONE_5 ...
 * 从左往右跳选择奇数编号石头，从右往左跳，选择偶数编号石头，这样，最大距离必定最小
 *
 * 证明：
 * STONE_1 STONE_2 STONE_3 STONE_4 STONE_5 ...
 * 从STONE_2直接跳到STONE_3，则回来的时候至少要从STONE_4跳到STONE_1
 *    解必 >= STONE_4 - STONE_1
 * 若从STONE_2直接跳到STONE_4，则回来的时候从STONE_3跳到STONE_1
 *    解为 max( STONE_4 - STONE_2,  STONE_3 - STONE_1 ) 更优
 * 所以，贪心是可行的～
 *
 * happy coding～
 */

#include<cstdio>
#include<algorithm>
#define MAXN 103
using namespace std;

struct STONE {
	int d;
	bool big, fade;
	STONE(){}
	STONE(int _d, bool _b):d(_d), big(_b) { fade=false; }
	bool operator<(const STONE &t) const {
		return d<t.d;
	}
}stone[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, d, n;
    char buf[30];
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d %d", &n, &d);

    	for(int i=0; i<n; ++i) {
    		scanf("%s", buf);
    		stone[i].big = (buf[0]=='B');
    		sscanf(buf, "%*c%*c%d", &stone[i].d);
    		stone[i].fade=false;
    	}
    	stone[n++]=STONE(0, true);
    	stone[n++]=STONE(d, true);
    	sort(stone, stone +n);

    	int key=0;
    	for(int i=0; i<n; ) {
    		if(!stone[i].big)
    			stone[i].fade=true;

    		if(i+1<n && stone[i+1].big) {
   				key=max(key, stone[i+1].d - stone[i].d);
    			++i;
    		} else {
    			if(i+2<n)
    				key=max(key, stone[i+2].d - stone[i].d);
    			i+=2;
    		}
    	}

    	for(int i=n-1; i>=0; ) {
    		int j=i-1;
    		for( ;j>=0; --j) {
    			if(!stone[j].fade)
    				break;
    		}

    		if(j>=0)
    			key=max(key, stone[i].d - stone[j].d);

    		i=j;
    	}

    	printf("Case %d: %d\n", cas, key);
    }

    return 0;
}

