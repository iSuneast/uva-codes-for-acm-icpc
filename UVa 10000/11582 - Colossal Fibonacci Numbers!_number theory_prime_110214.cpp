/*
 * 11582 - Colossal Fibonacci Numbers!
 *
 * number theory...
 * 竟然没注意到unsigned long long的读入应该是%llu形式，
 * WA了无数次，还是不知道为什么 =_=， 改成cin，cout才过了。。。
 *
 * fib( a^b ) % n
 * 因为是斐波那契数列，所以有循环节
 * 求出MOD n的循环节，不妨设为cyc
 * 则 fib( a^b ) % n = fib( (a^b)%cyc ) % n
 * 于是用两个二分求幂运算就可以算出解了。。。
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 1001
using namespace std;
typedef unsigned long long ULL;

ULL cyc[MAXN], fib[MAXN*100];

void init() {
	cyc[1]=1;
	for(int i=2; i<MAXN; ++i) {
		fib[0]=0;	fib[1]=1;
		for(int j=2; j; ++j) {
			fib[j] = (fib[j-1]+fib[j-2])%i;
			if(fib[j-1]==fib[0] && fib[j]==fib[1]) {
				cyc[i]=j-1;
				break;
			}
		}
	}
}

ULL pow_mod(ULL a, ULL b, ULL m) {
	a %= m;
	ULL key=1, mul=a;
	for(; b; b>>=1) {
		if(b&1)
			key = (key*mul)%m;
		mul = (mul*mul)%m;
	}

	return key;
}

struct MATRIX {
	ULL a[2][2];
	void fib_init() {
		a[0][0]=a[1][0]=a[0][1]=1;
		a[1][1]=0;
	}
	void unit() {
		a[0][0]=a[1][1]=1;
		a[0][1]=a[1][0]=0;
	}

	MATRIX multiply(MATRIX &t, ULL m) {
		MATRIX key;
		for(int i=0;i<2;++i) {
			for(int j=0;j<2;++j) {
				key.a[i][j]=0;
				for(int k=0;k<2;++k) {
					key.a[i][j] = key.a[i][j]+a[i][k]*t.a[k][j];
					key.a[i][j] %= m;
				}
			}
		}

		return key;
	}
};

ULL Nthfib(ULL n, ULL m) {
	MATRIX mul, key;
	key.unit();
	mul.fib_init();

	for(; n; n>>=1) {
		if(n&1)
			key = key.multiply(mul, m);
		mul = mul.multiply(mul, m);
	}

	return key.a[0][1]%m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	init();
	int dataset;
	ULL a, b, n;
	scanf("%d", &dataset);
	while(dataset--) {
		cin>>a>>b>>n;
		cout<<Nthfib( pow_mod(a,b,cyc[n]), n )<<endl;
	}

	return 0;
}
