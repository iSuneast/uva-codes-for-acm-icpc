/*
 * 10090 - Marbles
 *
 * number theory...
 * 这次的报告还是用中文来写吧~
 *
 * 题目意思很简单，给一个n，以及（c1,n1）,（c2,n2）
 * 求x，y满足n1*x+n2*y==n && n1*c1+n2*c2最小
 * ---------------------------------------------
 * 对于第一步，很简单，只需要用扩展欧几里得就可以求出一对合法的x，y
 * 复习一下，扩展欧几里得
 * a*x+b*y=c，有解当且仅当c%gcd（a，b）==0
 * 我们可以进一步得到跌代公式，如下
 * a*x0+b*y0=gcd(a,b)
 * b*x1+(a%b)*y1=gcd(b, a%b)
 * ...
 * 由欧几里得定理得gcd(a,b)==gcd(b,a%b)，则
 * a*x0+b*y0 = b*x1+(a%b)*y1
 * 又a%b = a-(a/b)*b，代入得
 *   a*x0+b*y0
 * = b*x1+(a%b)*y1
 * = b*x1+( a-(a/b)*b )*y1
 * = a*y1 + b*( x1-(a/b)*y1 )
 * 故，x0=y1，y0=x1-(a/b)*y1
 * 则，我们可以得到扩展欧几里得的递归公式为
 * gcd（a，b，x，y） {
 *    gcd（b，a%b，y，x）
 *    y -= a/b*x	// 在纸上画画就知道了
 * }
 * 边界条件为b=0时，x=1，y=0，gcd（）= a
 *
 * 至此，第一个问题解决了
 * ---------------------------------------------
 * 因为方程n1*x+n2*y=n要么无解，要么有无穷的解
 * 因此（x'，y'）仅为gcd对方程n1*x+n2*y=gcd(n1,n2)求出来的一组解
 * 方程n1*x+n2*y=n的实际解应该为(x,y)=(x'*n/gcd，y'*n/gcd)
 * 通解公式为（x+n2/gcd*k, y-n1/gcd*k）
 *
 * 顺便再复习一下通解公式的推导吧
 * 令（x0,y0），（x1,y1）为方程的两组解，则
 * x0*n1+y0*n2 = n = x1*n1+y1*n2，有
 * n1*（x0-x1） = -n2*(y0-y1)
 * 因为gcd（n1,n2）=gcd
 * 所以令n1‘=n1/gcd，n2’=n2/gcd,则
 * n1‘*（x0-x1） = -n2’*(y0-y1)，也成立
 * 此时，gcd（n1‘，n2’）==1，故
 * x0-x1必为n2‘的倍数
 * y0-y1必为n1‘的倍数
 * 于是x0-x1= -k*n2'，y0-y1= k*n1'
 * 即（x1,y1）=（x0+k×n2’，y0-k×n1‘）
 *
 * 因为题目要求解必须非负，所以解还要满足x>=0,y>=0，即
 * x0+k×n2’>=0
 * y0-k×n1‘>=0，
 * 故可以求出k的取值范围[ceil -x0/n2', floor y0/n1']
 * 因为n1*c1+n2*c2是一个线性方程，所以方程的值是单调的
 * 为了方便表示，令k的上下界为[low,up]，则可以求出方程最终的取值范围
 * lowV = (x + low * n2) * c1 + (y - low * n1) * c2
 * upV = (x + up * n2) * c1 + (y - up * n1) * c2
 * lowV<upV时，取下界的k，得到解（x + low * n2, y - low * n1），
 * 否则取上界k得到的解（x + up * n2, y - up * n1）
 *
 * 到这里，这题终于做完了~
 *
 * p.s 对于lowV<upV可以化简
 * (x + low * n2) * c1 + (y - low * n1) * c2 < (x + up * n2) * c1 + (y - up * n1) * c2
 * 得 n1 * c2 < n2 * c1
 *
 * happy coding~
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

void gcd(LL a, LL b, LL &g, LL &x, LL &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		g = a;
	} else {
		gcd(b, a % b, g, y, x);
		y -= a / b * x;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	LL n, c1, n1, c2, n2, x, y, g;
	while (scanf("%lld", &n) != EOF && n) {
		scanf("%lld %lld", &c1, &n1);
		scanf("%lld %lld", &c2, &n2);
		gcd(n1, n2, g, x, y);
		x *= (n / g);
		y *= (n / g);
		n1 /= g;
		n2 /= g;
		LL up = floor((y * 1.0) / n1);
		LL low = ceil((-1.0 * x) / n2);
		if (n % g || low > up)
			puts("failed");
		else {
			if (n1 * c2 < n2 * c1) {
				printf("%lld %lld\n", x + low * n2, y - low * n1);
			} else {
				printf("%lld %lld\n", x + up * n2, y - up * n1);
			}
		}
	}

	return 0;
}

