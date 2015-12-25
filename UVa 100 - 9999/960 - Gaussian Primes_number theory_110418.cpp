/*
 * 960 - Gaussian Primes
 *
 * number theory
 * math...
 *
 * a + bi is Gaussian Primes
 * if a!=0 && b!=0, if and only if a^2+b^2 is prime
 * if a==0 && b!=0, if and only if abs(b) is prime
 * if a!=0 && b==0, if and only if abs(a) is prime
 * else false
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
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;

bool isPrime(int var) {
	for(int i=2; i*i<=var; ++i) {
		if(var%i==0)
			return false;
	}
	return true;
}

bool chk(int a, int b) {
	if(a && b)
		return isPrime(a*a+b*b);
	else if(!a)
		return b%4==3 && isPrime(b);
	else if(!b)
		return a%4==3 && isPrime(a);
	else
		return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, a, b;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%d %d", &a, &b);
    	puts(chk(abs(a), abs(b))? "P": "C");
    }

    return 0;
}

